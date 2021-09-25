#pragma once
#include "barra.h"
#include "view.h"
#include "bolinha.h"
#include <SDL2/SDL.h>

class controller{
    
    private:
        view &v;
        barra* ba;
        bolinha* bo;
        int dirX = 5;
        int dirY = 5;
    
    public:
        controller(view &v_, barra* ba_, bolinha* bo_): ba(ba_), v(v_), bo(bo_){}
        void update();
        bool colisaoBarra();
        bool colisaoBloco();
};