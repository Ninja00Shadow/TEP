//
// Created by Dawid on 01.01.2023.
//

#include <iostream>
#include <chrono>

#include "GeneticAlgorithm.h"

int main() {
    int capacity = 15;
    int numberOfItems = 9;
    int weights[] = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    int values[] = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    KnapsackProblem* problem = new KnapsackProblem();
    problem->setKnapsackProblem(capacity, numberOfItems, weights, 9, values, 9);
    GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm();
    geneticAlgorithm->setGeneticAlgorithm(problem, 200, 1000, 0.05, 0.8);

    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < 100; ++i) {
        geneticAlgorithm->run();
        geneticAlgorithm->printBestIndividual();
        geneticAlgorithm->clearPopulation();
//    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms" << std::endl;

    delete geneticAlgorithm;

    return 0;
}