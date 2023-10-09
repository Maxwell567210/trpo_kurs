#include <ctest.h>
#include <drawSprite.h>
#include <field.h>
#include <setSprites.h>


CTEST(countVerticalLines, ctest) {

    int currentField[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int row = 0;

    int result = countVerticalLines(currentField, row);

    int expected = 12;
    ASSERT_EQUAL(expected, result);
}

CTEST(getNullableField, ctest) {

    int FIELD_SIZE = 10;

    int* result = getNullableField(FIELD_SIZE);

    ASSERT_NOT_NULL(result);

    delete[] result;
}

CTEST(nullifyField, ctest) {

    int FIELD_SIZE = 10;
    int currentField[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    nullifyField(currentField, FIELD_SIZE);

    for (int i = 0; i < FIELD_SIZE; i++) {
        ASSERT_EQUAL(0, currentField[i]);
    }
}

CTEST(countHorizontalLines, ctest) {

    int currentField[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int row = 0;

    int result = countHorizontalLines(currentField, row);

    int expected = 6;
    ASSERT_EQUAL(expected, result);
}

CTEST(countFirstHorizontal, ctest) {

    int currentField[9] = {1, 0, 0, 0, 2, 0, 0, 0, 3};

    int result = countFirstHorizontal(currentField);

    int expected = 6;
    ASSERT_EQUAL(expected, result);
}

CTEST(countSecondHorizontal, ctest) {
    int currentField[9] = {0, 0, 1, 0, 2, 0, 3, 0, 0}; 

    int result = countSecondHorizontal(currentField);

    int expected = 6;
    ASSERT_EQUAL(expected, result);
}

CTEST(foundWinner, ctest) {

    int FIELD_SIZE = 9;
    int currentField[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0};
    bool isPlay = true;

    int result = foundWinner(3, currentField, FIELD_SIZE, isPlay);

    ASSERT_EQUAL(1, result);
    ASSERT_FALSE(isPlay);
}

CTEST(checkClick, ctest) {

    int pressedX = 3;
    int pressedY = 3;
    int xStart = 1;
    int xEnd = 5;
    int yStart = 1;
    int yEnd = 5;

    bool result = checkClick(pressedX, pressedY, xStart, xEnd, yStart, yEnd);

    ASSERT_TRUE(result);
}

CTEST(DrawSpriteConstructor, ctest) {

    std::string path = "Resource/images/cat.png";
    Rectangle rect(10, 20, 50, 60);

    DrawSprite sprite(path, rect);

    ASSERT_NOT_NULL(sprite.texture);
    ASSERT_NOT_NULL(sprite.sprite);
}

CTEST(fillField, ctest) {

    bool currentMove = true;
    int currentField[9] = {0}; 
    int index = 4; 
    int pressedX = 0;
    int pressedY = 0;

    fillField(currentMove, currentField, index, pressedX, pressedY);

    ASSERT_EQUAL(1, currentField[index]);
    ASSERT_FALSE(currentMove);
    ASSERT_EQUAL(0, pressedX);
    ASSERT_EQUAL(0, pressedY);
}