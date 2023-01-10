//
// Created by Dawid on 01.01.2023.
//

#include <fstream>
#include <vector>
#include "KnapsackProblem.h"

KnapsackProblem::KnapsackProblem() {
    capacity = 0;
    numberOfItems = 0;
    weights = new int[0];
    weightsLength = 0;
    values = new int[0];
    valuesLength = 0;
}

bool KnapsackProblem::checkWeights(int *weights, unsigned int weightsLength, unsigned int numberOfItems) {
    for (int i = 0; i < weightsLength; ++i) {
        if (weights[i] <= 0) return false;
    }
    return weightsLength == numberOfItems;
}

bool KnapsackProblem::checkValues(int *values, unsigned int valuesLength, unsigned int numberOfItems) {
    for (int i = 0; i < valuesLength; ++i) {
        if (values[i] <= 0) return false;
    }
    return valuesLength == numberOfItems;
}

bool
KnapsackProblem::checkAll(unsigned int capacity, unsigned int numberOfItems, int *weights, unsigned int weightsLength,
                          int *values,
                          unsigned int valuesLength) {
    return capacity != 0 && numberOfItems != 0 && checkWeights(weights, weightsLength, numberOfItems) &&
           checkValues(values, valuesLength, numberOfItems);
}

void KnapsackProblem::setKnapsackProblem(unsigned int capacity, unsigned int numberOfItems, int *weights,
                                         unsigned int weightsLength, int *values,
                                         unsigned int valuesLength) {
    if (!checkAll(capacity, numberOfItems, weights, weightsLength, values, valuesLength)) {
        std::cout << "Wrong input data! (setKnapsackProblem)" << std::endl;
        return;
    }
    this->capacity = capacity;
    this->numberOfItems = numberOfItems;
    this->weights = weights;
    this->weightsLength = weightsLength;
    this->values = values;
    this->valuesLength = valuesLength;
}

void KnapsackProblem::printProblem() {
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Number of items: " << numberOfItems << std::endl;
    std::cout << "Weights: ";
    for (int i = 0; i < weightsLength; ++i) {
        std::cout << weights[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Values: ";
    for (int i = 0; i < valuesLength; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

int KnapsackProblem::evaluateSolution(std::vector<int> solution) {
    int sum = 0;
    int weight = 0;
    for (int i = 0; i < numberOfItems; ++i) {
        sum += solution[i] * values[i];
        weight += solution[i] * weights[i];
    }
    if (weight > capacity) return 0;
    return sum;
}

void KnapsackProblem::saveToFile(std::string fileName) {
    std::ofstream file;
    file.open(fileName);
    file << capacity << std::endl;
    file << numberOfItems << std::endl;
    for (int i = 0; i < weightsLength; ++i) {
        file << weights[i] << " ";
    }
    file << std::endl;
    for (int i = 0; i < valuesLength; ++i) {
        file << values[i] << " ";
    }
    file << std::endl;
    file.close();
}

void KnapsackProblem::loadFromFile(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    file >> capacity;
    file >> numberOfItems;
    weights = new int[numberOfItems];
    weightsLength = numberOfItems;
    values = new int[numberOfItems];
    valuesLength = numberOfItems;
    for (int i = 0; i < weightsLength; ++i) {
        file >> weights[i];
    }
    for (int i = 0; i < valuesLength; ++i) {
        file >> values[i];
    }
    file.close();
}

KnapsackProblem::~KnapsackProblem() {
}






