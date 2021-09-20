#include "model.hpp"

model::model(int x_, int y_){
    x=x_;
    y=y_;
}

int model::getX(){return x;}
int model::getY(){return y;}
void model::setX(int x_){x=x_;}
void model::setY(int y_){y=y_;}