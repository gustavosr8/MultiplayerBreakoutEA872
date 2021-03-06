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
        float x_param, y_param;
        int h, w;                       /*!< Variaveis de dimensao*/
        float w_mult = 2, h_mult = 0.25;/*!< Fator de multiplicacao para visualizacao*/       
        int color;                      /*!< Cor da barra*/
        int lim_left, lim_rigth;        /*!< Limites laterais de movimento*/
        bool show = true;               /*!< Diz se a barra deve ser mostrada na tela*/

    public:
        /*! \brief Construtor da barra
         *  
         *  Recebe uma posicao (x,y) inicial da barra
        */
        barra(int x_, int y_);
        barra();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(barra, x,y,w,h,x_param,y_param, lim_left, lim_rigth, show);
        int getX();
        int getY();
        int getLeftLim();
        int getRightLim();
        int getW();
        int getH();
        bool isVisible();
        float getWmult();
        float getHmult();
        float getXparam();
        float getYparam();
        void setXparam(float x_param_);
        void setYparam(float y_param_);
        void setW(int w_);
        void setH(int h_);
        void setX(int x_);
        void setY(int y_);
        void setLeftLim(int lim_left_);
        void setRigthLim(int lim_rigth_);
        bool setVisibility(bool show_);
        std::string print();
};