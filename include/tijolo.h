#pragma once

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para os tijolos.
*/

class tijolo{
    private:
        int x,y;                    /*!< Variaveis de posicao*/
        int h, w;                   /*!< Variaveis de dimensao*/
        float w_mult=2, h_mult=0.5; /*!< Fator de multiplicacao para visualizacao*/
        int color;                  /*!< Cor da barra*/
        bool estado = true;         /*!< Variavel de estado, que diz se o tijolo existe ou nao*/

    public:
        tijolo(int x_, int y_);
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
        bool getEstado();
        void setEstado(bool e);
};

