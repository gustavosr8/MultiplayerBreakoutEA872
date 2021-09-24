#pragma once

class bolinha{
    private:
        int x,y;
        int w = 20;
        int h = 20;
        int color;

    public:
        bolinha(int x_, int y_);
        int getX();
        int getY();
        int getW();
        int getH();
        void setX(int x_);
        void setY(int y_);
};