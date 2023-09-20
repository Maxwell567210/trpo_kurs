#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

// rectangle construct
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

    // struct destruct
    ~DrawSprite()
    {
        delete texture;
        delete sprite;
    }
};

// check load file correct
bool loadImageFromFile(Image& Image, std::string path) {
    if (!Image.loadFromFile(path)) return false;
    return true;
}


// main
int main()
{
    const int WIDTH = 1920;
    const int HEIGHT = 1000;
    const std::string RES_PATH = "../../Resource/";

    // create fullscreen window
    RenderWindow window;
    window.create(VideoMode(WIDTH, HEIGHT), "TicTacToe");
    window.setFramerateLimit(60);


    DrawSprite background = DrawSprite( RES_PATH + "images/Background.jpg", Rectangle(0, 0, WIDTH, HEIGHT));
    

    // window out cicle
    while (window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed || event.key.code == Keyboard::Escape) window.close();
            //if(event.type == Event::KeyPressed || event.key.code == Keyboard::R)
        }

        window.clear();
        window.draw(*background.sprite);
        window.display();
    }
}
