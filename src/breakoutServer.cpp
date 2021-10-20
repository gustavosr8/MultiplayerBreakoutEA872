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

using boost::asio::ip::udp;

using nlohmann::json;

teclado getTeclado(view &v);

int main()
{
    char local[120];
    boost::asio::io_service my_io_service; // Conecta com o SO

    udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                   // conf. da conexao (ip/port)

    udp::socket my_socket(my_io_service,   // io service
                          local_endpoint); // endpoint

    udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

    my_socket.receive_from(boost::asio::buffer(local, 120), // Local do buffer
                           remote_endpoint);                // Confs. do Cliente

    //Inicializa os objetos da aplicação

    //Tijolos
    std::vector<tijolo> t;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            tijolo NewTijolo(i, j);
            t.push_back(NewTijolo);
        }
    }

    bolinha bol = bolinha(8, 7);
    barra bar = barra(8, 8);
    pontos p = pontos(0);
    vida l = vida();
    teclado key = teclado();
    l.setValue(4);
    view v = view(t, &bar, &bol, &p, &l);
    v.init();
    controller c = controller(v, &bar, &bol, &key);

    bool rodando = true;
    SDL_Event evento;

    container cntr;
    cntr.v = l;
    cntr.ba = bar;
    cntr.bo = bol;
    cntr.p = p;
    cntr.t = t;

    json j;
    j["Container"] = cntr;
    std::ofstream f;
    f.open("server.json");
    f << j;
    f.close();

    my_socket.send_to(j, remote_endpoint);

    //Ciclo de atualização e renderização
    while (rodando)
    {

        my_socket.receive_from(j, remote_endpoint);
        std::ifstream f;
        f.open("client.json");
        f >> j;
        f.close();

        c.start();
        if (c.save())
        {
            cntr.v = l;
            cntr.ba = bar;
            cntr.bo = bol;
            cntr.p = p;
            cntr.t = t;
            j["Container"] = cntr;
            std::ofstream f;
            f.open("server.json");
            f << j;
            f.close();
        }
        if (c.load())
        {
            std::ifstream f;
            f.open("server.json");
            f >> j;
            f.close();
            cntr = j["Container"];
            l = cntr.v;
            bar = cntr.ba;
            //Ele instancia a bolinha no último local em que a barra foi salva
            bol.setX(cntr.ba.getX() + cntr.ba.getW() / 2);
            bol.setY(cntr.ba.getY() - cntr.bo.getH());
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

        cntr.v = l;
        cntr.ba = bar;
        cntr.bo = bol;
        cntr.p = p;
        cntr.t = t;

        json j;
        j["Container"] = cntr;
        std::ofstream f3;
        f3.open("server.json");
        f3 << j;
        f3.close();

        my_socket.send_to(j, remote_endpoint);
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