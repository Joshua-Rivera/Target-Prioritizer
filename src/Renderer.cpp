#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int tileSize, int minCoord, int maxCoord)
    : tileSize(tileSize), minCoord(minCoord), 
    maxCoord(maxCoord), botSprite(botTexture),
    targetSprite(targetTexture), tileSprite(tileTexture) {}

bool Renderer::loadAssets() {
    if (!botTexture.loadFromFile("assets/standingbot.png")) {
        std::cerr << "Failed to load bot texture!" << std::endl;
        return false;
    }
    if (!targetTexture.loadFromFile("assets/target.png")) {
        std::cerr << "Failed to load target texture!" << std::endl;
        return false;
    }
    if (!tileTexture.loadFromFile("assets/tile.png")) {
        std::cerr << "Failed to load tile texture!" << std::endl;
        return false;
    }

    botSprite.setTexture(botTexture);
    targetSprite.setTexture(targetTexture);
    tileSprite.setTexture(tileTexture);
    return true;
}
sf::Vector2f Renderer::screen(int gridX, int gridY) const {
    int screenX = (gridX - minCoord) * tileSize;
    int screenY = (maxCoord - gridY) * tileSize;
    return sf::Vector2f(static_cast<float>(screenX), static_cast<float>(screenY));
}

void Renderer::draw(sf::RenderWindow& window, const Bot& bot, const std::vector<Target>& targets) {

    for (int y = minCoord; y <= maxCoord; ++y) {
        for (int x = minCoord; x < maxCoord; ++x) {
            tileSprite.setPosition(screen(x, y));
            window.draw(tileSprite);
        }
    }

    for (const auto& target : targets) {
        sf::Vector2f pos = screen(static_cast<int>(target.getX_Cord()), static_cast<int>(target.getY_Cord()));
        targetSprite.setPosition(pos);
        window.draw(targetSprite);
    }

    
    sf::Vector2f botPos = screen(static_cast<int>(bot.getBot_x()), static_cast<int>(bot.getBot_y()));
    botSprite.setPosition(botPos);
    window.draw(botSprite);
}