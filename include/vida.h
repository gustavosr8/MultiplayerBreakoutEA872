#pragma once
#include "json.hpp"

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para armazenar os pontos do jogador.
*/

class vida{
    private:
        int value;                      /*!< quantidade de vidas*/
        float w_mult=2, h_mult=0.5;     /*!< Multiplicadores para parametrizar altura e largura*/
        int x = 0.5, y = 0.7;           /*!< Posicao da vida*/

    public:
        vida(int value_);
        vida();        
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(vida, value);
        int getValue();
        void setValue(int value_);
        float getWmult();
        float getHmult();
        int getX();
        int getY();
};