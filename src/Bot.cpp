#include "Bot.h"
Bot::Bot(double bot_x, double bot_y){
    this->bot_x = bot_x;
    this->bot_y = bot_y;
}

//Getters
double Bot::getBot_x() {return bot_x;}
double Bot::getBot_y() {return bot_y;}

//Setters
void Bot::setBot_x(double NewBot_X) {bot_x = NewBot_X;} 
void Bot::setBot_y(double NewBot_y) {bot_y = NewBot_y;}
