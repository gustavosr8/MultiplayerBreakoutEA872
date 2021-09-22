#include "view.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

view::view(model &m_, tijolo* t_):m(m_),t(t_){}

SDL_Rect* view::getTarget(){return &target;}
const Uint8* view::getState(){return state;}

int view::init(){
 
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
        return 1;
    }
    window = nullptr;
    window = SDL_CreateWindow("Demonstracao do SDL2",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN);
    if (window==nullptr) { // Em caso de erro...
        std::cout << SDL_GetError();
        SDL_Quit();
        return 1;
    }
    renderer = nullptr; 
    renderer = SDL_CreateRenderer(
    window, -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer==nullptr) { // Em caso de erro...
        SDL_DestroyWindow(window);
        std::cout << SDL_GetError();
        SDL_Quit();
        return 1;
    }
    capivara = IMG_LoadTexture(renderer, "../assets/capi.png" );
    taquaral = IMG_LoadTexture(renderer, "../assets/park.jpeg" );
    target.x = m.getX();
    target.y = m.getY();
    SDL_QueryTexture(capivara, nullptr, nullptr, &target.w, &target.h);
    state = SDL_GetKeyboardState(nullptr);
}
void view::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, taquaral, nullptr, nullptr);
    SDL_RenderCopy(renderer, capivara, nullptr, &target);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
}
void view::quit(){
    SDL_DestroyTexture(capivara);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}