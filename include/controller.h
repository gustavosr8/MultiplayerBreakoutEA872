#pragma once
#include "barra.h"
#include "view.h"
#include "bolinha.h"
#include <SDL2/SDL.h>

/*! \brief Classe para o controller
 *
 *  Esta é a classe para o controller.
 *  Ela faz o link entre os controles direcionais e a barra,
 *  tambem faz a movimentacao da bolinha, 
 *  assim como sua colisao com as bordas da tela, barra e blocos.
 *  Faz tambem a destruicao do bloco e o reposicionamento da bolinha
*/

class controller{
    
    private:
        view &v;        /*!< view (alocado previamente)*/
        barra* ba;      /*!< barra (alocada previamente*/
        bolinha* bo;    /*!< bolinha (alocada previamente)*/
        int dirX = 5;   /*!< direcao de movimentacao da bolinha em X*/
        int dirY = 5;   /*!< direcao de movimentacao da bolinha em Y*/
        int veloc = 10; /*!< velocidade de movimentacao da bolinha*/
    
    public:
        /*! \brief Construtor do controller
         *  
         *  Recebe um view, uma barra e uma bolinha
         * 
         * \param v_ um objeto view onde os objetos vao ser mostrados
         * \param ba_ objeto barra
         * \param bo_ objeto bolinha
        */
        controller(view &v_, barra* ba_, bolinha* bo_): ba(ba_), v(v_), bo(bo_){}

        /*! \brief Metodo de acao
         *  
         *  serie de eventos que acontecem a cada ciclo de jogo
        */
        void update();

        /*! \brief Colisao barra/bolinha
         *  
         *  checa a colisao entre a barra e a bolinha
         * 
         *  \return retorna true caso haja colisao
        */
        bool colisaoBarra();

        /*! \brief Colisao blocos/bolinha
         *  
         *  checa a colisao entre a todos os blocos e a bolinha
         *  caso haja colisao, tira o bloco da visualizacao 
         * 
         *  \return retorna true caso haja colisao
        */
        bool colisaoBloco();

        /*! \brief Inicia o jogo
         *  
         *  checa se uma tecla previamente estabelecida foi pressionada,
         *  iniciando o movimento da bolinha
         * (Tecla S)
         * 
        */
        void start();

        /*! \brief Finaliza o jogo
         *  
         *  checa se uma tecla previamente estabelecida foi pressionada,
         *  encerrando a execução e fechando o programa
         * (Tecla Esc)
         * 
        */
        bool finish();
        bool save();
        bool load();
};