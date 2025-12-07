#include "Calculations.h"
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int RandomNumberGenerator(int min, int max){
     
    return min + rand() % (max - min + 1);
}

void generateTargets(vector<Target>& targets, int amount){
    int i = 1;
    while (i <= amount){
        int x = RandomNumberGenerator(-10, 10);
        int y = RandomNumberGenerator(-10, 10);
        int id = i; int priority = 0;
        Target newTarget(id, priority, x, y); //calls constructor so that i can create an object and work on the class itself;
        targets.push_back(newTarget);
        i++;
        }
        
        
}
void getRobotPosition(Bot& bot){
    int x = RandomNumberGenerator(-10, 10);
    int y = RandomNumberGenerator(-10, 10);
    bot.setBot_x(x);
    bot.setBot_y(y);
}
void getDistanceFromTarget(Bot& bot, vector<Target>& targets){
    double distance;
    for (int i = 0; i < targets.size(); i++){
        int x = targets[i].getX_Cord() - bot.getBot_x();
        int y = targets[i].getY_Cord() - bot.getBot_y();
        distance = sqrt(pow(x, 2) + pow(y, 2));
        targets[i].setDistanceFromBot(round(distance*100.0)/100.0);
    }return;
}

void sortPriorityTarget(vector<Target>& targets){
    int target = targets.size();
    bool swapped = false;
    int count = 1;
    for (int i = 0; i < target - 1; i ++){
        
        for (int j = 0; j < target - i - 1; j++){
            if (targets[j].getDistanceFromBot() > targets[j+1].getDistanceFromBot()){
                swap(targets[j], targets[j+1]);
                swapped = true;
            }
        }
    } for (int i = 0; i < targets.size(); i++){
        targets[i].setPriority(count);
        count++;
    }return;
    if (!swapped) {return;}
}