#pragma once
#include "model.h"
#include "view.h"
#include <SDL2/SDL.h>


class controller{
    
    private:
        view &v;
        model &m;
    
    public:
        controller(view &v_, model &m_): m(m_), v(v_){}

        void update();
};