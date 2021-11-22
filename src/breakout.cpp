#include "../include/view.h"
#include "../include/controller.h"
#include "../include/tijolo.h"
#include "../include/bolinha.h"
#include "../include/barra.h"
#include "../include/pontos.h"
#include "../include/vida.h"
#include "../include/container.h"
#include "../include/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/asio.hpp>

using nlohmann::json;
using boost::asio::ip::udp;


teclado getTeclado(view &v);

int main()
{

    std::string v1("Conexao iniciada...");
    boost::asio::io_service io_service;
    udp::endpoint local_endpoint(udp::v4(), 0);
    udp::socket meu_socket(io_service, local_endpoint);
    boost::asio::ip::address ip_remoto =
        boost::asio::ip::address::from_string("25.63.189.194");

    udp::endpoint remote_endpoint(ip_remoto, 9001);
    
    json js, jc;
    char output[5000];

    for(int i = 0; i < 5000; i++){
        output[i] = 0;
    }

    
    meu_socket.send_to(boost::asio::buffer(v1), remote_endpoint);

    std::cout << v1 << std::endl;
    std::cout << "Server conectado" << std::endl;
    meu_socket.receive_from(boost::asio::buffer(output, 5000), remote_endpoint);
    std::string s = output;
    int user_id =  stoi(s);
    meu_socket.receive_from(boost::asio::buffer(output, 5000), remote_endpoint);
    
    std::stringstream output1;
    output1 << output;

    
    js = json::parse(output1);
    container cntr;
    std::vector<std::vector<tijolo> > t, t_param;
    bolinha bol, bol_param;
    std::vector<barra> bar, bar_param;
    pontos p;
    vida l;
    teclado key;
    
    cntr = js["Container"];
    l = cntr.v;
    bar_param = cntr.ba;
    bol_param = cntr.bo;
    p = cntr.p;
    t_param = cntr.t;
    key = cntr.keyb;
    

    view v = view(t, bar, &bol, &p, &l);
    v.window_create(1);
    //Objects Size Parameterization
    int width = v.getWidth();
    int heigth = v.getHeigth();
    for(int i = 0; i < t_param.size(); i++){
        for(int j=0; j<t_param[i].size(); j++){
            t_param[i][j].setX(t_param[i][j].getXparam()*width);
            t_param[i][j].setY(t_param[i][j].getYparam()*heigth);
        }
    }
    for(int i = 0; i < bar_param.size(); i++){
        bar_param[i].setX(bar_param[i].getXparam()*width);
        bar_param[i].setY(bar_param[i].getYparam()*heigth);
    }
    bol_param.setX(bol_param.getXparam()*width);
    bol_param.setY(bol_param.getYparam()*heigth);
    t = t_param;
    bol = bol_param;
    bar = bar_param;
    v.initClient();
    
    bool rodando = true;
    SDL_Event evento;


    //Ciclo de atualização e renderização
    
    while (rodando)
    {   
        if (l.getValue() > 0 && t[user_id].size() > 0)
        {
            v.render(user_id);
            int counter = 0;
            for(int i = 0; i < t.size(); i++){
                if (t[i].size() > 0) counter++;
            }
            if(t.size() > 1 && counter == 1 && t[user_id].size() > 0) v.ganhou(user_id);
        }
        else if (t[user_id].size() < 1 && t.size() == 1)
        {   
            if(l.getValue() > 0)
                v.ganhou(user_id);
        }
        else
        {
            v.perdeu(user_id);
        }
        while (SDL_PollEvent(&evento))
        {
            if (evento.type == SDL_QUIT)
            {
                rodando = false;
            }
        }
        key = getTeclado(v);
        std::string output2;
        jc["user_id"] = user_id;
        jc["Teclado"] = key;
        std::stringstream output3;
        output3 << jc;
        output2 = output3.str();
        meu_socket.send_to(boost::asio::buffer(output2, 5000), remote_endpoint);
        for(int i = 0; i < 5000; i++){
            output[i] = 0;
        }
        
        meu_socket.receive_from(boost::asio::buffer(output, 5000), remote_endpoint);
        std::stringstream output4;
        output4 << output;
        js = json::parse(output4);
        cntr = js["Container"];
        int l_temp = l.getValue();
        l = cntr.v;
        p = cntr.p;
        int w, h;
        w = bar[0].getW();
        h = bar[0].getH();
        bar = cntr.ba;
        for(int i = 0; i < bar.size(); i++){
            bar[i].setX(bar[i].getXparam()*width);
            bar[i].setY(bar[i].getYparam()*heigth);
            bar[i].setW(w);
            bar[i].setH(h);
        }
         
        //Ele instancia a bolinha no último local em que a barra foi salva
        if(l_temp < l.getValue() || key.Space()){
            bol.setX((bar[0].getXparam()*width) + bar[0].getW() / 2);
            bol.setY((bar[0].getYparam()*heigth) - bol.getH());
        }else{
            bol.setX(cntr.bo.getXparam()*width);
            bol.setY(cntr.bo.getYparam()*heigth);
        }
            
        w = t[0][0].getW();
        h = t[0][0].getH();
        t = cntr.t;
        for(int i = 0; i < t.size(); i++){
            for(int j=0; j<t[i].size(); j++){
                t[i][j].setX(t[i][j].getXparam()*width);
                t[i][j].setY(t[i][j].getYparam()*heigth);
                t[i][j].setW(w);
                t[i][j].setH(h);
            }
        }
        if (l.getValue() > 0 && t[user_id].size() > 0)
        {
            v.render(user_id);
        }
        if (key.Exit())
        {   
            rodando = false;
        }
    }
    v.quit();
    
    return 0;
}

teclado getTeclado(view &v)
{
    const Uint8 *state = v.getState();
    teclado keyb = teclado();
    if (state[SDL_SCANCODE_LEFT])
    {
        keyb.setLeft(true);
    }
    if (state[SDL_SCANCODE_RIGHT])
    {
        keyb.setRight(true);
    }
    if (state[SDL_SCANCODE_UP])
    {
        keyb.setUp(true);
    }
    if (state[SDL_SCANCODE_DOWN])
    {
        keyb.setDown(true);
    }
    if (state[SDL_SCANCODE_ESCAPE])
    {
        keyb.setExit(true);
    }
    if (state[SDL_SCANCODE_L])
    {
        keyb.setLoad(true);
    }

    if (state[SDL_SCANCODE_W])
    {
        keyb.setSave(true);
    }

    if (state[SDL_SCANCODE_S])
    {
        keyb.setStart(true);
    }

    if (state[SDL_SCANCODE_SPACE])
    {
        keyb.setSpace(true);
    }

    return keyb;
}