#include <clearMemory.h>

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