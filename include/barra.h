#pragma once

class barra{
    private:
        int x,y;
        int h, w;
        float w_mult = 2;
        float h_mult = 0.25;
        int color;

    public:
        barra(int x_, int y_);
        int getX();
        int getY();
        int getW();
        int getH();
        float getWmult();
        float getHmult();
        void setW(int w_);
        void setH(int h_);
        void setX(int x_);
        void setY(int y_);
};