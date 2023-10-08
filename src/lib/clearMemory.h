#pragma once

#include <SFML/Graphics.hpp>
#include <drawSprite.h>
#include <drawSprite.cpp>

using namespace sf;

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
);