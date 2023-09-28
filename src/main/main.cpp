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

    const int BUTTON_WIDHT = 322;
    const int X_BASE_BUTTON = 138;
    const int Y_BASE_BUTTON = 65;

    const int X_EL_POSITION = X_BASE_BUTTON + 75;
    const int Y_EL_POSITION = Y_BASE_BUTTON + 60;
    const int CORRECT_Y = 45;

    const int IMAGE_SIZE = 180;

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

    // 9 sprites of cat load
    DrawSprite pos0Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION, 
        Y_EL_POSITION, 
        X_EL_POSITION + IMAGE_SIZE, 
        Y_EL_POSITION + IMAGE_SIZE));
    DrawSprite pos1Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT, 
        Y_EL_POSITION, 
        X_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE, 
        Y_EL_POSITION + IMAGE_SIZE));
    DrawSprite pos2Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT * 2, 
        Y_EL_POSITION, 
        X_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE, 
        Y_EL_POSITION + IMAGE_SIZE));


    DrawSprite pos3Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION, 
        Y_EL_POSITION + BUTTON_WIDHT - CORRECT_Y, 
        X_EL_POSITION + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos4Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT, 
        Y_EL_POSITION + BUTTON_WIDHT - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos5Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT * 2, 
        Y_EL_POSITION + BUTTON_WIDHT - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE - CORRECT_Y));


    DrawSprite pos6Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 - CORRECT_Y, 
        X_EL_POSITION + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos7Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos8Cat = DrawSprite(RES_PATH + "cat.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT * 2, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE - CORRECT_Y));



    // 9 sprites of hurt load
    DrawSprite pos0Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION, 
        Y_EL_POSITION, 
        X_EL_POSITION + IMAGE_SIZE, 
        Y_EL_POSITION + IMAGE_SIZE));
    DrawSprite pos1Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT, 
        Y_EL_POSITION, 
        X_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE, 
        Y_EL_POSITION + IMAGE_SIZE));
    DrawSprite pos2Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT * 2, 
        Y_EL_POSITION, 
        X_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE, 
        Y_EL_POSITION + IMAGE_SIZE));


    DrawSprite pos3Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION, 
        Y_EL_POSITION + BUTTON_WIDHT - CORRECT_Y, 
        X_EL_POSITION + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos4Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT, 
        Y_EL_POSITION + BUTTON_WIDHT - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos5Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT * 2, 
        Y_EL_POSITION + BUTTON_WIDHT - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE - CORRECT_Y));


    DrawSprite pos6Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 - CORRECT_Y, 
        X_EL_POSITION + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos7Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE - CORRECT_Y));
    DrawSprite pos8Love = DrawSprite(RES_PATH + "love.png", Rectangle
        (X_EL_POSITION + BUTTON_WIDHT * 2, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 - CORRECT_Y, 
        X_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE, 
        Y_EL_POSITION + BUTTON_WIDHT * 2 + IMAGE_SIZE - CORRECT_Y));


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
            if(currentMove){
                window.draw(*BigCatCurrent.sprite);
            } else {
                window.draw(*BigLoveCurrent.sprite);
            }

            if((pressedX > X_BASE_BUTTON)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY > Y_BASE_BUTTON)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT)
            && currentField[0] == 0){
                if(currentMove){
                    currentField[0] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[0] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY > Y_BASE_BUTTON)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT)
            && currentField[1] == 0){
                if(currentMove){
                    currentField[1] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[1] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 3)
            && (pressedY > Y_BASE_BUTTON)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT)
            && currentField[2] == 0){
                if(currentMove){
                    currentField[2] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[2] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && currentField[3] == 0){
                if(currentMove){
                    currentField[3] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[3] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && currentField[4] == 0){
                if(currentMove){
                    currentField[4] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[4] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 3)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && currentField[5] == 0){
                if(currentMove){
                    currentField[5] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[5] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 3)
            && currentField[6] == 0){
                if(currentMove){
                    currentField[6] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[6] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 3)
            && currentField[7] == 0){
                if(currentMove){
                    currentField[7] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[7] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 3)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 3)
            && currentField[8] == 0){
                if(currentMove){
                    currentField[8] = 1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                } else{
                    currentField[8] = -1;
                    currentMove = !currentMove;

                    pressedX = 0;
                    pressedY = 0;
                }
            }

            
        } else{
            window.draw(*playButton.sprite);

            for(int i = 0; i < 9; i++) currentField[i] = 0;
        }

        if(currentField[0] == 1){
            window.draw(*pos0Cat.sprite);
        }
        if(currentField[0] == -1){
            window.draw(*pos0Love.sprite);
        }

        if(currentField[1] == 1){
            window.draw(*pos1Cat.sprite);
        }
        if(currentField[1] == -1){
            window.draw(*pos1Love.sprite);
        }

        if(currentField[2] == 1){
            window.draw(*pos2Cat.sprite);
        }
        if(currentField[2] == -1){
            window.draw(*pos2Love.sprite);
        }

        if(currentField[3] == 1){
            window.draw(*pos3Cat.sprite);
        }
        if(currentField[3] == -1){
            window.draw(*pos3Love.sprite);
        }

        if(currentField[4] == 1){
            window.draw(*pos4Cat.sprite);
        }
        if(currentField[4] == -1){
            window.draw(*pos4Love.sprite);
        }

        if(currentField[5] == 1){
            window.draw(*pos5Cat.sprite);
        }
        if(currentField[5] == -1){
            window.draw(*pos5Love.sprite);
        }

        if(currentField[6] == 1){
            window.draw(*pos6Cat.sprite);
        }
        if(currentField[6] == -1){
            window.draw(*pos6Love.sprite);
        }

        if(currentField[7] == 1){
            window.draw(*pos7Cat.sprite);
        }
        if(currentField[7] == -1){
            window.draw(*pos7Love.sprite);
        }
        
        if(currentField[8] == 1){
            window.draw(*pos8Cat.sprite);
        }
        if(currentField[8] == -1){
            window.draw(*pos8Love.sprite);
        }

        for(int i = 0; i < 3; i++){
            int counter = 0;

            for(int j = 0; j < 3; j++){
                
                counter += currentField[i * 3 + j];
            }

            if(counter == 3){
                for(int k = 0; k < 9; k++) currentField[k] = 0;
                isPlay = !isPlay;
            } else if(counter == -3){
                for(int k = 0; k < 9; k++) currentField[k] = 0;
                isPlay = !isPlay;
            }
        }

        for(int i = 0; i < 3; i++){
            int counter = 0;

            for(int j = 0; j < 3; j++){
                
                counter += currentField[j * 3 + i];
            }

            if(counter == 3){
                for(int k = 0; k < 9; k++) currentField[k] = 0;
                isPlay = !isPlay;
            } else if(counter == -3){
                for(int k = 0; k < 9; k++) currentField[k] = 0;
                isPlay = !isPlay;
            }
        }

        if((currentField[0] + currentField[4] + currentField[8]) == 3){

            for(int k = 0; k < 9; k++) currentField[k] = 0;
            isPlay = !isPlay;
        } else if((currentField[0] + currentField[4] + currentField[8]) == -3){

            for(int k = 0; k < 9; k++) currentField[k] = 0;
            isPlay = !isPlay;
        }

        if((currentField[2] + currentField[4] + currentField[6]) == 3){

            for(int k = 0; k < 9; k++) currentField[k] = 0;
            isPlay = !isPlay;
        } else if((currentField[2] + currentField[4] + currentField[6]) == -3){

            for(int k = 0; k < 9; k++) currentField[k] = 0;
            isPlay = !isPlay;
        }
        
        window.display();
    }
}
