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
    boost::asio::io_service io_service;
    udp::endpoint local_endpoint(udp::v4(), 0);
    udp::socket meu_socket(io_service, local_endpoint);
    boost::asio::ip::address ip_remoto =
        boost::asio::ip::address::from_string("25.53.141.69");

    udp::endpoint remote_endpoint(ip_remoto, 9001);
    
    json j;

    meu_socket.receive_from(j, remote_endpoint);

    
    container cntr;
    std::vector<tijolo> t;
    bolinha bol;
    barra bar;
    pontos p;
    vida l;
    teclado key;

    std::ifstream f;
    f.open("server.json");
    f >> j;
    f.close();
    cntr = j["Container"];
    l = cntr.v;
    bar = cntr.ba;
    bol = cntr.bo;
    p = cntr.p;
    t = cntr.t;
    key = cntr.keyb;

    view v = view(t, &bar, &bol, &p, &l);
    v.init();
    controller c = controller(v, &bar, &bol, &key);

    bool rodando = true;
    SDL_Event evento;

    //Ciclo de atualização e renderização
    while (rodando)
    {
        std::ifstream f;
        f.open("server.json");
        f >> j;
        f.close();
        cntr = j["Container"];
        l = cntr.v;
        p = cntr.p;
        bar.setX(cntr.ba.getX());
        bar.setY(cntr.ba.getY());

        //Ele instancia a bolinha no último local em que a barra foi salva
        bol.setX(bar.getX() + bar.getW() / 2);
        bol.setY(bar.getY() - bol.getH());
        int w, h;
        w = t[0].getW();
        h = t[0].getH();
        t = cntr.t;
        for(int i = 0; i < t.size(); i++){
            t[i].setH(w);
            t[i].setH(h);
        }


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

        json j;
        j["Teclado"] = key;
        std::ofstream f2;
        f.open("client.json");
        f2 << j;
        f2.close();

        meu_socket.send_to(j, remote_endpoint);

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