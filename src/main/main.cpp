#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <unistd.h>

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


void createWindow(RenderWindow &window, int WIDTH, int HEIGHT, String NAME_GAME) {

    window.create(sf::VideoMode(WIDTH, HEIGHT), NAME_GAME);
    window.setFramerateLimit(60);

}


void fillField(bool &currentMove, int currentField[], int index, int &pressedX, int &pressedY){
    if(currentMove){
        currentField[index] = 1;
        currentMove = !currentMove;

        pressedX = 0;
        pressedY = 0;
    } else{
        currentField[index] = -1;
        currentMove = !currentMove;

        pressedX = 0;
        pressedY = 0;
    }
}

int* getNullableField(int FIELD_SIZE) {
    int* currentField = new int[FIELD_SIZE];
    for (int i = 0; i < FIELD_SIZE; i++) {
        currentField[i] = 0;
    }
    return currentField;
}


// main
int main()
{
    // init consts
    const String NAME_GAME = "TicTacToe";
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

    const int FIELD_SIZE = 9;


    // init default values
    bool currentMove = 1;
    bool isPlay = 0;

    int pressedX;
    int pressedY;

    int* currentField = getNullableField(FIELD_SIZE);

    int checkWin = 0;

    String cat0 = "*pos0Cat.sprite";


    // create window
    RenderWindow window;
    createWindow(window, WIDTH, HEIGHT, NAME_GAME);


    // image resourses
    DrawSprite background = DrawSprite( RES_PATH + "Background.jpg", Rectangle(0, 0, WIDTH, HEIGHT));
    DrawSprite playButton = DrawSprite( RES_PATH + "PLAY.png", Rectangle(1333, 267, 1726, 357));
    DrawSprite resetButton = DrawSprite( RES_PATH + "RESET.png", Rectangle(1333, 267, 1726, 357));
    DrawSprite BigCatCurrent = DrawSprite( RES_PATH + "BigCat.png", Rectangle(1374, 596, 1694, 900));
    DrawSprite BigLoveCurrent = DrawSprite( RES_PATH + "BigLove.png", Rectangle(1374, 596, 1694, 900));
    DrawSprite catsWins = DrawSprite( RES_PATH + "cats_win.png", Rectangle(486, 260, 1486, 760));
    DrawSprite loveWins = DrawSprite( RES_PATH + "love_win.png", Rectangle(486, 260, 1486, 760));


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


    // window loop
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


        if(isPlay && (checkWin == 0)){

            window.draw(*resetButton.sprite);

            if(currentMove)
                window.draw(*BigCatCurrent.sprite); 
            else
                window.draw(*BigLoveCurrent.sprite);


            int index = 0;

            if((pressedX > X_BASE_BUTTON)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY > Y_BASE_BUTTON)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);
            
            index++;

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY > Y_BASE_BUTTON)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 3)
            && (pressedY > Y_BASE_BUTTON)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            if((pressedX > X_BASE_BUTTON)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 3)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            if((pressedX > X_BASE_BUTTON)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 3)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 3)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            if((pressedX > X_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedX < X_BASE_BUTTON + BUTTON_WIDHT * 3)
            && (pressedY > Y_BASE_BUTTON + BUTTON_WIDHT * 2)
            && (pressedY < Y_BASE_BUTTON + BUTTON_WIDHT * 3)
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            
        } else{

            window.draw(*playButton.sprite);

            for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
        }

        if(checkWin){
            
            if(checkWin == 1){
                window.draw(*catsWins.sprite);
            }

            if(checkWin == -1){
                window.draw(*loveWins.sprite);
            }

            if((pressedX > 0) && (pressedX < 1920) && (pressedY > 0) && (pressedY < 1000)) checkWin = 0;
        }

        if(currentField[0] == 1){
            window.draw(cat0);
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
                checkWin = 1;
            
                for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
                isPlay = !isPlay;
                break;

            } else if(counter == -3){
                checkWin = -1;
                
                for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
                isPlay = !isPlay;
                break;
            }
        }


        for(int i = 0; i < 3; i++){
            int counter = 0;

            for(int j = 0; j < 3; j++){
                
                counter += currentField[j * 3 + i];
            }

            if(counter == 3){
                checkWin = 1;
            
                for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
                isPlay = !isPlay;
                break;

            } else if(counter == -3){
                checkWin = -1;
            
                for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
                isPlay = !isPlay;
                break;
            }
        }

        if((currentField[0] + currentField[4] + currentField[8]) == 3){

            checkWin = 1;
            
            for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
            isPlay = !isPlay;

        } else if((currentField[0] + currentField[4] + currentField[8]) == -3){

            checkWin = -1;
            
            for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
            isPlay = !isPlay;
        }

        if((currentField[2] + currentField[4] + currentField[6]) == 3){

            checkWin = 1;
            
            for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
            isPlay = !isPlay;

        } else if((currentField[2] + currentField[4] + currentField[6]) == -3){

            checkWin = -1;
            
            for(int k = 0; k < FIELD_SIZE; k++) currentField[k] = 0;
            isPlay = !isPlay;

        }
        
        window.display();
    }

    delete[] currentField;
}
