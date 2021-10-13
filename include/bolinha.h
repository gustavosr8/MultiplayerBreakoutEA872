#pragma once
#include "json.hpp"


/*! \brief Classe para a bolinha
 *
 *  Esta é a classe para a bolinha. 
 *  Ela possui variaveis internas para guardar suas dimensoes e posicao,
 *  alem de ter um fator de multiplicacao para quando for ser mostrada na tela.
 *  Tambem tem os parametros de estado exit e pause
*/

class bolinha{
    private:
        int x,y;                        /*!< Variaveis de posicao*/
        int h, w;                       /*!< Variaveis de dimensao*/
        float h_mult=0.25, w_mult=0.25; /*!< Fator de multiplicacao para visualizacao*/
        int color;                      /*!< Cor da bolinha*/
        bool exit = false;              /*!< Variavel de condicao. Tem valor true caso a bolinha atinja a parte inferior da tela*/
        bool pause = false;             /*!< Variavel de condicao. Caso seja true, a bolinha fica parada em uma posicao definida*/

    public:
        /*! \brief Construtor da bolinha
         *  
         *  Recebe uma posicao (x,y) inicial da bolinha
        */
        bolinha(int x_, int y_);
        bolinha();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(bolinha, x,y);
        int getX();
        int getY();
        int getW();
        int getH();
        float getWmult();
        float getHmult();
        bool getExit();
        bool getPause();
        void setX(int x_);
        void setY(int y_);
        void setW(int w_);
        void setH(int h_);
        void setExit(bool exit_);
        void setPause(bool pause_);
};
