#pragma once

class bolinha{
    private:
        int x,y;
        int w = 20;
        int h = 20;
        int color;
        bool exit = false;
        bool pause = false;

    public:
        bolinha(int x_, int y_);
        int getX();
        int getY();
        int getW();
        int getH();
        bool getExit();
        bool getPause();
        void setX(int x_);
        void setY(int y_);
        void setExit(bool exit_);
        void setPause(bool pause_);
};