#include <drawSprite.h>
#include <createWindow.h>
#include <setSprites.h>
#include <field.h>
#include <clearMemory.h>

using namespace sf;


// main
int main()
{
    // init consts
    const String NAME_GAME = "TicTacToe";
    const int WIDTH = 1920;
    const int HEIGHT = 1000;
    const std::string RES_PATH = "Resource/images/";

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
