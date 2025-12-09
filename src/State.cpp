#include "Calculations.h"
#include "Simulation.h"
#include "State.h"
#include <iostream>

State::State(int tileSize, int minCoord, int maxCoord)
    : window(), renderer(tileSize, minCoord, maxCoord), bot(0, 0), targets(),simulation(bot, targets),
      state(SimulationState::RUNNING), tileSize(tileSize), minCoord(minCoord), maxCoord(maxCoord), clock(),
      StepTime(0.15f)
{
    
    int gridSize = maxCoord - minCoord + 1;
    unsigned int windowSize  = gridSize * tileSize;
    window.create(sf::VideoMode({windowSize, windowSize}), "Target Prioritizer");
    if (!renderer.loadAssets()) {
        std::cerr << "Failed to load assets!" << std::endl;
    }
    reset();
}

void State::reset(){
    targets.clear();
    generateTargets(targets, 20);
    getRobotPosition(bot);
    getDistanceFromTarget(bot, targets);
    sortPriorityTarget(targets);
    simulation.resetPlz(bot, targets);
    std::cout << "==== TARGET PRIORITIES' (CONSOLE) ====" << std::endl;
    for (int i = 0; i < targets.size(); i++){
        std::cout << "======================================" << "\nPriority: " << targets[i].getPriority() << "\nID: " << targets[i].getID() 
        << "\nTarget Coordinates: (" << targets[i].getX_Cord() << ", " << targets[i].getY_Cord() <<  ")\nBot Coordinates: (" << bot.getBot_x() << "," << bot.getBot_y() 
        << ")\nDistance from Target: " << targets[i].getDistanceFromBot() 
        <<"\n======================================" << std::endl;
    }
    update();
    state = SimulationState::RUNNING;
    clock.restart();
}
void State::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void State::processEvents(){
    while (auto eventOpt = window.pollEvent()) {
        const sf::Event& event = *eventOpt;
        if (event.is<sf::Event::Closed>()){
            window.close();}

    
    if (auto key = event.getIf<sf::Event::KeyPressed>()) {
    switch(key->code) {
        case (sf::Keyboard::Key::R):
            reset();
            break;
        case (sf::Keyboard::Key::P):
            if (state == SimulationState::RUNNING)
                state = SimulationState::PAUSED;
            else if (state == SimulationState::PAUSED)
                state = SimulationState::RUNNING;
            break;
        default:
            break;
        
    }}
}
}
void State::update(){
    if (state == SimulationState::RUNNING && !simulation.isDone() && clock.getElapsedTime().asSeconds() >= StepTime) {
        simulation.update();
        clock.restart();
    }
}
void State::render(){
    window.clear();
    renderer.draw(window, bot, targets);
    window.display();
}