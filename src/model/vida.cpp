#include "vida.h"

vida::vida(int value_){
    value=value_;
}

vida::vida(){
    value=0;
}
int vida::getValue(){return value;}
void vida::setValue(int value_){value=value_;}
