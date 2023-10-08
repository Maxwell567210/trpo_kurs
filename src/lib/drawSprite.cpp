#include <drawSprite.h>

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
    ) : x(x), y(y), endX(endX), endY(endY) {}
};


struct DrawSprite {
    sf::Texture* texture;
    sf::RectangleShape* sprite;

    DrawSprite(std::string path, Rectangle rect)
    {
        texture = new sf::Texture;
        texture->loadFromFile(path);
        
        sprite = new sf::RectangleShape;
        sprite->setTexture(texture);
        sprite->setPosition(sf::Vector2f(rect.x, rect.y));
        sprite->setSize(sf::Vector2f(rect.endX- rect.x, rect.endY- rect.y));
    }
};

