#pragma once
#include "json.hpp"

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para os tijolos.
*/

class tijolo{
    private:
        int x,y;                    /*!< Variaveis de posicao*/
        int h, w;                   /*!< Variaveis de dimensao*/
        float x_param, y_param;     /*!< Fatores de parametrizacao da posicao*/
        float w_mult=1, h_mult=0.5; /*!< Fator de multiplicacao para visualizacao*/
        int color;                  /*!< Cor da barra*/

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(tijolo, x,y,w,h,x_param,y_param);
        tijolo(int x_, int y_);
        tijolo();
        int getX();
        int getY();
        int getW();
        int getH();
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
};

