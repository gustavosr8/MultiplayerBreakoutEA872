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
        int dir = 10;
    
    public:
        controller(view &v_, barra* ba_, bolinha* bo_): ba(ba_), v(v_), bo(bo_){}
        void update();
        bool encontro();
};