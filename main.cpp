#include <iostream>
#include <vector>
#include "Bot.h"
#include "Target.h"
#include "Calculations.h"
using namespace std;

// Run utilizing make and then ./sim in terminal!!!!!!!!!!
int main(){
    srand(time(nullptr)); //Make sure randint is always random
    Bot bot (0,0);
    vector<Target> targets;
    generateTargets(targets, 5);
    getRobotPosition(bot);
    getDistanceFromTarget(bot, targets);
    sortPriorityTarget(targets);
    for (int i = 0; i < targets.size(); i++){
        cout << "======================================" << "\nPriority: " << targets[i].getPriority() << "\nID: " << targets[i].getID() 
        << "\nTarget Coordinates: (" << targets[i].getX_Cord() << ", " << targets[i].getY_Cord() <<  ")\nBot Coordinates: (" << bot.getBot_x() << "," << bot.getBot_y() 
        << ")\nDistance from Target: " << targets[i].getDistanceFromBot() 
        <<"\n======================================" <<endl;
    }
    return 0;
}