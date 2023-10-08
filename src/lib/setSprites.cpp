#include <setSprites.h>

RectangleShape getSpriteCat(
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


RectangleShape getSpriteLove(
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