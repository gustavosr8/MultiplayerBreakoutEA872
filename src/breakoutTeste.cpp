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

    std::cout << "Recebeu retorno: " << output << std::endl;


    
    std::stringstream output1;
    output1 << output;

    js = json::parse(output1);

    return 0;
}