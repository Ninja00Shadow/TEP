//
// Created by Dawid on 01.01.2023.
//

#include <fstream>
#include <vector>
#include "KnapsackProblem.h"
#include <cmath>
#include <sstream>

void KnapsackProblem::checkWeights() const {
    for (int i = 0; i < numberOfItems; ++i) {
        if (weights[i] <= 0) throw InvalidWeightException("Weight of item " + std::to_string(i) + " is invalid");
    }
    if (weights.size() != numberOfItems) throw InvalidWeightException("Number of weights is invalid");
}

void KnapsackProblem::checkValues() const {
    for (int i = 0; i < numberOfItems; ++i) {
        if (values[i] <= 0) throw InvalidValueException("Value of item " + std::to_string(i) + " is invalid");
    }
    if (values.size() != numberOfItems) throw InvalidValueException("Number of values is invalid");
}

void KnapsackProblem::checkAll() const{
    if (numberOfItems <= 0) throw InvalidNumberOfItemsException("Number of items is invalid");
    if (capacity <= 0) throw InvalidCapacityException("Capacity is invalid");
    checkWeights();
    checkValues();
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

    std::stringstream ss;

    ss << numberOfItems << " " << capacity << std::endl;
    for (int i = 0; i < numberOfItems; ++i) {
        ss << values[i] << " " << weights[i] << std::endl;
    }
    std::string s = ss.str();
    s.pop_back();
    file << s;
    file.close();
}

void KnapsackProblem::loadFromFile(const std::string& fileName) {
    std::ifstream file;
    file.open(fileName);
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    if (file.is_open()) {
        file >> numberOfItems;
        file >> capacity;
        weights.resize(numberOfItems);
        values.resize(numberOfItems);
        int i = 0;
        while (!file.eof()) {
            try {
                file >> values[i];
                file >> weights[i];
                i++;
            }
            catch (std::ifstream::failure& e) {
                throw InvalidCharacterException("Invalid character in line " + std::to_string(i+2));
            }

            if (!file.eof() && file.peek() != '\n') throw InvalidFileFormatException("To many arguments in line " + std::to_string(i+2));
        }
    }
    else {
        throw FileProblemException("File not found");
    }
    calculateFillingRatio();
}

KnapsackProblem::~KnapsackProblem() = default;

KnapsackProblem::KnapsackProblem(int capacity, int numberOfItems, std::vector<int>& weights, std::vector<int>& values) {
    this->capacity = capacity;
    this->numberOfItems = numberOfItems;
    this->weights = weights;
    this->values = values;

    checkAll();

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

    checkAll();
}






