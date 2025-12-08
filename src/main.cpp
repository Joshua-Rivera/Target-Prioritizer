#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

#include "Bot.h"
#include "Target.h"
#include "Calculations.h"
#include "Simulation.h"
#include "Renderer.h"
using namespace std;

// Run utilizing make and then ./sim in terminal!!!!!!!!!!
int main(){
    srand(static_cast<unsigned>(time(nullptr))); //Make sure randint is always random
    vector<Target> targets;
    Bot bot (0,0);
    generateTargets(targets, 5);
    getRobotPosition(bot);
    getDistanceFromTarget(bot, targets);
    sortPriorityTarget(targets);
    cout << "==== TARGET PRIORITIES' (CONSOLE) ====" << endl;
    for (int i = 0; i < targets.size(); i++){
        cout << "======================================" << "\nPriority: " << targets[i].getPriority() << "\nID: " << targets[i].getID() 
        << "\nTarget Coordinates: (" << targets[i].getX_Cord() << ", " << targets[i].getY_Cord() <<  ")\nBot Coordinates: (" << bot.getBot_x() << "," << bot.getBot_y() 
        << ")\nDistance from Target: " << targets[i].getDistanceFromBot() 
        <<"\n======================================" <<endl;
    }
    Simulation sim(bot, targets);
    int tileSize = 32;
    int minCoord = -10;
    int maxCoord = 10;
    int gridSize = maxCoord - minCoord + 1;
    unsigned int windowWidth  = gridSize * tileSize;
    unsigned int windowHeight = gridSize * tileSize;
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "Target Prioritizer");
    Renderer renderer(tileSize, minCoord, maxCoord);
    if (!renderer.loadAssets()) {
        std::cerr << "Failed to load assets!" << std::endl;
        return 1; 
    }
    sf::Clock clock;
    const float stepTime = 0.15f; // Time per simulation step in seconds
    while (window.isOpen()) {
        while (auto eventOpt = window.pollEvent()) {
            const sf::Event& event = *eventOpt;
            if (event.is<sf::Event::Closed>()){
                window.close();}
        }
        if (!sim.isDone() && clock.getElapsedTime().asSeconds() >= stepTime) {
            sim.update();
            clock.restart();
        }
        window.clear();
        renderer.draw(window, bot, targets);
        window.display();
    }
    
    return 0;
}  