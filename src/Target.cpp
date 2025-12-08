#include "Target.h"

Target::Target(int id, int priority, double x_cord, double y_cord){
    this->id = id;
    this->priority = priority;
    this->x_cord = x_cord;
    this->y_cord = y_cord;
    distanceFromBot = 0;
}

//Setters
void Target::setID(int newID){id = newID;}
void Target::setPriority(int newPriority) {priority = newPriority;}
void Target::setX_cord(double NewX) {x_cord = NewX;}
void Target::setY_cord(double NewY) {y_cord = NewY;}
void Target::setDistanceFromBot(double NewBotDist) {distanceFromBot = NewBotDist;}
//Getters
int Target::getID() const {return id;}
int Target::getPriority() const {return priority;}
double Target::getX_Cord() const {return x_cord;}
double Target::getY_Cord() const {return y_cord;}
double Target::getDistanceFromBot() const {return distanceFromBot;}