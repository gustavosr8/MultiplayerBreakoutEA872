#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "model.hpp"

class view{
    private:
        
        model &m;

        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *capivara;
        SDL_Texture *taquaral;
        SDL_Rect target;
        const Uint8 *state;
    
    public:

        view(model &m_);
        SDL_Rect* getTarget();
        const Uint8* getState();
        int init();
        void render();
        void quit();
};