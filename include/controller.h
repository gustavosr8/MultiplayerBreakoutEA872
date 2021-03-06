#pragma once
#include "barra.h"
#include "view.h"
#include "bolinha.h"
#include "teclado.h"
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
        view &v;                    /*!< view (alocado previamente)*/
        bolinha* bo;                /*!< bolinha (alocada previamente)*/
        std::vector<teclado>& keyb; /*!< tecla pressionada no cliente*/
        int veloc = 20;             /*!< velocidade de movimentacao da barrinha*/
    
    public:
        /*! \brief Construtor do controller
         *  
         *  Recebe um view, uma barra e uma bolinha
         * 
         * \param v_ um objeto view onde os objetos vao ser mostrados
         * \param bo_ objeto bolinha
         * \param keyb_ objeto teclado
        */
        controller(view &v_, bolinha* bo_, std::vector<teclado>& keyb_): v(v_), bo(bo_), keyb(keyb_){}

        /*! \brief Metodo de acao
         *  
         *  serie de eventos que acontecem a cada ciclo de jogo
        */
        void update();

        
        /*! \brief Movimento barrinha
         *  
         *  Recebe parametros de teclado e atualiza o movimento da barrinha 
        */
        void updateMovimento(barra* ba, teclado keyb, bool space_on);


        /*! \brief Colisao barra/bolinha
         *  
         *  checa a colisao entre a barra e a bolinha
         * 
         *  \return retorna true caso haja colisao
        */
        bool colisaoBarra(barra* barra);

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
        void start(int user);

        /*! \brief Finaliza o jogo
         *  
         *  checa se uma tecla previamente estabelecida foi pressionada,
         *  encerrando a execução e fechando o programa
         * (Tecla Esc)
         * 
        */
        bool finish(int user);

        /*! \brief Salva o jogo*/
        bool save(int user);

        /*! \brief Carrega o jogo salvo*/
        bool load(int user);
};