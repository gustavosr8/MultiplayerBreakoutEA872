#pragma once

class tijolo{
    private:
        int x,y;
        int h, w;
        float w_mult = 2;
        float h_mult = 0.5;
        int color;
        bool estado = true;

    public:
        tijolo(int x_, int y_);
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
        bool getEstado();
        void setEstado(bool e);
};

