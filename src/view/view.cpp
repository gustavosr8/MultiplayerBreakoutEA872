#include "view.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <charconv>



using std::cout; using std::cin;
using std::endl; using std::string;


int SCREEN_WIDTH = 720;
int SCREEN_HEIGHT = 480;

SDL_Color White = {255, 255, 255};
SDL_Color Red = {255, 0, 0};
SDL_Color Green = {0, 255, 0};
char num_char[10 + sizeof(char)];
char tmp[256];



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
    TTF_Init();
    SDL_GetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
    getcwd(tmp, 256);

    std::string font; 
    cout << tmp << endl;
    font += tmp;
    //Retira o 'bin' do caminho
    font = font.substr(0, font.size()-3);
    //Adiciona a localidade e a o nome da fonte
    font.append("src/Sans.ttf");
    std::copy(font.begin(), font.end(), tmp);

    //this opens a font style and sets a size
    Sans = TTF_OpenFont(tmp, 30);

    if(!Sans) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }   

    Message_Vida_rect.x = 0;  //controls the rect's x coordinate 
    Message_Vida_rect.y = 0; // controls the rect's y coordinte
    Message_Vida_rect.w = 80; // controls the width of the rect
    Message_Vida_rect.h = 50;// controls the height of the rect
    render_text(renderer, Message_Vida_rect.x, Message_Vida_rect.y, "Vida: ",Sans, &Message_Vida_rect, &White);
    

    Message_Pontos_rect.x = 200;  //controls the rect's x coordinate 
    Message_Pontos_rect.y = 0; // controls the rect's y coordinte
    Message_Pontos_rect.w = 80; // controls the width of the rect
    Message_Pontos_rect.h = 50;// controls the height of the rect
    render_text(renderer, Message_Pontos_rect.x, Message_Pontos_rect.y, "Pontos: ",Sans, &Message_Pontos_rect, &White);

    std::sprintf(num_char, "%d", v->getValue());
    Message_VidaValue_rect.x = 80;  //controls the rect's x coordinate 
    Message_VidaValue_rect.y = 0; // controls the rect's y coordinte
    Message_VidaValue_rect.w = 50; // controls the width of the rect
    Message_VidaValue_rect.h = 50;// controls the height of the rect
    render_text(renderer, Message_VidaValue_rect.x, Message_VidaValue_rect.y, num_char,Sans, &Message_VidaValue_rect, &White);
    
    std::sprintf(num_char, "%d", po->getValue());
    Message_PointValue_rect.x = 320;  //controls the rect's x coordinate 
    Message_PointValue_rect.y = 0; // controls the rect's y coordinte
    Message_PointValue_rect.w = 50; // controls the width of the rect
    Message_PointValue_rect.h = 50;// controls the height of the rect
    render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Sans, &Message_PointValue_rect, &White);
    
    
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

    render_text(renderer, Message_Vida_rect.x, Message_Vida_rect.y, "Vida: ",Sans, &Message_Vida_rect, &White);
    render_text(renderer, Message_Pontos_rect.x, Message_Pontos_rect.y, "Pontos: ",Sans, &Message_Pontos_rect, &White);
    std::sprintf(num_char, "%d", v->getValue());
    render_text(renderer, Message_VidaValue_rect.x, Message_VidaValue_rect.y, num_char,Sans, &Message_VidaValue_rect, &White);
    std::sprintf(num_char, "%d", po->getValue());
    render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Sans, &Message_PointValue_rect, &White);
    
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

void view::perdeu(){
    render();
    render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Sans, &Message_PointValue_rect, &White);
    Message_Fim_rect.x = SCREEN_WIDTH/2-20;  //controls the rect's x coordinate 
    Message_Fim_rect.y = SCREEN_HEIGHT/2; // controls the rect's y coordinte
    Message_Fim_rect.w = 150; // controls the width of the rect
    Message_Fim_rect.h = 150;// controls the height of the rect
    TTF_Font* Sans2 = TTF_OpenFont(tmp, 70);
    render_text(renderer, Message_Fim_rect.x, Message_Fim_rect.y, "PERDEU!!!!",Sans2, &Message_Fim_rect, &Red);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}


void view::ganhou(){
    render();
    render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Sans, &Message_PointValue_rect, &White);
    Message_Fim_rect.x = SCREEN_WIDTH/2-20;  //controls the rect's x coordinate 
    Message_Fim_rect.y = SCREEN_HEIGHT/2; // controls the rect's y coordinte
    Message_Fim_rect.w = 150; // controls the width of the rect
    Message_Fim_rect.h = 150;// controls the height of the rect
    TTF_Font* Sans2 = TTF_OpenFont(tmp, 70);
    render_text(renderer, Message_Fim_rect.x, Message_Fim_rect.y, "GANHOUU!!!!",Sans2, &Message_Fim_rect, &Green);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}

void view::quit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit;
    SDL_Quit();
}

//Function to render a text;
void view::render_text(
    SDL_Renderer *renderer,
    int x,
    int y,
    const char *text,
    TTF_Font *font,
    SDL_Rect *rect,
    SDL_Color *color
) {
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, *color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect->x = x;
    rect->y = y;
    rect->w = surface->w;
    rect->h = surface->h;
    /* This is wasteful for textures that stay the same.
     * But makes things less stateful and easier to use.
     * Not going to code an atlas solution here... are we? */
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, rect);
    SDL_DestroyTexture(texture);
}

int view::quantidadeTijolos(){
    int k = 0;
    for(int i  = 0; i < 100; i++){
        if(t[i].getEstado()){
            k++;
        }
    } 
    return k;
}