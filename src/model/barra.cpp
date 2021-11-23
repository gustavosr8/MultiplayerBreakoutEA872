#include "barra.h"

barra::barra(int x_, int y_){
    x=x_;
    y=y_;
}

barra::barra(){
    x=0;
    y=0;
}

int barra::getX(){return x;}
int barra::getY(){return y;}
int barra::getLeftLim(){return lim_left;}
int barra::getRightLim(){return lim_rigth;}
int barra::getW(){return w;}
int barra::getH(){return h;}
bool barra::isVisible(){return show;}
float barra::getHmult(){return h_mult;}
float barra::getWmult(){return w_mult;}
float barra::getXparam(){return x_param;}
float barra::getYparam(){return y_param;}
void barra::setXparam(float x_param_){x_param=x_param_;}
void barra::setYparam(float y_param_){y_param=y_param_;}
void barra::setW(int w_){w=w_;}
void barra::setH(int h_){h=h_;}
void barra::setX(int x_){x=x_;}
void barra::setY(int y_){y=y_;}
void barra::setLeftLim(int lim_left_){lim_left=lim_left_;}
void barra::setRigthLim(int lim_rigth_){lim_rigth=lim_rigth_;}
bool barra::setVisibility(bool show_){show = show_;}
std::string barra::print(){
    std::string temp;
    temp.append("x: ");
    temp += std::to_string(x);
    temp.append(", y: ");
    temp += std::to_string(y);
    temp.append(", w: ");
    temp += std::to_string(w);
    temp.append(", h: ");
    temp += std::to_string(h);
    return temp;
};
