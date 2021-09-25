#pragma once

class tijolo{
    private:
        int x,y;
        int w = 260;
        int h = 80;
        int color;
        bool estado = true;

    public:
        tijolo(int x_, int y_);
        int getX();
        int getY();
        int getW();
        int getH();
        void setX(int x_);
        void setY(int y_);
        bool getEstado();
        void setEstado(bool e);
};