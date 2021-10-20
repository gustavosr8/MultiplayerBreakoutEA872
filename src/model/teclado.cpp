#include "teclado.h"

teclado::teclado(bool up_, bool down_, bool left_, bool rigth_, bool start_, bool load_, bool save_, bool exit_, bool space_)
{
    up = up_;
    down = down_;
    left = left_;
    rigth = rigth_;
    start = start_;
    load = load_;
    save = save_;
    exit = exit_;
    space = space_;
}

teclado::teclado()
{
    up = false;
    down = false;
    left = false;
    rigth = false;
    start = false;
    load = false;
    save = false;
    exit = false;
    space =  false;
}

bool teclado::Up() { return up; };
void teclado::setUp(bool up_) { up = up_; };
bool teclado::Down() { return down; };
void teclado::setDown(bool down_) { down = down_; };
bool teclado::Left() { return left; };
void teclado::setLeft(bool left_) { left = left_; };
bool teclado::Rigth() { return rigth; };
void teclado::setRight(bool rigth_) { rigth = rigth_; };
bool teclado::Start() { return start; };
void teclado::setStart(bool start_) { start = start_; };
bool teclado::Load() { return load; };
void teclado::setLoad(bool load_) { load = load_; };
bool teclado::Save() { return save; };
void teclado::setSave(bool save_) { save = save_; };
bool teclado::Exit() { return exit; };
void teclado::setExit(bool exit_) { exit = exit_; };
bool teclado::Space() { return space; };
void teclado::setSpace(bool space_) { space = space_; };