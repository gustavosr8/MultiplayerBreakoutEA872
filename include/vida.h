#pragma once

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para armazenar os pontos do jogador.
*/

class vida{
    private:
        int value;      /*!< quantidade de vidas*/

    public:
        vida(int value_);
        int getValue();
        void setValue(int value_);
};