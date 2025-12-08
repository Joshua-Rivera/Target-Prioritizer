#include "Simulation.h"
#include "Calculations.h"
#include <cmath>


Simulation::Simulation(Bot& bot, std::vector<Target>& targets)
    : bot(bot), targets(targets), 
    hasCurrentTarget(false), done(false), 
    stepCount(0), currentTarget(0, 0, 0.0, 0.0) {}

    bool Simulation::isDone() const {
        return done;
    }
    void Simulation::pickNextTarget(){
        if (targets.empty()){
            done = true;
            hasCurrentTarget = false;
            return;
        }
        getDistanceFromTarget(bot, targets);
        sortPriorityTarget(targets);
        currentTarget = targets[0];
        hasCurrentTarget = true;
    }

    void Simulation::moveOneStep(){
        if (!hasCurrentTarget){
            return;
        }
        double bot_x = bot.getBot_x();
        double bot_y = bot.getBot_y();
        double target_x = currentTarget.getX_Cord();
        double target_y = currentTarget.getY_Cord();
        if (bot_x < target_x){
            bot.setBot_x(bot_x + 1.0);
        }else if (bot_x > target_x){
            bot.setBot_x(bot_x - 1.0);
        }
        if (bot_y < target_y){
            bot.setBot_y(bot_y + 1.0);
        }else if (bot_y > target_y){
            bot.setBot_y(bot_y - 1.0);
    } ++stepCount;
}

    void Simulation::update(){
        if (done){
            return;
        }
        if (!hasCurrentTarget){
            pickNextTarget();
        }
        int bot_x = static_cast<int>(round(bot.getBot_x()));
        int bot_y = static_cast<int>(round(bot.getBot_y()));
        int target_x = static_cast<int>(round(currentTarget.getX_Cord()));
        int target_y = static_cast<int>(round(currentTarget.getY_Cord()));
        if (bot_x == target_x && bot_y == target_y){
            if (!targets.empty()){
                targets.erase(targets.begin());
            }
            hasCurrentTarget = false;
            return;
    }moveOneStep();
}