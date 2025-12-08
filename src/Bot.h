#pragma once

class Bot{
    private:
        double bot_x;
        double bot_y;
    public:
        Bot(double bot_x, double bot_y);
    
        //Getters
        double getBot_x() const;
        double getBot_y() const;
    
        //Setters
        void setBot_x(double NewBot_X);
        void setBot_y(double NewBot_y);
    };