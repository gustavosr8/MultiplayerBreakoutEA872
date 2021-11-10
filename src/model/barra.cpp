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
int barra::getW(){return w;}
int barra::getH(){return h;}
float barra::getHmult(){return h_mult;}
float barra::getWmult(){return w_mult;}
void barra::setW(int w_){w=w_;}
void barra::setH(int h_){h=h_;}
void barra::setX(int x_){x=x_;}
void barra::setY(int y_){y=y_;}
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
