#include <iostream>
#include "allocate_deallocate_array.h"

void allocateArrayFill34(int size) {
    if (!validSize(size)) return;

    int *array;
    array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = DEFAULT_ARRAY_FILLING_NUMBER;
    }

    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete array;
}

bool allocateArrayTwoDim(int ***twoDimArray, int sizeX, int sizeY) {
    if (!validSize(sizeX, sizeY)) {
        twoDimArray = nullptr;
        return false;
    }

    *twoDimArray = new int *[sizeX];

    for (int i = 0; i < sizeX; i++) {
        (*twoDimArray)[i] = new int[sizeY];
    }
    return true;
}

bool deallocateArrayTwoDim(int ***twoDimArray, int sizeX, int sizeY) {
    if (!validSize(sizeX, sizeY)) return false;

    for (int i = 0; i < sizeX; i++) {
        delete (*twoDimArray)[i];
    }
    delete *twoDimArray;

    return true;
}

bool deallocateArrayTwoDimLessParameters(int ***twoDimArray, int sizeX) {
    if (!validSize(sizeX)) return false;

    for (int i = 0; i < sizeX; i++) {
        delete (*twoDimArray)[i];
    }
    delete *twoDimArray;

    return true;
}

bool validSize(int size) {
    if (size <= 0) {
        std::cout << DEFAULT_ERROR_MESSAGE << std::endl;
        return false;
    }
    return true;
}

bool validSize(int sizeX, int sizeY) {
    if (sizeX <= 0 || sizeY <= 0) {
        std::cout << DEFAULT_ERROR_MESSAGE << std::endl;
        return false;
    }
    return true;
}

void printTwoDimArray(int**& twoDimArray, int verses, int columns){
    if (!validSize(verses, columns)) return;

    for (int i = 0; i < verses; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << twoDimArray[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void fillAndPrintTwoDimArray(int**& twoDimArray, int verses, int columns) {
    if (!validSize(verses, columns)) return;

    int numberToPlace = 1;
    for (int i = 0; i < verses; ++i) {
        for (int j = 0; j < columns; ++j) {
            twoDimArray[i][j] = numberToPlace++;
        }
    }

    printTwoDimArray(twoDimArray, verses, columns);
}

int main() {
    allocateArrayFill34(6);
    allocateArrayFill34(-1);

    std::cout << std::endl << "Allocation, filling and printing two dim array:" << std::endl;

    int **twoDimensionalArray;
    std::cout << "Checking for wrong size" << std::endl;
    allocateArrayTwoDim(&twoDimensionalArray, 1, -5);

    std::cout << "Further testing" << std::endl;

    allocateArrayTwoDim(&twoDimensionalArray, 5, 3);
    fillAndPrintTwoDimArray(twoDimensionalArray, 5, 3);

    std::cout << "Deallocating and printing deallocated array" << std::endl;

    deallocateArrayTwoDim(&twoDimensionalArray, 5, 3);

    std::cout << std::endl;

    std::cout << "Same process with less parameter deallocation method" << std::endl;

    int **twoDimensionalArray2;
    allocateArrayTwoDim(&twoDimensionalArray2, 5, 3);
    fillAndPrintTwoDimArray(twoDimensionalArray2, 5, 3);

    std::cout << std::endl;

    deallocateArrayTwoDimLessParameters(&twoDimensionalArray2, 5);

    return 0;
}