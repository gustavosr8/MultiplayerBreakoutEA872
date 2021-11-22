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
    while(1){
        char output_client[5000];
        udp::endpoint remote_endpoint;

        for(int i = 0; i < 5000; i++){
            output_client[i] = 0;
        }
        my_socket.receive_from(boost::asio::buffer(output_client, 5000), remote_endpoint);
        std::stringstream output1;
        output1 << output_client;
        jc = json::parse(output1);
        //std::string s = jc["user_id"];
        int user_id =  jc["user_id"];
        keyboard[user_id] = jc["Teclado"];
    }    
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
    }while(players<6);

    //Inicializa os objetos da aplicação

    //Bolinha
    bolinha bol = bolinha(8, 7);
    bolinha bol_param;

    //Tijolos e barras
    std::vector<barra> bar, bar_param;
    std::vector<std::vector<tijolo> > t, t_param;
    std::vector<tijolo> t_aux;



    switch(players){
        case 1:
            std::cout << "1 jogador conectado. Iniciando jogo." << std::endl; 
            bar.push_back(barra(8,8));

            for (int i=0; i<10; i++){
                for(int j=0;j<4;j++){
                    tijolo NewTijolo(i+1,j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            break;

        
        case 2:
            std::cout << "2 jogadores conectado. Iniciando jogo." << std::endl;
            bar.push_back(barra(8,4));
            bar.push_back(barra(8,6));
            
            for(int i=0; i<8;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+2, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<8;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+2, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            break;

        case 3:
            bar.push_back(barra(4,6));
            bar.push_back(barra(4,4));
            bar.push_back(barra(12,6));
            

            for(int i=0; i<5;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<5;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<5;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+7, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            break;

        case 4:
            bar.push_back(barra(4,6));
            bar.push_back(barra(4,4));
            bar.push_back(barra(12,6));
            bar.push_back(barra(12,4));
            
            for(int i=0; i<5;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<5;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<5;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+7, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<5;i++){
                for(int j=0; j<2; j++){
                     tijolo NewTijolo(i+7, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            break;

        case 5:
            bar.push_back(barra(2,6));
            bar.push_back(barra(2,4));
            bar.push_back(barra(7,6));
            bar.push_back(barra(7,4));
            bar.push_back(barra(13,6));

            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+5, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                     tijolo NewTijolo(i+5, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+9, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            break;

        case 6:
            bar.push_back(barra(2,6));
            bar.push_back(barra(2,4));
            bar.push_back(barra(7,6));
            bar.push_back(barra(7,4));
            bar.push_back(barra(13,4));
            bar.push_back(barra(13,6));
            

            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+1, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+5, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                     tijolo NewTijolo(i+5, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+9, j+1);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            t_aux.clear();
            for(int i=0; i<3;i++){
                for(int j=0; j<2; j++){
                    tijolo NewTijolo(i+9, j+7);
                    t_aux.push_back(NewTijolo);
                }
            }
            t.push_back(t_aux);
            break;
    }

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
        for(int j=0; j<t[i].size(); j++){
            t_param[i][j].setXparam((float)t[i][j].getX()/(float)width);
            t_param[i][j].setYparam((float)t[i][j].getY()/(float)heigth);
            
        }
        if(t[i].size() == 0)
            bar[i].setVisibility(false);
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

    for(int i=0; i < players; i++){
        my_socket.send_to(boost::asio::buffer(output, output.size()), remote_endpoints[i]);
    }
    
    std::thread t1(receive);


    //Ciclo de atualização e renderização
    while (rodando)
    {
        for(int i=0; i < players; i++){ 
            c.start(i);
        }
        if(players == 1){
            if (c.save(0))
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
            if (c.load(0))
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
            if (l.getValue() > 0 && t[0].size() > 0)
            {
                c.update();
                v.render(-1);
            }
            
            else if (t[0].size() < 1)
            {
                v.ganhou(-1);
            }
            else
            {
                v.perdeu(-1);
            }
        } else {
            int counter = 0;
            int user;
            for(int i = 0; i < t.size(); i++){
                if(t[i].size() > 0){
                    counter++;
                    user = i;
                }    
            }
            if(counter == 1){
                v.ganhouMulti(user);
            }else{
                c.update();
                v.render(-1);
            }
        }
        while (SDL_PollEvent(&evento))
        {
            if (evento.type == SDL_QUIT)
            {
                rodando = false;
            }
        }
        //Objects Size Parameterization
        t_param = t;
        for(int i = 0; i < t.size(); i++){
            for(int j=0; j<t[i].size();j++){
                t_param[i][j].setXparam((float)t[i][j].getX()/(float)width);
                t_param[i][j].setYparam((float)t[i][j].getY()/(float)heigth);
            }
            if(t[i].size() < 1){bar[i].setVisibility(false);}
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
            my_socket.send_to(boost::asio::buffer(output_send, output_send.size()), remote_endpoints[i]);
        }     
        teclado keyS = getTeclado(v);
        if (keyS.Exit())
        {
            rodando = false;
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
