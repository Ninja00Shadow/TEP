//
// Created by Dawid on 01.01.2023.
//

#include <iostream>

#include "GeneticAlgorithm.h"

int main() {
    int capacity = 10;
    int numberOfItems = 9;
    int weights[] = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    int values[] = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    KnapsackProblem *problem = new KnapsackProblem();
    problem->setKnapsackProblem(capacity, numberOfItems, weights, 9, values, 9);
    GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm();
    geneticAlgorithm->setGeneticAlgorithm(problem, 200, 10000, 0.05, 0.8);

    geneticAlgorithm->run();
    geneticAlgorithm->printBestIndividual();

    return 0;
}