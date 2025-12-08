#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bot.h"
#include "Target.h"
#include "Renderer.h"
#include "Simulation.h"


enum class SimulationState {
    RUNNING,
    PAUSED,
};

class State {
public:
    State(int tileSize, int minCoord, int maxCoord);
    void run();
private:
    void processEvents();
    void update();
    void render();
    void reset();
    sf::RenderWindow window;
    Renderer renderer;
    Bot bot;
    std::vector<Target> targets;
    Simulation simulation;
    SimulationState state;
    int tileSize;
    int minCoord;
    int maxCoord;
    sf::Clock clock;
    float StepTime = 0.15f; //step time of the bot
};