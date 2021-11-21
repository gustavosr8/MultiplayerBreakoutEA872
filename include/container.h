#pragma once
#include "tijolo.h"
#include "bolinha.h"
#include "barra.h"
#include "pontos.h"
#include "vida.h"
#include "teclado.h"
#include "json.hpp"

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