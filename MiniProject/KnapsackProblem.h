//
// Created by Dawid on 01.01.2023.
//

#ifndef TEP_KNAPSACKPROBLEM_H
#define TEP_KNAPSACKPROBLEM_H

#include <iostream>

class KnapsackProblem {
public:
    KnapsackProblem();

    ~KnapsackProblem();

    void setKnapsackProblem(unsigned int capacity, unsigned int numberOfItems, int *weights, unsigned int weightsLength,
                            int *values, unsigned int valuesLength);

    int getCapacity() const { return capacity; }

    int getNumberOfItems() const { return numberOfItems; }

    int *getWeights() { return weights; }

    int *getValues() { return values; }

    int getWeight(int itemNumber) { return weights[itemNumber]; }

    int getValue(int itemNumber) { return values[itemNumber]; }

    void setCapacity(int capacity) { this->capacity = capacity; }

    void setNumberOfItems(int numberOfItems) { this->numberOfItems = numberOfItems; }

    void setWeights(int *weights) { this->weights = weights; }

    void setValues(int *values) { this->values = values; }

    void setWeight(int itemNumber, int weight) { weights[itemNumber] = weight; }

    void setValue(int itemNumber, int value) { values[itemNumber] = value; }

    void printProblem();

    int evaluateSolution(std::vector<int> solution);

    void saveToFile(std::string fileName);

    void loadFromFile(std::string fileName);

private:
    unsigned int capacity;
    unsigned int numberOfItems;
    int *weights;
    unsigned int weightsLength;
    int *values;
    unsigned int valuesLength;

    bool checkWeights(int *weights, unsigned int weightsLength, unsigned int numberOfItems);

    bool checkValues(int *values, unsigned int valuesLength, unsigned int numberOfItems);

    bool
    checkAll(unsigned int capacity, unsigned int numberOfItems, int *weights, unsigned int weightsLength, int *values,
             unsigned int valuesLength);
};


#endif //TEP_KNAPSACKPROBLEM_H
