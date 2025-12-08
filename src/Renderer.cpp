#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int tileSize, int minCoord, int maxCoord)
    : tileSize(tileSize), minCoord(minCoord), 
    maxCoord(maxCoord), botSprite(botTexture),
    targetSprite(targetTexture), tileSprite(tileTexture) {}

bool Renderer::loadAssets() {
    bool working = true;

    if (!botTexture.loadFromFile("assets/standingbot.png")) {
        std::cerr << "Failed to load bot texture!" << std::endl;
        working = false;
    }
    if (!targetTexture.loadFromFile("assets/target.png")) {
        std::cerr << "Failed to load target texture!" << std::endl;
        working = false;
    }
    if (!tileTexture.loadFromFile("assets/tile.png")) {
        std::cerr << "Failed to load tile texture!" << std::endl;
        working = false;
    }

    if (!working) {
        return false; 
    }
    botSprite.setTexture(botTexture);
    targetSprite.setTexture(targetTexture);
    tileSprite.setTexture(tileTexture);

    botSprite.setOrigin(sf::Vector2f(
        botTexture.getSize().x / 2.f,
        botTexture.getSize().y / 2.f
    ));
    targetSprite.setOrigin(sf::Vector2f(
        targetTexture.getSize().x / 2.f,
        targetTexture.getSize().y / 2.f
    ));
    tileSprite.setOrigin(sf::Vector2f(0.f, 0.f));
    float botScaleX    = static_cast<float>(tileSize) / botTexture.getSize().x;
    float botScaleY    = static_cast<float>(tileSize) / botTexture.getSize().y;
    float targetScaleX = static_cast<float>(tileSize) / targetTexture.getSize().x;
    float targetScaleY = static_cast<float>(tileSize) / targetTexture.getSize().y;
    float tileScaleX   = static_cast<float>(tileSize) / tileTexture.getSize().x;
    float tileScaleY   = static_cast<float>(tileSize) / tileTexture.getSize().y;

    botSprite.setScale(sf::Vector2f(botScaleX, botScaleY));
    targetSprite.setScale(sf::Vector2f(targetScaleX, targetScaleY));
    tileSprite.setScale(sf::Vector2f(tileScaleX, tileScaleY));

    return true;
}
sf::Vector2f Renderer::screen(int gridX, int gridY) const {
    int screenX = (gridX - minCoord) * tileSize;
    int screenY = (maxCoord - gridY) * tileSize;
    return sf::Vector2f(static_cast<float>(screenX), 
    static_cast<float>(screenY));
}

void Renderer::draw(sf::RenderWindow& window, const Bot& bot, const std::vector<Target>& targets) {

    for (int y = minCoord; y <= maxCoord; ++y) {
        for (int x = minCoord; x <= maxCoord; ++x) {
            tileSprite.setPosition(screen(x, y));
            window.draw(tileSprite);
        }
    }

    for (const auto& target : targets) {
        sf::Vector2f pos = screen(static_cast<int>(target.getX_Cord()), 
        static_cast<int>(target.getY_Cord()));
        targetSprite.setPosition(pos);
        window.draw(targetSprite);
        sf::CircleShape targetCircle(6.f);  // radius = 6 px
        targetCircle.setFillColor(sf::Color::Green);
        targetCircle.setOrigin(sf::Vector2f(6.f, 6.f)); // center the circle
        targetCircle.setPosition(pos);
        window.draw(targetCircle);

    }

    sf::Vector2f botPos = screen(static_cast<int>(bot.getBot_x()), 
    static_cast<int>(bot.getBot_y()));
    botSprite.setPosition(botPos);
    window.draw(botSprite);
    sf::CircleShape botCircle(8.f);
    botCircle.setFillColor(sf::Color::Red);
    botCircle.setOrigin(sf::Vector2f(8.f, 8.f));
    botCircle.setPosition(botPos);
    window.draw(botCircle);

}