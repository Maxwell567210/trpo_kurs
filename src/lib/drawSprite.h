#pragma once

#include <SFML/Graphics.hpp>
#include <unistd.h>

using namespace sf;

struct Rectangle
{
    int x;
    int y;
    int endX;
    int endY;
    Rectangle(
        int x,
        int y,
        int endX,
        int endY
    ); //: x(x), y(y), endX(endX), endY(endY) {}
};


struct DrawSprite {
    sf::Texture* texture;
    sf::RectangleShape* sprite;

    DrawSprite(std::string path, Rectangle rect);

};