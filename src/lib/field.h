#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>

using namespace sf;

void fillField(bool &currentMove, int currentField[], int index, int &pressedX, int &pressedY);

int* getNullableField(int FIELD_SIZE);

void nullifyField(int* currentField, int FIELD_SIZE);

int countVerticalLines(int* currentField, int row);

int countHorizontalLines(int* currentField, int row);

int countFirstHorizontal(int* currentField);

int countSecondHorizontal(int* currentField);

int foundWinner(int counter, int* currentField, int FIELD_SIZE, bool &isPlay);

bool checkClick(int pressedX, int pressedY, int xStart, int xEnd, int yStart, int yEnd);