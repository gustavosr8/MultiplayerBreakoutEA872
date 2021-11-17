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
#include <boost/bind.hpp>
#include <thread>

using boost::asio::ip::udp;

using nlohmann::json;
int players=0;
boost::asio::io_service my_io_service; // Conecta com o SO
udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                   // conf. da conexao (ip/port)
std::vector<udp::endpoint> remote_endpoints;
udp::socket my_socket(my_io_service,   // io service
                          local_endpoint); // endpoint
json jc;
teclado getTeclado(view &v);
std::vector<teclado> keyboard;

void receive(){

    char output_client[3500];
    udp::endpoint remote_endpoint;

    for(int i = 0; i < 3500; i++){
         output_client[i] = 0;
    }
    my_socket.receive_from(boost::asio::buffer(output_client, 3500), remote_endpoint);
    std::stringstream output1;
    output1 << output_client;
    jc = json::parse(output1);
    int user_id = int(jc["user_id"]);
    std::cout << "Player " << user_id << std::endl;
    keyboard[user_id] = jc["Teclado"];
}

int main()
{
    char local[120];
    //udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar
    int start=0;
    do{ 
        std::cout << "Quando todos se conectarem, digite 1, caso contrario digite 0" << std::endl;
        std::cin >> start;
        if(start==1) break;
        std::cout << "Esperando mensagem!" << std::endl;
        remote_endpoints.push_back(udp::endpoint());
        my_socket.receive_from(boost::asio::buffer(local, 120), // Local do buffer
                           remote_endpoints[players]);                // Confs. do Cliente
        std::string user_id = std::to_string(players);
        my_socket.send_to(boost::asio::buffer(user_id, user_id.size()), remote_endpoints[players]);
        std::cout << "Fim de mensagem!" << std::endl;
        players++;
    }while(players<5);

    //Inicializa os objetos da aplicação

    //Tijolos
    std::vector<tijolo> t, t_param;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            tijolo NewTijolo(i, j+3);
            t.push_back(NewTijolo);
        }
    }

    bolinha bol = bolinha(8, 7);
    bolinha bol_param;
    std::vector<barra> bar, bar_param;
    bar.push_back(barra(8,1));
    bar.push_back(barra(8,8));
    /*
    barra bar = barra(8, 8);
    barra bar_param;
    */

    pontos p = pontos(0);
    vida l = vida();

    for(int i = 0; i < players; i++){
        keyboard.push_back(teclado());
    }
    l.setValue(4);
    view v = view(t, bar, &bol, &p, &l);
    v.window_create(1);
    v.init();
    controller c = controller(v, &bol, keyboard);

    bool rodando = true;
    SDL_Event evento;

    container cntr;
    //Objects Size Parameterization
    int width = v.getWidth();
    int heigth = v.getHeigth();
    float temp;
    t_param = t;
    for(int i = 0; i < t.size(); i++){
        t_param[i].setXparam((float)t[i].getX()/(float)width);
        t_param[i].setYparam((float)t[i].getY()/(float)heigth);
    }
    //std::cout << "Barra: " << bar.print() << "   Bolinha: " << bol.print() << std::endl;
    bar_param = bar;
    for(int i = 0; i < bar.size(); i++){
        bar_param[i].setXparam((float)bar_param[i].getX()/(float)width);
        bar_param[i].setYparam((float)bar_param[i].getY()/(float)heigth);
    }
    bol_param = bol;
    bol_param.setXparam((float)bol_param.getX()/(float)width);
    bol_param.setYparam((float)bol_param.getY()/(float)heigth);
    cntr.t = t_param;
    cntr.ba = bar_param;
    cntr.bo = bol_param;
    cntr.v = l;
    cntr.p = p;
     

    json js;
    js["Container"] = cntr;
    std::ofstream f;
    f.open("server.json");
    f << js;
    f.close();
    //key = getTeclado(v);
    std::stringstream output1;
    output1 << js;
    std::string output = output1.str();

    for(int i=0; i<players; i++){
        my_socket.send_to(boost::asio::buffer(output, output.size()), remote_endpoints[i]);
    }
    
    std::thread t1(receive);


    //Ciclo de atualização e renderização
    while (rodando)
    {
        
        
        c.start();
        //Fazer alteração para funcionar só com single player
        if (c.save())
        {
            cntr.v = l;
            cntr.ba = bar;
            cntr.bo = bol;
            cntr.p = p;
            cntr.t = t;
            js["Container"] = cntr;
            std::ofstream f;
            f.open("server.json");
            f << js;
            f.close();
        }
        if (c.load())
        {
            std::ifstream f;
            f.open("server.json");
            f >> js;
            f.close();
            cntr = js["Container"];
            l = cntr.v;
            bar = cntr.ba;
            //Ele instancia a bolinha no último local em que a barra foi salva
            bol.setX(cntr.ba[0].getX() + cntr.ba[0].getW() / 2);
            bol.setY(cntr.ba[0].getY() - cntr.bo.getH());
            p = cntr.p;
            t = cntr.t;
        }
        if (l.getValue() > 0 && t.size() > 0)
        {
            c.update();
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

        if (c.finish())
        {
            rodando = false;
        }
        //Objects Size Parameterization
        t_param = t;
        for(int i = 0; i < t.size(); i++){
            t_param[i].setXparam((float)t[i].getX()/(float)width);
            t_param[i].setYparam((float)t[i].getY()/(float)heigth);
        }
        bar_param = bar;
        for(int i = 0; i < bar.size(); i++){
            bar_param[i].setXparam((float)bar_param[i].getX()/(float)width);
            bar_param[i].setYparam((float)bar_param[i].getY()/(float)heigth);
        }
        bol_param = bol;
        bol_param.setXparam((float)bol_param.getX()/(float)width);
        bol_param.setYparam((float)bol_param.getY()/(float)heigth);

        cntr.t = t_param;
        cntr.ba = bar_param;
        cntr.bo = bol_param;
        cntr.v = l;
        cntr.p = p;
        js["Container"] = cntr;
        std::stringstream output4;
        output4 << js;
        std::string output_send;
        output_send = output4.str();
        
        for(int i=0; i<players; i++){
            my_socket.send_to(boost::asio::buffer(output, output.size()), remote_endpoints[i]);
        }        
    }
    t1.join();
    v.quit();
    
    return 0;
}

teclado getTeclado(view &v)
{
    const Uint8 *state = v.getState();
    teclado keyb = teclado();
    if (state[SDL_SCANCODE_G])
    {
        keyb.setLeft(true);
    }
    if (state[SDL_SCANCODE_J])
    {
        keyb.setRight(true);
    }
    if (state[SDL_SCANCODE_Y])
    {
        keyb.setUp(true);
    }
    if (state[SDL_SCANCODE_H])
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