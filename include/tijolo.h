#pragma once

class tijolo{
    private:
        int x,y;
        int w = 40;
        int h = 20;
        int color;

    public:
        tijolo(int x_, int y_);
        int getX();
        int getY();
        int getW();
        int getH();
        void setX(int x_);
        void setY(int y_);
};