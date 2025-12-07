#pragma once

class Target{
    private:
        int id;
        int priority;
        double x_cord;
        double y_cord;
        double bot_x;
        double bot_y;
        double distanceFromBot;
    public:
        Target(int id, int priority, double x_cord, double y_cord);
        //Setters
        void setID(int newID);
        void setPriority(int newPriority);
        void setX_cord(double NewX);
        void setY_cord(double NewY);
        void setDistanceFromBot(double NewBotDist);
        //Getters
        int getID();
        int getPriority();
        double getX_Cord();
        double getY_Cord();
        double getDistanceFromBot();
    
        
    };