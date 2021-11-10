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

    std::string v1("{\"Teste\": 15}");
    boost::asio::io_service io_service;
    udp::endpoint local_endpoint(udp::v4(), 0);
    udp::socket meu_socket(io_service, local_endpoint);
    boost::asio::ip::address ip_remoto =
        boost::asio::ip::address::from_string("25.51.223.228");

    udp::endpoint remote_endpoint(ip_remoto, 9001);
    
    json js, jc;
    char output[3500];

    for(int i = 0; i < 3500; i++){
        output[i] = 0;
    }

    
    meu_socket.send_to(boost::asio::buffer(v1), remote_endpoint);

    std::cout << v1 << std::endl;
    std::cout << "Fim" << std::endl;
    meu_socket.receive_from(boost::asio::buffer(output, 3500), remote_endpoint);
    
    std::stringstream output1;
    output1 << output;

    

    js = json::parse(output1);
   
    container cntr;
    std::vector<tijolo> t, t_param;
    bolinha bol, bol_param;
    barra bar, bar_param;
    pontos p;
    vida l;
    teclado key;
    
    cntr = js["Container"];
    //std::cout << js << std::endl;
    l = cntr.v;
    bar_param = cntr.ba;
    bol_param = cntr.bo;
    p = cntr.p;
    t_param = cntr.t;
    key = cntr.keyb;
    

    view v = view(t, &bar, &bol, &p, &l);
    v.window_create(1);
    //Objects Size Parameterization
    int width = v.getWidth();
    int heigth = v.getHeigth();
    for(int i = 0; i < t_param.size(); i++){
        t_param[i].setX(t_param[i].getXparam()*width);
        t_param[i].setY(t_param[i].getYparam()*heigth);
    }
    bar_param.setX(bar_param.getXparam()*width);
    bar_param.setY(bar_param.getYparam()*heigth);
    bol_param.setX(bol_param.getXparam()*width);
    bol_param.setY(bol_param.getYparam()*heigth);
    t = t_param;
    bol = bol_param;
    bar = bar_param;
    //std::cout << "Barra: " << bar.print() << "   Bolinha: " << bol.print() << std::endl;
    v.initClient();
    std::cout << "Tijolos  H: " << t[0].getH() << "   W: " << t[0].getW() << std::endl;
    bool rodando = true;
    SDL_Event evento;

    //Ciclo de atualização e renderização
    
    while (rodando)
    {   
        //std::cout << "Barra: " << bar.print() << "   Bolinha: " << bol.print() << std::endl;
        if (l.getValue() > 0 && t.size() > 0)
        {
            v.render();
        }
        else if (t.size() < 1)
        {
            v.ganhou();
        }
        else
        {
            v.perdeu();
        }
        while (SDL_PollEvent(&evento))
        {
            if (evento.type == SDL_QUIT)
            {
                rodando = false;
            }
        }

        key = getTeclado(v);
        if (key.Exit())
        {
            rodando = false;
        }
        std::string output2;
        jc["Teclado"] = key;
        std::stringstream output3;
        output3 << jc;
        output2 = output3.str();
        meu_socket.send_to(boost::asio::buffer(output2, 3500), remote_endpoint);

        for(int i = 0; i < 3500; i++){
            output[i] = 0;
        }

        meu_socket.receive_from(boost::asio::buffer(output, 3500), remote_endpoint);
        std::stringstream output4;
        output4 << output;
        js = json::parse(output4);
        cntr = js["Container"];
        //std::cout << js << std::endl;
        if (l.getValue() > 0 && t.size() > 0)
        {
            v.render();
        }
        
        int l_temp = l.getValue();
        l = cntr.v;
        p = cntr.p;
        bar.setX(cntr.ba.getXparam()*width);
        bar.setY(cntr.ba.getYparam()*heigth);

        //Ele instancia a bolinha no último local em que a barra foi salva
        if(l_temp < l.getValue() || key.Space()){
            bol.setX((bar.getXparam()*width) + bar.getW() / 2);
            bol.setY((bar.getYparam()*heigth) - bol.getH());
        }else{
            bol.setX(cntr.bo.getXparam()*width);
            bol.setY(cntr.bo.getYparam()*heigth);
        }    
        int w, h;
        w = t[0].getW();
        h = t[0].getH();
        t = cntr.t;
        for(int i = 0; i < t.size(); i++){
            t[i].setX(t[i].getXparam()*width);
            t[i].setY(t[i].getYparam()*heigth);
            t[i].setH(w);
            t[i].setH(h);
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