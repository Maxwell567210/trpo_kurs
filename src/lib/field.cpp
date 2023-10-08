#include <field.h>


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