#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

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
    Target(int id, int priority, double x_cord, double y_cord){
        this->id = id;
        this->priority = priority;
        this->x_cord = x_cord;
        this->y_cord = y_cord;
        distanceFromBot = 0;
    }
    //Setters
    void setID(int newID){id = newID;}
    void setPriority(int newPriority) {priority = newPriority;}
    void setX_cord(double NewX) {x_cord = NewX;}
    void setY_cord(double NewY) {y_cord = NewY;}
    void setDistanceFromBot(double NewBotDist) {distanceFromBot = NewBotDist;}
    //Getters
    int getID(){return id;}
    int getPriority() {return priority;}
    double getX_Cord() {return x_cord;}
    double getY_Cord() {return y_cord;}
    double getDistanceFromBot() {return distanceFromBot;}

    
};

class Bot{
private:
    double bot_x;
    double bot_y;
public:
    Bot(double bot_x, double bot_y){
        this->bot_x = bot_x;
        this->bot_y = bot_y;
    }

    //Getters
    double getBot_x() {return bot_x;}
    double getBot_y() {return bot_y;}

    //Setters
    void setBot_x(double NewBot_X) {bot_x = NewBot_X;} 
    void setBot_y(double NewBot_y) {bot_y = NewBot_y;}
};


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
void getRobotPosition(vector<Bot>& position){
    int x = 3;
    int y = 0;
    Bot CurrPos(x, y);
    position.push_back(CurrPos);
}
void getDistanceFromTarget(vector<Bot>& position, vector<Target>& targets){
    double distance;
    for (int i = 0; i < targets.size(); i++){
        if (position.size() >= 1){
        int x = targets[i].getX_Cord() - position[0].getBot_x();
        int y = targets[i].getY_Cord() - position[0].getBot_y();
        distance = sqrt(pow(x, 2) + pow(y, 2));
        targets[i].setDistanceFromBot(round(distance*100.0)/100.0);}
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


int main(){
    srand(time(nullptr)); //Make sure randint is always random
    vector<Bot> position;
    vector<Target> targets;
    generateTargets(targets, 5);
    getRobotPosition(position);
    getDistanceFromTarget(position, targets);
    sortPriorityTarget(targets);
    for (int i = 0; i < targets.size(); i++){
        cout << "======================================" << "\nPriority: " << targets[i].getPriority() << "\nID: " << targets[i].getID() 
        << "\nX Coordinates: " << targets[i].getX_Cord() << "\nY Coordinates: " << targets[i].getY_Cord() << "\nDistance: "
        << targets[i].getDistanceFromBot() << "\n======================================" <<endl;
    }
    return 0;
}
