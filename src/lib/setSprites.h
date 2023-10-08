#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unistd.h>
#include <drawSprite.h>
#include <drawSprite.cpp>

using namespace sf;

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
);

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
);

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
    );