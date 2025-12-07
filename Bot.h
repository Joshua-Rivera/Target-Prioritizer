#pragma once

class Bot{
    private:
        double bot_x;
        double bot_y;
    public:
        Bot(double bot_x, double bot_y);
    
        //Getters
        double getBot_x();
        double getBot_y();
    
        //Setters
        void setBot_x(double NewBot_X);
        void setBot_y(double NewBot_y);
    };