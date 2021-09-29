#pragma once

class bolinha{
    private:
        int x,y;
        int h, w;
        float w_mult = 0.25;
        float h_mult = 0.25;
        int color;
        bool exit = false;
        bool pause = false;

    public:
        bolinha(int x_, int y_);
        int getX();
        int getY();
        int getW();
        int getH();
        float getWmult();
        float getHmult();
        bool getExit();
        bool getPause();
        void setX(int x_);
        void setY(int y_);
        void setW(int w_);
        void setH(int h_);
        void setExit(bool exit_);
        void setPause(bool pause_);
};
