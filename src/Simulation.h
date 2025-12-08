#pragma once
#include <vector>
#include "Bot.h"
#include "Target.h"

class Simulation{
public:
    Simulation(Bot& bot, std::vector<Target>& targets);
    void update();
    bool isDone() const;
private:
    Bot& bot;
    std::vector<Target>& targets;
    bool hasCurrentTarget;
    bool done;
    int stepCount;
    Target currentTarget;
    void pickNextTarget();
    void moveOneStep();
};