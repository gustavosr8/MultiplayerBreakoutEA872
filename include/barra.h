#pragma once
#include "json.hpp"


/*! \brief Classe para a barra
 *
 *  Esta é a classe para a barra. 
 *  Ela possui variaveis internas para guardar suas dimensoes e posicao,
 *  alem de ter um fator de multiplicacao para quando for ser mostrada na tela.
 * 
*/

class barra{
    private:
        int x,y;                        /*!< Variaveis de posicao*/
        int h, w;                       /*!< Variaveis de dimensao*/
        float w_mult = 2, h_mult = 0.25;/*!< Fator de multiplicacao para visualizacao*/       
        int color;                      /*!< Cor da barra*/

    public:
        /*! \brief Construtor da barra
         *  
         *  Recebe uma posicao (x,y) inicial da barra
        */
        barra(int x_, int y_);
        barra();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(barra, x,y);
        int getX();
        int getY();
        int getW();
        int getH();
        float getWmult();
        float getHmult();
        void setW(int w_);
        void setH(int h_);
        void setX(int x_);
        void setY(int y_);
};