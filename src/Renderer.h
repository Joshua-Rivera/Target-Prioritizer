#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Target.h"
#include "Bot.h"

class Renderer {
public:
    Renderer(int tileSize, int minCoord, int maxCoord); 
    bool loadAssets();
    void draw(sf::RenderWindow& window, const Bot& bot, const std::vector<Target>& targets);
private:
    int tileSize;
    int minCoord;
    int maxCoord;
    sf::Texture botTexture;
    sf::Texture targetTexture;
    sf::Texture tileTexture;
    sf::Sprite botSprite;
    sf::Sprite targetSprite;
    sf::Sprite tileSprite;
    sf::Vector2f screen(int gridX, int gridY) const;

};