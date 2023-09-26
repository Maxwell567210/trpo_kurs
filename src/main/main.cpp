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
    const int XRECT = 138;
    const int YRECT = 60;

    const int X_EL_POSITION = XRECT + 75;
    const int Y_EL_POSITION = YRECT + 60;

    // create fullscreen window
    RenderWindow window;
    window.create(VideoMode(WIDTH, HEIGHT), "TicTacToe");
    window.setFramerateLimit(60);

    // image resourse
    DrawSprite background = DrawSprite( RES_PATH + "Background.jpg", Rectangle(0, 0, WIDTH, HEIGHT));

    DrawSprite playButton = DrawSprite( RES_PATH + "PLAY.png", Rectangle(1333, 267, 1726, 357));
    DrawSprite resetButton = DrawSprite( RES_PATH + "RESET.png", Rectangle(1333, 267, 1726, 357));

    DrawSprite BigCatCurrent = DrawSprite( RES_PATH + "BigCat.png", Rectangle(1374, 596, 1694, 900));
    DrawSprite BigLoveCurrent = DrawSprite( RES_PATH + "BigLove.png", Rectangle(1374, 596, 1694, 900));

    DrawSprite pos0Cat = DrawSprite(RES_PATH + "cat.png", Rectangle(X_EL_POSITION, Y_EL_POSITION, X_EL_POSITION + 180, Y_EL_POSITION + 180));

    DrawSprite pos0Love = DrawSprite(RES_PATH + "love.png", Rectangle(X_EL_POSITION, Y_EL_POSITION, X_EL_POSITION + 180, Y_EL_POSITION + 180));


    bool currentMove = 1;
    bool isPlay = 0;

    int pressedX;
    int pressedY;

    int currentField[9];
    for(int i = 0; i < 9; i++) currentField[i] = 0;

    // window out cicle
    while (window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed || event.key.code == Keyboard::Escape) window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    pressedX = event.mouseButton.x;
                    pressedY = event.mouseButton.y;

                    if((pressedX > 1229) && (pressedX < 1829) && (pressedY > 222) && (pressedY < 422)) isPlay = !isPlay;


                }
            }
        }


        window.clear();
        window.draw(*background.sprite);

        if(isPlay){
            window.draw(*resetButton.sprite);

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386) && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = 2;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            // if(currentMove){
            //     window.draw(*BigCatCurrent.sprite);

            //     if((pressedX > 138) && (pressedX < 460) && (pressedY > 65) && (pressedY < 386)){
            //         currentField[0] = 1;
            //         currentMove = !currentMove;
            //     }

            // } else{
            //     window.draw(*BigLoveCurrent.sprite);
            // }

            
        } else{
            window.draw(*playButton.sprite);

            for(int i = 0; i < 9; i++) currentField[i] = 0;
        }

        if(currentField[0] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[0] == 2){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[1] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[1] == 2){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[2] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[2] == 2){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[3] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[3] == 2){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[4] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[4] == 2){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[5] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[5] == 2){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[6] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[6] == 2){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[7] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[7] == 2){
            window.draw(*pos0Love.sprite);
        }
        
        if(currentField[8] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[8] == 2){
            window.draw(*pos0Love.sprite);
        }
        
        window.display();
    }
}
