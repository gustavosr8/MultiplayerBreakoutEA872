#pragma once
#include "tijolo.h"
#include "bolinha.h"
#include "barra.h"
#include "pontos.h"
#include "vida.h"
#include "teclado.h"
#include "json.hpp"

/*! \brief Classe para o container
 *
 *  Esta é a classe para o container. 
 *  Ela possui variaveis internas para os objetos que serão mandados nas comunicações entre
 *  os clientes e o server utilizando um JSON. 
*/

class container {
    public:
        vida v;
        std::vector<barra> ba;
        bolinha bo;
        pontos p;
        std::vector <std::vector<tijolo> > t;
        teclado keyb;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(container, v, ba, bo, p, t, keyb);
};