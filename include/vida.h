#pragma once
#include "json.hpp"

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para armazenar os pontos do jogador.
*/

class vida{
    private:
        int value;      /*!< quantidade de vidas*/

    public:
        vida(int value_);
        vida();        
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(vida, value);
        int getValue();
        void setValue(int value_);
};