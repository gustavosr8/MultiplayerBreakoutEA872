#include "view.h"
#include <iostream>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

view::view(model &m_, tijolo* t_, barra* ba_, bolinha* bo_):m(m_),t(t_),ba(ba_),bo(bo_){}

SDL_Rect* view::getTarget(){return &target;}
SDL_Rect* view::getBloco(){return &bloco;}
SDL_Rect* view::getBolinha(){return &bol;}
SDL_Rect* view::getBarra(){return &bar;}
tijolo* view::getTijolos(){return t;}

int view::getWidth(){return SCREEN_WIDTH;};
int view::getHeigth(){return SCREEN_HEIGHT;};


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
    
  
    //Inicializando a Bolinha
    bol.h = bo->getH();
    bol.w = bo->getW();
    bol.x = bo->getX();
    bol.y = bo->getY();
   
    //Inicializando a Barra
    bar.h = ba->getH();
    bar.w = ba->getW();
    bar.x = ba->getX();
    bar.y = ba->getY();



    state = SDL_GetKeyboardState(nullptr);
}
void view::render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    //Imprimindo os tijolos
    for(int i  = 0; i < 100; i++){
        if(t[i].getEstado()){
            bloco.h = t[i].getH();
            bloco.w = t[i].getW();
            bloco.x = t[i].getX();
            bloco.y = t[i].getY();
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &bloco);
            SDL_RenderFillRect( renderer, &bloco );
        }
    } 
    
    //Imprimindo as barras
    SDL_SetRenderDrawColor(renderer, 64, 244, 208, 255);
    SDL_RenderDrawRect(renderer, &bar);
    SDL_RenderFillRect( renderer, &bar );
    
    //Imprimindo as bolinhas
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &bol);
    SDL_RenderFillRect( renderer, &bol );

    SDL_RenderPresent(renderer);
    SDL_Delay(10);
}
void view::quit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}