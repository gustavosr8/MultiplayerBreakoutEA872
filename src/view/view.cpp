#include "../../include/view.h"
#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <unistd.h>


using std::cout; using std::cin;
using std::endl; using std::string;


int SCREEN_WIDTH = 720;
int SCREEN_HEIGHT = 480;

SDL_Color White = {255, 255, 255};
SDL_Color Red = {255, 0, 0};
SDL_Color Green = {0, 255, 0};
char num_char[10 + sizeof(char)];
char tmp[256];



view::view(std::vector<std::vector<tijolo> >& t_, std::vector<barra>& ba_, bolinha* bo_, pontos* po_, vida* v_): t(t_),ba(ba_),bo(bo_), po(po_), v(v_){}

SDL_Rect* view::getTarget(){return &target;}
SDL_Rect* view::getBloco(){return &bloco;}
SDL_Rect* view::getBolinha(){return &bol;}
SDL_Rect* view::getBarra(){return &bar;}
std::vector<barra>& view::getBarras(){return ba;}
std::vector<std::vector<tijolo> >& view::getTijolos(){return t;}
pontos* view::getPonto(){return po;}
vida* view::getVida(){return v;}


int view::getWidth(){return SCREEN_WIDTH;};
int view::getHeigth(){return SCREEN_HEIGHT;};


const Uint8* view::getState(){return state;}


//Metodo que gera todas as estruturas iniciais de vizualizacao do SDL
int view::init(){

    //Inicia e configura o TTF (vizualizacao de texto)
    TTF_Init();
    int width, heigth;
    if(SCREEN_WIDTH/SCREEN_HEIGHT > 2.32){  
        width = 21;
        heigth = 9;
    }else if(SCREEN_WIDTH/SCREEN_HEIGHT < 1.34){
        width = 4;
        heigth = 3;
    }else{
        width = 16;
        heigth = 9;
    }
    
    getcwd(tmp, 256);

    std::string font; 
    cout << tmp << endl;
    font += tmp;

    font = font.substr(0, font.size()-3);        //Retira o 'bin' do caminho
    font.append("assets/PressStart2P-vaV7.ttf"); //Adiciona a localidade e o nome da fonte
    std::copy(font.begin(), font.end(), tmp);
    
    int font_size;
    if(SCREEN_HEIGHT > 2160){  
        font_size = 50;
    }else if(SCREEN_HEIGHT <= 720){
        font_size = 25;
    }else{
        font_size = 40;
    }

    Font = TTF_OpenFont(tmp, font_size); //carrega a fonte e define seu tamanho
    if(!Font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }   


    //Inicializa as posicoes e tamanhos dos textos

    //Texto "Vida"
    Message_Vida_rect.x = (v->getX()*SCREEN_WIDTH/16);//20;  
    Message_Vida_rect.y = (v->getY()*SCREEN_HEIGHT/9);//20; 
    Message_Vida_rect.w = (v->getWmult()*SCREEN_WIDTH/16);//80; 
    Message_Vida_rect.h = (v->getHmult()*SCREEN_HEIGHT/9);//50;
    
    //Texto "Pontos"
    Message_Pontos_rect.x = (po->getX()*SCREEN_WIDTH/16);//320;   
    Message_Pontos_rect.y = (po->getY()*SCREEN_HEIGHT/9);//20; 
    Message_Pontos_rect.w = (po->getWmult()*SCREEN_WIDTH/16);//80; 
    Message_Pontos_rect.h = (po->getHmult()*SCREEN_HEIGHT/9);//50;
    
    //Converte o valor da vida pra char
    std::sprintf(num_char, "%d", v->getValue());
    Message_VidaValue_rect.x= ((v->getX()+3.25)*SCREEN_WIDTH/16);//170;  
    Message_VidaValue_rect.y = (v->getY()*SCREEN_HEIGHT/9);//20; 
    Message_VidaValue_rect.w = (v->getHmult()*SCREEN_HEIGHT/9);//50; 
    Message_VidaValue_rect.h = (v->getHmult()*SCREEN_HEIGHT/9);//50;
    
    //Converte o valor da pontuacao pra char
    std::sprintf(num_char, "%d", po->getValue());
    Message_PointValue_rect.x = ((po->getX()+4.55)*SCREEN_WIDTH/16);//520;   
    Message_PointValue_rect.y = (po->getY()*SCREEN_HEIGHT/9);//20; 
    Message_PointValue_rect.w = (po->getHmult()*SCREEN_HEIGHT/9);//50; 
    Message_PointValue_rect.h = (po->getHmult()*SCREEN_HEIGHT/9);//50;  
    
    //Inicializando os tamanhos dos objetos


    //Tijolos
    for(int i=0; i<t.size(); i++){
        for(int j=0; j<t[i].size();j++){
            t[i][j].setH(t[i][j].getHmult()*SCREEN_HEIGHT/9);
            t[i][j].setW(t[i][j].getWmult()*SCREEN_WIDTH/16);
            t[i][j].setX(t[i][j].getX()*((SCREEN_WIDTH/16)+(t[i][j].getW()/3)));
            t[i][j].setY(((t[i][j].getY()*(SCREEN_HEIGHT/9))+(t[i][j].getH()/1.5)));
        }
    } 
    
    
    //Inicializando a Barras
    for(int i=0; i<ba.size(); i++){
        //Inicializando limites laterais das Barras
        if(ba.size() <=2){
            ba[i].setLeftLim(0);
            ba[i].setRigthLim(SCREEN_WIDTH);
        }else if(ba.size() == 3 || ba.size() == 4){
            if(ba[i].getX() == 4){
                ba[i].setLeftLim(0);
                ba[i].setRigthLim(SCREEN_WIDTH/2);
            }else{
                ba[i].setLeftLim(SCREEN_WIDTH/2);
                ba[i].setRigthLim(SCREEN_WIDTH);
            }
        }else{
            if(ba[i].getX() == 2){
                ba[i].setLeftLim(0);
                ba[i].setRigthLim(SCREEN_WIDTH/3);
            }else if (ba[i].getX() == 7){
                ba[i].setLeftLim(SCREEN_WIDTH/3);
                ba[i].setRigthLim(SCREEN_WIDTH*(2/3));
            }else {
                ba[i].setLeftLim(SCREEN_WIDTH*(2/3));
                ba[i].setRigthLim(SCREEN_WIDTH);
            }
        }

        ba[i].setX(ba[i].getX()*SCREEN_WIDTH/16);
        ba[i].setY(ba[i].getY()*SCREEN_HEIGHT/9);
        ba[i].setH(ba[i].getHmult()*SCREEN_HEIGHT/9);
        ba[i].setW(ba[i].getWmult()*SCREEN_WIDTH/16);
    }    

    //Bolinha
    bo->setH(bo->getHmult()*SCREEN_HEIGHT/9);
    bo->setW(bo->getWmult()*SCREEN_WIDTH/16);
    bo->setX(ba[0].getX()+ba[0].getW()/2);
    bo->setY(ba[0].getY()-bo->getH());

    //Inicializando a Bolinha
    bol.h = bo->getH();
    bol.w = bo->getW();
    bol.x = bo->getX();
    bol.y = bo->getY();    
    

    //Inicia a variavel de estado que vai ler o teclado
    state = SDL_GetKeyboardState(nullptr);
    return width/heigth;
}

int view::initClient(){
    TTF_Init();
    //SDL_GetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
    getcwd(tmp, 256);

    std::string font; 
    cout << tmp << endl;
    font += tmp;

    font = font.substr(0, font.size()-3);        //Retira o 'bin' do caminho
    font.append("assets/PressStart2P-vaV7.ttf"); //Adiciona a localidade e o nome da fonte
    std::copy(font.begin(), font.end(), tmp);
    
    int font_size;
    if(SCREEN_HEIGHT > 2160){  
        font_size = 50;
    }else if(SCREEN_HEIGHT <= 720){
        font_size = 25;
    }else{
        font_size = 40;
    }

    Font = TTF_OpenFont(tmp, font_size); //carrega a fonte e define seu tamanho
    if(!Font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }   


    //Inicializa as posicoes e tamanhos dos textos

    //Texto "Vida"
    Message_Vida_rect.x = (v->getX()*SCREEN_WIDTH/16);//20;  
    Message_Vida_rect.y = (v->getY()*SCREEN_HEIGHT/9);//20; 
    Message_Vida_rect.w = (v->getWmult()*SCREEN_WIDTH/16);//80; 
    Message_Vida_rect.h = (v->getHmult()*SCREEN_HEIGHT/9);//50;
    
    //Texto "Pontos"
    Message_Pontos_rect.x = (po->getX()*SCREEN_WIDTH/16);//320;   
    Message_Pontos_rect.y = (po->getY()*SCREEN_HEIGHT/9);//20; 
    Message_Pontos_rect.w = (po->getWmult()*SCREEN_WIDTH/16);//80; 
    Message_Pontos_rect.h = (po->getHmult()*SCREEN_HEIGHT/9);//50;
    
    //Converte o valor da vida pra char
    std::sprintf(num_char, "%d", v->getValue());
    Message_VidaValue_rect.x= ((v->getX()+3.25)*SCREEN_WIDTH/16);//170;  
    Message_VidaValue_rect.y = (v->getY()*SCREEN_HEIGHT/9);//20; 
    Message_VidaValue_rect.w = (v->getHmult()*SCREEN_HEIGHT/9);//50; 
    Message_VidaValue_rect.h = (v->getHmult()*SCREEN_HEIGHT/9);//50;
    
    //Converte o valor da pontuacao pra char
    std::sprintf(num_char, "%d", po->getValue());
    Message_PointValue_rect.x = ((po->getX()+4.55)*SCREEN_WIDTH/16);//520;   
    Message_PointValue_rect.y = (po->getY()*SCREEN_HEIGHT/9);//20; 
    Message_PointValue_rect.w = (po->getHmult()*SCREEN_HEIGHT/9);//50; 
    Message_PointValue_rect.h = (po->getHmult()*SCREEN_HEIGHT/9);//50;  
    
    //Inicializando os tamanhos dos objetos

    //Bolinha
    bo->setH(bo->getHmult()*SCREEN_HEIGHT/9);
    bo->setW(bo->getWmult()*SCREEN_WIDTH/16);

    //Barrinha
    for(int i=0; i<ba.size(); i++){
        ba[i].setH(ba[i].getHmult()*SCREEN_HEIGHT/9);
        ba[i].setW(ba[i].getWmult()*SCREEN_WIDTH/16);
    }
    //Tijolos
    for(int i=0; i<t.size(); i++){
        for(int j=0; j<t[i].size(); j++){
            t[i][j].setW(t[i][j].getWmult()*SCREEN_WIDTH/16);
            t[i][j].setH(t[i][j].getHmult()*SCREEN_HEIGHT/9);
        }
    } 

    //Inicializando a Bolinha
    bol.h = bo->getH();
    bol.w = bo->getW();
    bol.x = bo->getX();
    bol.y = bo->getY();
   

    //Inicia a variavel de estado que vai ler o teclado
    state = SDL_GetKeyboardState(nullptr);
    return 0;
}

//Faz as atualizacoes necessarias para cada renderizacao da tela
void view::render(int user){

    //Define a cor da tela como preta
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    if(t.size() == 1){
        //Renderiza os textos
        render_text(renderer, Message_Vida_rect.x, Message_Vida_rect.y, "Vida: ",Font, &Message_Vida_rect, &White);
        render_text(renderer, Message_Pontos_rect.x, Message_Pontos_rect.y, "Pontos: ",Font, &Message_Pontos_rect, &White);
        std::sprintf(num_char, "%d", v->getValue());
        render_text(renderer, Message_VidaValue_rect.x, Message_VidaValue_rect.y, num_char,Font, &Message_VidaValue_rect, &White);
        std::sprintf(num_char, "%d", po->getValue());
        render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Font, &Message_PointValue_rect, &White);
    } else {
        if(user == -1){
            std::sprintf(num_char, "Server");
        }else{
            std::sprintf(num_char, "Player %d", user);
        }  
        render_text(renderer, Message_Vida_rect.x, Message_Vida_rect.y, num_char,Font, &Message_Vida_rect, &White);
    }
    //Renderiza os tijolos
    for(int i=0; i<t.size(); i++){
        for(int j=0; j<t[i].size(); j++){
            bloco.h = t[i][j].getH();
            bloco.w = t[i][j].getW();
            bloco.x = t[i][j].getX();
            bloco.y = t[i][j].getY();

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &bloco);
            SDL_RenderFillRect( renderer, &bloco );
        }
    } 

    //Inicializando a Bolinha
    bol.h = bo->getH();
    bol.w = bo->getW();
    bol.x = bo->getX();
    bol.y = bo->getY();
    
    for(int i=0; i<ba.size(); i++){
        if(ba[i].isVisible()){
            //Inicializando a Barra
            bar.h = ba[i].getH();
            bar.w = ba[i].getW();
            bar.x = ba[i].getX();
            bar.y = ba[i].getY();

            //Renderiza as barras
            SDL_SetRenderDrawColor(renderer, 64, 244, 208, 255);
            SDL_RenderDrawRect(renderer, &bar);
            SDL_RenderFillRect( renderer, &bar );
        }    
    }
    //Renderiza as bolinhas
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &bol);
    SDL_RenderFillRect( renderer, &bol );

    //Encerra um ciclo de renderizacao
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
}

//Mostra na tela a mensagem de derrota
void view::perdeu(int user){
    render(user);
    render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Font, &Message_PointValue_rect, &White);
     
    int font_size;
    if(SCREEN_HEIGHT > 2160){  
        font_size = 80;
    }else if(SCREEN_HEIGHT <= 720){
        font_size = 40;
    }else{
        font_size = 70;
    }
    TTF_Font* Font2 = TTF_OpenFont(tmp,font_size);
    Message_Fim_rect.x = (SCREEN_WIDTH/2)-(4*font_size);   
    Message_Fim_rect.y = SCREEN_HEIGHT/2; 
    Message_Fim_rect.w = 150;
    render_text(renderer, Message_Fim_rect.x, Message_Fim_rect.y, "PERDEU!!!",Font2, &Message_Fim_rect, &Red);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}
//Mostra na tela a mensagem de vitoria
void view::ganhou(int user){
    render(user);
    render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Font, &Message_PointValue_rect, &White);
    
    int font_size;
    if(SCREEN_HEIGHT > 2160){  
        font_size = 80;
    }else if(SCREEN_HEIGHT <= 720){
        font_size = 40;
    }else{
        font_size = 70;
    }
    Message_Fim_rect.x = (SCREEN_WIDTH/2)-(4*font_size);   
    Message_Fim_rect.y = SCREEN_HEIGHT/2; 
    Message_Fim_rect.w = 150;
    TTF_Font* Font2 = TTF_OpenFont(tmp,font_size);
    render_text(renderer, Message_Fim_rect.x, Message_Fim_rect.y, "GANHOU!!!",Font2, &Message_Fim_rect, &Green);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}

void view::ganhouMulti(int user_id){
    render(-1);
    render_text(renderer, Message_PointValue_rect.x, Message_PointValue_rect.y, num_char,Font, &Message_PointValue_rect, &White);
    
    int font_size;
    if(SCREEN_HEIGHT > 2160){  
        font_size = 80;
    }else if(SCREEN_HEIGHT <= 720){
        font_size = 40;
    }else{
        font_size = 70;
    }
    Message_Fim_rect.x = (SCREEN_WIDTH/2)-(8*font_size);   
    Message_Fim_rect.y = SCREEN_HEIGHT/2; 
    Message_Fim_rect.w = 150;
    TTF_Font* Font2 = TTF_OpenFont(tmp,font_size);
    std::stringstream fim;
    fim << "PLAYER ";
    fim << user_id;
    fim << " GANHOU!!";
    std::string output = fim.str();
    render_text(renderer, Message_Fim_rect.x, Message_Fim_rect.y, output.c_str() , Font2, &Message_Fim_rect, &Green);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}

//Funcao para renderizar um texto
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
    
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, rect);
    SDL_DestroyTexture(texture);
}

//Encerra a janela de vizualizacao e a execucao do programa
void view::quit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

int view::window_create(int size){
    if (size == 0){
        SCREEN_WIDTH = 1920;
        SCREEN_HEIGHT = 1080;
    } else {
        SCREEN_WIDTH = 720;
        SCREEN_HEIGHT = 480;
    }
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
        return 1;
    }
    //Cria a janela
    window = nullptr;
    window = SDL_CreateWindow("Breakout",
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

    //cria um renderizador
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
}