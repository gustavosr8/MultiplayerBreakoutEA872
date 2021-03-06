#pragma once
#include "json.hpp"

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para armazenar os pontos do jogador.
*/

class pontos{
    private:
        int value;  /*!< quantidade de pontos*/
        float w_mult=2, h_mult=0.5;
        int x = 5.5, y = 0.7; 

    public:
        pontos(int value_);
        pontos();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(pontos, value);
        int getValue();
        void setValue(int value_);
        float getWmult();
        float getHmult();
        int getX();
        int getY();
};