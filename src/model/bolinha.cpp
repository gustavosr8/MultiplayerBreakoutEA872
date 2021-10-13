#include "bolinha.h"

bolinha::bolinha(int x_, int y_){
    x=x_;
    y=y_;
}

bolinha::bolinha(){
    x=0;
    y=0;
}

int bolinha::getX(){return x;}
int bolinha::getY(){return y;}
int bolinha::getDirX(){return dirX;}
int bolinha::getDirY(){return dirY;}
int bolinha::getW(){return w;}
int bolinha::getH(){return h;}
bool bolinha::getExit(){return exit;}
bool bolinha::getPause(){return pause;}
float bolinha::getHmult(){return h_mult;}
float bolinha::getWmult(){return w_mult;}
void bolinha::setW(int w_){w=w_;}
void bolinha::setH(int h_){h=h_;}
void bolinha::setX(int x_){x=x_;}
void bolinha::setY(int y_){y=y_;}
void bolinha::setDirX(int dirX_){dirX=dirX_;}
void bolinha::setDirY(int dirY_){dirY=dirY_;}
void bolinha::setExit(bool exit_){exit=exit_;}
void bolinha::setPause(bool pause_){pause=pause_;}