#include "view.h"
#include <iostream>
#include <string>

int SCREEN_WIDTH = 720;
int SCREEN_HEIGHT = 480;



view::view(tijolo* t_, barra* ba_, bolinha* bo_, pontos* po_, vida* v_): t(t_),ba(ba_),bo(bo_), po(po_), v(v_){}

SDL_Rect* view::getTarget(){return &target;}
SDL_Rect* view::getBloco(){return &bloco;}
SDL_Rect* view::getBolinha(){return &bol;}
SDL_Rect* view::getBarra(){return &bar;}
tijolo* view::getTijolos(){return t;}
pontos* view::getPonto(){return po;};
vida* view::getVida(){return v;};


int view::getWidth(){return SCREEN_WIDTH;};
int view::getHeigth(){return SCREEN_HEIGHT;};


const Uint8* view::getState(){return state;}

int view::init(){
    
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
        return 1;
    }
    window = nullptr;
    window = SDL_CreateWindow("Breakout",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_FULLSCREEN_DESKTOP);
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
    SDL_GetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

    //this opens a font style and sets a size
    TTF_Font* Sans = TTF_OpenFont("PressStart2P-vaV7.ttf", 24);

    // this is the color in rgb format,
    // maxing out all would give you the color white,
    // and it will be your text's color
    SDL_Color White = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    surfaceMessage =
        TTF_RenderText_Solid(Sans, "put your text here", White); 

    // now you can convert it into a texture
    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

 //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate 
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect

    // (0,0) is on the top left of the window/screen,
    // think a rect as the text's box,
    // that way it would be very simple to understand

    // Now since it's a texture, you have to put RenderCopy
    // in your game loop area, the area where the whole code executes

    // you put the renderer's name first, the Message,
    // the crop size (you can ignore this if you don't want
    // to dabble with cropping), and the rect which is the size
    // and coordinate of your texture
    

    
    //Inicializando os tamanhos dos elementos
    bo->setX(bo->getX()*SCREEN_WIDTH/16);
    bo->setY(bo->getY()*((SCREEN_HEIGHT/9)-100));
    bo->setH(bo->getHmult()*SCREEN_HEIGHT/9);
    bo->setW(bo->getWmult()*SCREEN_WIDTH/16);

    ba->setX(ba->getX()*SCREEN_WIDTH/16);
    ba->setY(ba->getY()*SCREEN_HEIGHT/9);
    ba->setH(ba->getHmult()*SCREEN_HEIGHT/9);
    ba->setW(ba->getWmult()*SCREEN_WIDTH/16);


    for(int i  = 0; i < 100; i++){
        t[i].setH(t[i].getHmult()*SCREEN_HEIGHT/9);
        t[i].setW(t[i].getWmult()*SCREEN_WIDTH/16);
        t[i].setX(t[i].getX()*((SCREEN_WIDTH/16)+(t[i].getW()/1.5)));
        t[i].setY(t[i].getY()*((SCREEN_HEIGHT/9)-(t[i].getH()*0.8)));  
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

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

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
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}