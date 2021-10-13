#pragma once
#include "json.hpp"

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para armazenar os pontos do jogador.
*/

class pontos{
    private:
        int value;  /*!< quantidade de pontos*/

    public:
        pontos(int value_);
        pontos();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(pontos, value);
        int getValue();
        void setValue(int value_);
};