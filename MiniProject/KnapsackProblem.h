//
// Created by Dawid on 01.01.2023.
//

#ifndef TEP_KNAPSACKPROBLEM_H
#define TEP_KNAPSACKPROBLEM_H

#include <iostream>
#include "KnapsackProblemExceptions.h"

class KnapsackProblem {
public:
    KnapsackProblem(int capacity, int numberOfItems, std::vector<int>& weights, std::vector<int>& values);

    KnapsackProblem(const std::string& fileName);

    ~KnapsackProblem();

    int getNumberOfItems() const { return numberOfItems; }

    void setValue(int itemNumber, int value) { values[itemNumber] = value; }

    void printProblem();

    int evaluateSolution(std::vector<int> solution);

    void saveToFile(const std::string& fileName);

    double getFillingRatio() const;

private:
    int capacity{};
    int numberOfItems{};
    std::vector<int> weights;
    std::vector<int> values;
    double fillingRatio{};

    void checkWeights() const;

    void checkValues() const;

    void checkAll() const;

    void calculateFillingRatio();

    void loadFromFile(const std::string& fileName);
};


#endif //TEP_KNAPSACKPROBLEM_H
