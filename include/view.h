#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "model.h"
#include "tijolo.h"
#include "bolinha.h"
#include "barra.h"


class view{
    private:
        
        model &m;
        tijolo *t;
        bolinha *bo;
        barra *ba;



        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Rect bloco;
        SDL_Rect target;
        SDL_Rect bol;
        SDL_Rect bar;
        const Uint8 *state;
    
    public:

        view(model &m_, tijolo* t_, barra* ba_, bolinha* bo_);
        SDL_Rect* getTarget();
        SDL_Rect* getBloco();
        SDL_Rect* getBolinha();
        SDL_Rect* getBarra();
        tijolo* getTijolos();
        int getWidth();
        int getHeigth();
        const Uint8* getState();
        int init();
        void render();
        void quit();
};