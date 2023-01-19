//
// Created by Dawid on 01.01.2023.
//

#include <fstream>
#include <vector>
#include "KnapsackProblem.h"
#include <cmath>

bool KnapsackProblem::checkWeights() const {
    for (int i = 0; i < numberOfItems; ++i) {
        if (weights[i] <= 0) return false;
    }
    return weights.size() == numberOfItems;
}

bool KnapsackProblem::checkValues() const {
    for (int i = 0; i < numberOfItems; ++i) {
        if (values[i] <= 0) return false;
    }
    return values.size() == numberOfItems;
}

bool
KnapsackProblem::checkAll() const{
    return capacity != 0 && numberOfItems != 0 && checkWeights() && checkValues();
}


void KnapsackProblem::printProblem() {
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Number of items: " << numberOfItems << std::endl;
    std::cout << "Weights: ";
    for (int i = 0; i < numberOfItems; ++i) {
        std::cout << weights[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Values: ";
    for (int i = 0; i < numberOfItems; ++i) {
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

void KnapsackProblem::saveToFile(const std::string& fileName) {
    std::ofstream file;
    file.open(fileName);
    file << numberOfItems << std::endl;
    file << capacity << std::endl;
    for (int i = 0; i < numberOfItems; ++i) {
        file << values[i] << " " << weights[i] << std::endl;
    }
    file << std::endl;
    file.close();
}

void KnapsackProblem::loadFromFile(const std::string& fileName) {
    std::ifstream file;
    file.open(fileName);
    file >> numberOfItems;
    file >> capacity;

    weights = std::vector<int>(numberOfItems);
    values = std::vector<int>(numberOfItems);

    for (int i = 0; i < numberOfItems; ++i) {
        file >> values[i];
        file >> weights[i];
    }

    calculateFillingRatio();
}

KnapsackProblem::~KnapsackProblem() = default;

KnapsackProblem::KnapsackProblem(int capacity, int numberOfItems, std::vector<int>& weights, std::vector<int>& values) {
    this->capacity = capacity;
    this->numberOfItems = numberOfItems;
    this->weights = weights;
    this->values = values;

    if (!checkAll()) {
        throw std::invalid_argument("Wrong input data! (KnapsackProblem)");
    }

    calculateFillingRatio();
}

double KnapsackProblem::getFillingRatio() const {
    return fillingRatio;
}

void KnapsackProblem::calculateFillingRatio() {
    for (int weight : weights) {
        fillingRatio += weight;
    }

    fillingRatio = capacity / fillingRatio;

    if (fillingRatio > 0.05) fillingRatio = sqrt(fillingRatio);
    else fillingRatio = pow(fillingRatio, 2);
}

KnapsackProblem::KnapsackProblem(const std::string& fileName) {
    loadFromFile(fileName);

    if (!checkAll()) {
        throw std::invalid_argument("Wrong input data! (KnapsackProblem)");
    }
}






