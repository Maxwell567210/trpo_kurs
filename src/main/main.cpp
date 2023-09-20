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
    const std::string RES_PATH = "../../Resource/images/";

    // create fullscreen window
    RenderWindow window;
    window.create(VideoMode(WIDTH, HEIGHT), "TicTacToe");
    window.setFramerateLimit(60);

    // image resourse
    DrawSprite background = DrawSprite( RES_PATH + "Background.jpg", Rectangle(0, 0, WIDTH, HEIGHT));

    DrawSprite playButton = DrawSprite( RES_PATH + "PLAY.png", Rectangle(1333, 267, 1726, 357));
    DrawSprite resetButton = DrawSprite( RES_PATH + "RESET.png", Rectangle(1333, 267, 1726, 357));

    
    bool isMousePressed = 0;

    // window out cicle
    while (window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed || event.key.code == Keyboard::Escape) window.close();
            //if(event.type == Event::KeyPressed || event.key.code == Keyboard::R)

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if((event.mouseButton.x > 1229) && (event.mouseButton.x < 1829) && (event.mouseButton.y > 222) && (event.mouseButton.y < 422)) 
                    isMousePressed = !isMousePressed;
                }
            }
        }

        window.clear();
        window.draw(*background.sprite);

        if(isMousePressed){

            window.draw(*resetButton.sprite);
        } else{
            window.draw(*playButton.sprite);
        }
        
        window.display();
    }
}
