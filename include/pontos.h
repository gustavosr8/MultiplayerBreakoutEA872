#pragma once

/*! \brief Classe para os pontos
 *
 *  Classe utilizada para armazenar os pontos do jogador.
*/

class pontos{
    private:
        int value;  /*!< quantidade de pontos*/

    public:
        pontos(int value_);
        int getValue();
        void setValue(int value_);
};