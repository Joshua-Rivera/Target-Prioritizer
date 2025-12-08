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
    sf::Texture botTexture{"assets/derechabot.png"};
    sf::Texture bot2Texture{"assets/derechabot.png"};
    sf::Texture bot3Texture{"assets/izquierdabot.png"};
    sf::Texture targetTexture{"assets/target.png"};
    sf::Texture tileTexture{"assets/tile.png"};
    sf::Sprite botSprite{botTexture};
    sf::Sprite bot2Sprite{bot2Texture};
    sf::Sprite bot3Sprite{bot3Texture};
    sf::Sprite targetSprite{targetTexture};
    sf::Sprite tileSprite{tileTexture};
    sf::Vector2f screen(int gridX, int gridY) const;

};