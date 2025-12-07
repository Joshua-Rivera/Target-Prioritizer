#pragma once
#include <vector>
#include "Bot.h"
#include "Target.h"


int RandomNumberGenerator(int min, int max);
void generateTargets(std::vector<Target>& targets, int amount);
void getRobotPosition(Bot& bot);
void getDistanceFromTarget(Bot& bot, std::vector<Target>& targets);
void sortPriorityTarget(std::vector<Target>& targets);