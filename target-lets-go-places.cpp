#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Target{
private:
    int id;
    int priority;
    double x_cord;
    double y_cord;
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
    //Getters
    int getID(){return id;}
    int getPriority() {return priority;}
    double getX_Cord() {return x_cord;}
    double getY_cord() {return y_cord;}
    double getDistanceFromBot() {return distanceFromBot;}

    //Functions
    void generateTargets(vector<Target>& targets, int amount);
};


int main(){
    srand(time(nullptr)); //Make sure randint is always random
    vector<Target> targets;

    return 0;
}

int RandomNumberGenerator(int min, int max){
     
    return min + rand() % (max - min + 1);
}

void Target::generateTargets(vector<Target>& targets, int amount){
    int i = 1;
    while (i <= amount){
        int x = RandomNumberGenerator(-10, 10);
        setX_cord(x);
        int y = RandomNumberGenerator(-10, 10);
        setY_cord(y);
        i++;
    }
}


