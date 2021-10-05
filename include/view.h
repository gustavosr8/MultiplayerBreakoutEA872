#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <sstream>
#include <experimental/filesystem>
#include "tijolo.h"
#include "bolinha.h"
#include "barra.h"
#include "pontos.h"
#include "vida.h"

/*! \brief Classe para o view
 *
 *  Esta é a classe para o view.
 *  Ela recebe todos os objetos que precisam ser mostrados em tela,
 *  e utiliza a biblioteca SDL2 para isso.
 *  */

class view{
    private:
        
        tijolo *t;      /*!< tijolo (alocado previamente)*/
        bolinha *bo;    /*!< bolinha (alocado previamente)*/
        barra *ba;      /*!< barra (alocado previamente)*/
        pontos* po;     /*!< pontos (alocado previamente)*/
        vida* v;        /*!< vida (alocado previamente)*/

        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Rect bloco;
        SDL_Rect target;
        SDL_Rect bol;
        SDL_Rect bar;
        const Uint8 *state;
        TTF_Font* Font;

        SDL_Rect Message_Vida_rect;
        SDL_Rect Message_Fim_rect;
        SDL_Rect Message_Pontos_rect;
        SDL_Rect Message_VidaValue_rect;
        SDL_Rect Message_PointValue_rect;





    public:
        /*! \brief Construtor do view
         *  
         *  Recebe um tudo o que for ser mostrado em tela
         * 
         * \param t_ objeto tijolp
         * \param ba_ objeto barra
         * \param bo_ objeto bolinha
         * \param po_ objeto pontos
         * \param v_ objeto vida
        */
        void render_text(SDL_Renderer *renderer,int x, int y,const char *text,TTF_Font *font,SDL_Rect *rect,SDL_Color *color);
        view(tijolo* t_, barra* ba_, bolinha* bo_, pontos* po_, vida* v_);
        SDL_Rect* getTarget();
        SDL_Rect* getBloco();
        SDL_Rect* getBolinha();
        SDL_Rect* getBarra();
        tijolo* getTijolos();
        pontos* getPonto();
        vida* getVida();
        int getWidth();
        int getHeigth();
        const Uint8* getState();

        /*! \brief Rotina de inicializacao
         *  
         *  Sequencia de acoes que inicializam a janela de visualizacao
        */
        int init();

        /*! \brief Renderizacao
         *  
         *  Metodo que renderiza todos os objetos a cada ciclo definido
        */
        void render();

        /*! \brief Encerramento
         *  
         *  Metodo que encerra os objetos de visualizacao e fecha o programa
        */
        void quit();
        void perdeu();
        void ganhou();
        int quantidadeTijolos();

};