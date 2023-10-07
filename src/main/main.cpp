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

void nullifyField(int* currentField, int FIELD_SIZE){
    for(int i = 0; i < FIELD_SIZE; i++) currentField[i] = 0;
}


int countVerticalLines(int* currentField, int row) {
    int counter = 0;

    for (int j = 0; j < 3; j++) {
        counter += currentField[j * 3 + row];
    }

    return counter;
}

int countHorizontalLines(int* currentField, int row) {
    int counter = 0;

    for (int j = 0; j < 3; j++) {
        counter += currentField[row * 3 + j];
    }

    return counter;
}

int countFirstHorizontal(int* currentField){
    return (currentField[0] + currentField[4] + currentField[8]);
}

int countSecondHorizontal(int* currentField){
    return (currentField[2] + currentField[4] + currentField[6]);
}

int foundWinner(int counter, int* currentField, int FIELD_SIZE, bool &isPlay){
         
    nullifyField(currentField, FIELD_SIZE);
    isPlay = !isPlay;

    if(counter == 3) 
        return 1;
    if(counter == -3)
        return -1;

    return 0;
}


bool checkClick(int pressedX, int pressedY, int xStart, int xEnd, int yStart, int yEnd){
    if((pressedX > xStart) && (pressedX < xEnd) && (pressedY > yStart) && (pressedY < yEnd))
        return 1;
    else
        return 0;
}


sf::RectangleShape getSpriteCat(
    int index,
    DrawSprite pos0Cat,
    DrawSprite pos1Cat,
    DrawSprite pos2Cat,
    DrawSprite pos3Cat,
    DrawSprite pos4Cat,
    DrawSprite pos5Cat,
    DrawSprite pos6Cat,
    DrawSprite pos7Cat,
    DrawSprite pos8Cat
) {
    switch (index)
    {
    case 0:
        return *pos0Cat.sprite;
    case 1:
        return *pos1Cat.sprite;
    case 2:
        return *pos2Cat.sprite;
    case 3:
        return *pos3Cat.sprite;
    case 4:
        return *pos4Cat.sprite;
    case 5:
        return *pos5Cat.sprite;
    case 6:
        return *pos6Cat.sprite;
    case 7:
        return *pos7Cat.sprite;
    case 8:
        return *pos8Cat.sprite;
    }

    return *pos0Cat.sprite;
}


sf::RectangleShape getSpriteLove(
    int index,
    DrawSprite pos0Love,
    DrawSprite pos1Love,
    DrawSprite pos2Love,
    DrawSprite pos3Love,
    DrawSprite pos4Love,
    DrawSprite pos5Love,
    DrawSprite pos6Love,
    DrawSprite pos7Love,
    DrawSprite pos8Love
) {
    switch (index)
    {
    case 0:
        return *pos0Love.sprite;
    case 1:
        return *pos1Love.sprite;
    case 2:
        return *pos2Love.sprite;
    case 3:
        return *pos3Love.sprite;
    case 4:
        return *pos4Love.sprite;
    case 5:
        return *pos5Love.sprite;
    case 6:
        return *pos6Love.sprite;
    case 7:
        return *pos7Love.sprite;
    case 8:
        return *pos8Love.sprite;
    }

    return *pos0Love.sprite;
}


void drawOutSprites(
    int* currentField,
    RenderWindow &window,
    int FIELD_SIZE,

    DrawSprite pos0Cat,
    DrawSprite pos0Love,

    DrawSprite pos1Cat,
    DrawSprite pos1Love,

    DrawSprite pos2Cat,
    DrawSprite pos2Love,

    DrawSprite pos3Cat,
    DrawSprite pos3Love,

    DrawSprite pos4Cat,
    DrawSprite pos4Love,

    DrawSprite pos5Cat,
    DrawSprite pos5Love,

    DrawSprite pos6Cat,
    DrawSprite pos6Love,

    DrawSprite pos7Cat,
    DrawSprite pos7Love,

    DrawSprite pos8Cat,
    DrawSprite pos8Love
    ){
    for(int index = 0; index < FIELD_SIZE; index++){

        if(currentField[index] == 1){

            window.draw(getSpriteCat(index, pos0Cat, pos1Cat, pos2Cat, pos3Cat, pos4Cat, pos5Cat, pos6Cat, pos7Cat, pos8Cat));
        }

        if(currentField[index] == -1){

            window.draw(getSpriteLove(index, pos0Love, pos1Love, pos2Love, pos3Love, pos4Love, pos5Love, pos6Love, pos7Love, pos8Love));
        }
    }
}


void clearMemory(
    DrawSprite background,
    DrawSprite playButton,
    DrawSprite resetButton,
    DrawSprite BigCatCurrent,
    DrawSprite BigLoveCurrent,
    DrawSprite catsWins,
    DrawSprite loveWins,

    DrawSprite pos0Cat,
    DrawSprite pos1Cat,
    DrawSprite pos2Cat,
    DrawSprite pos3Cat,
    DrawSprite pos4Cat,
    DrawSprite pos5Cat,
    DrawSprite pos6Cat,
    DrawSprite pos7Cat,
    DrawSprite pos8Cat,

    DrawSprite pos0Love,
    DrawSprite pos1Love,
    DrawSprite pos2Love,
    DrawSprite pos3Love,
    DrawSprite pos4Love,
    DrawSprite pos5Love,
    DrawSprite pos6Love,
    DrawSprite pos7Love,
    DrawSprite pos8Love,
    int* currentField
){
    delete background.sprite;
    delete background.texture;
    
    delete playButton.sprite;
    delete playButton.texture;

    delete resetButton.sprite;
    delete resetButton.texture;

    delete BigCatCurrent.sprite;
    delete BigCatCurrent.texture;

    delete BigLoveCurrent.sprite;
    delete BigLoveCurrent.texture;

    delete catsWins.sprite;
    delete catsWins.texture;

    delete loveWins.sprite;
    delete loveWins.texture;

    delete pos0Cat.sprite;
    delete pos0Cat.texture;

    delete pos1Cat.sprite;
    delete pos1Cat.texture;

    delete pos2Cat.sprite;
    delete pos2Cat.texture;

    delete pos3Cat.sprite;
    delete pos3Cat.texture;

    delete pos4Cat.sprite;
    delete pos4Cat.texture;

    delete pos5Cat.sprite;
    delete pos5Cat.texture;

    delete pos6Cat.sprite;
    delete pos6Cat.texture;

    delete pos7Cat.sprite;
    delete pos7Cat.texture;

    delete pos8Cat.sprite;
    delete pos8Cat.texture;

    delete pos0Love.sprite;
    delete pos0Love.texture;

    delete pos1Love.sprite;
    delete pos1Love.texture;

    delete pos2Love.sprite;
    delete pos2Love.texture;

    delete pos3Love.sprite;
    delete pos3Love.texture;

    delete pos4Love.sprite;
    delete pos4Love.texture;

    delete pos5Love.sprite;
    delete pos5Love.texture;

    delete pos6Love.sprite;
    delete pos6Love.texture;

    delete pos7Love.sprite;
    delete pos7Love.texture;

    delete pos8Love.sprite;
    delete pos8Love.texture;

    delete[] currentField;
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

                    if(checkClick(pressedX, pressedY, 1229, 1829, 222, 422)) isPlay = !isPlay;

                }
            }
        }


        window.clear();
        window.draw(*background.sprite);

        // field click listener
        if(isPlay && (checkWin == 0)){

            window.draw(*resetButton.sprite);

            if(currentMove)
                window.draw(*BigCatCurrent.sprite); 
            else
                window.draw(*BigLoveCurrent.sprite);


            int index = 0;

            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON, 
            X_BASE_BUTTON + BUTTON_WIDHT, 
            Y_BASE_BUTTON, 
            Y_BASE_BUTTON + BUTTON_WIDHT) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON + BUTTON_WIDHT, 
            X_BASE_BUTTON + BUTTON_WIDHT * 2, 
            Y_BASE_BUTTON, 
            Y_BASE_BUTTON + BUTTON_WIDHT) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON + BUTTON_WIDHT * 2, 
            X_BASE_BUTTON + BUTTON_WIDHT * 3, 
            Y_BASE_BUTTON, 
            Y_BASE_BUTTON + BUTTON_WIDHT) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON, 
            X_BASE_BUTTON + BUTTON_WIDHT, 
            Y_BASE_BUTTON + BUTTON_WIDHT, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 2) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON + BUTTON_WIDHT, 
            X_BASE_BUTTON + BUTTON_WIDHT * 2, 
            Y_BASE_BUTTON + BUTTON_WIDHT, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 2) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON + BUTTON_WIDHT * 2, 
            X_BASE_BUTTON + BUTTON_WIDHT * 3, 
            Y_BASE_BUTTON + BUTTON_WIDHT, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 2) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON, 
            X_BASE_BUTTON + BUTTON_WIDHT, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 2, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 3) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON + BUTTON_WIDHT, 
            X_BASE_BUTTON + BUTTON_WIDHT * 2, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 2, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 3) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;


            if(checkClick(
            pressedX, 
            pressedY, 
            X_BASE_BUTTON + BUTTON_WIDHT * 2, 
            X_BASE_BUTTON + BUTTON_WIDHT * 3, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 2, 
            Y_BASE_BUTTON + BUTTON_WIDHT * 3) 
            && currentField[index] == 0)
                fillField(currentMove, currentField, index, pressedX, pressedY);

            index++;

            
        } else{

            window.draw(*playButton.sprite);

            nullifyField(currentField, FIELD_SIZE);
        }


        // print winner menu
        if(checkWin){
            
            if(checkWin == 1){
                window.draw(*catsWins.sprite);
            }

            if(checkWin == -1){
                window.draw(*loveWins.sprite);
            }
            
            if(checkClick(pressedX, pressedY, 0, 1920, 0, 1000)) checkWin = 0;
        }

        // draw sprites

        drawOutSprites(
            currentField, window, FIELD_SIZE,
            pos0Cat, pos0Love,
            pos1Cat, pos1Love,
            pos2Cat, pos2Love,
            pos3Cat, pos3Love,
            pos4Cat, pos4Love,
            pos5Cat, pos5Love,
            pos6Cat, pos6Love,
            pos7Cat, pos7Love,
            pos8Cat, pos8Love
        );


        // check winner
        for(int i = 0; i < 3; i++){
            
            int counter = countVerticalLines(currentField, i);

            if((counter == 3) || (counter == -3)){
                checkWin = foundWinner(counter, currentField, FIELD_SIZE, isPlay);
                break;
            }
        }


        for(int i = 0; i < 3; i++){
            
            int counter = countHorizontalLines(currentField, i);

            if((counter == 3) || (counter == -3)){
                checkWin = foundWinner(counter, currentField, FIELD_SIZE, isPlay);
                break;
            }
        }


        int countFirstHorizont = countFirstHorizontal(currentField);
        int countSecondHorizont = countSecondHorizontal(currentField);


        if((countFirstHorizont == 3) || (countFirstHorizont == -3))
            checkWin = foundWinner(countFirstHorizont, currentField, FIELD_SIZE, isPlay);


        if((countSecondHorizont == 3) || (countSecondHorizont == -3))
            checkWin = foundWinner(countSecondHorizont, currentField, FIELD_SIZE, isPlay);

        
        window.display();
    }
    
    clearMemory(
        background, playButton, resetButton, BigCatCurrent, BigLoveCurrent, catsWins, loveWins,
        pos0Cat,
        pos1Cat,
        pos2Cat,
        pos3Cat,
        pos4Cat,
        pos5Cat,
        pos6Cat,
        pos7Cat,
        pos8Cat,

        pos0Love,
        pos1Love,
        pos2Love,
        pos3Love,
        pos4Love,
        pos5Love,
        pos6Love,
        pos7Love,
        pos8Love,

        currentField
    );
    
}
