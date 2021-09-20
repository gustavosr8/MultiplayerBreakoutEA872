#pragma once
#include "model.hpp"
#include "view.hpp"
#include <SDL2/SDL.h>


class controller{
    
    private:
        view &v;
        model &m;
    
    public:
        controller(view &v_, model &m_): m(m_), v(v_){}

        void update();
};