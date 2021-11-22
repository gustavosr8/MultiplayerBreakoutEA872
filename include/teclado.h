#pragma once
#include "json.hpp"

/*! \brief Classe para oteclado
 *
 *  Classe armazena a funcao da tecla que foi pressionada
*/

class teclado{
    private:
        bool up, down, left, rigth, start, load, save, exit, space;  /*!< variáveis do teclado*/

    public:
        teclado(bool up_, bool down_, bool left_, bool rigth_, bool start_, bool load_, bool save_, bool exit_, bool space_);
        teclado();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(teclado, up, down, left, rigth, start, load, save, exit, space);
        bool Up();
        void setUp(bool up_);
        bool Down();
        void setDown(bool down_);
        bool Left();
        void setLeft(bool left_);
        bool Rigth();
        void setRight(bool rigth_);
        bool Start();
        void setStart(bool start_);
        bool Load();
        void setLoad(bool load_);
        bool Save();
        void setSave(bool save_);
        bool Exit();
        void setExit(bool exit_);
        bool Space();
        void setSpace(bool space_);
};