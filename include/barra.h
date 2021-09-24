#pragma once

class barra{
    private:
        int x,y;
        int w = 80;
        int h = 20;
        int color;

    public:
        barra(int x_, int y_);
        int getX();
        int getY();
        int getW();
        int getH();
        void setX(int x_);
        void setY(int y_);
};