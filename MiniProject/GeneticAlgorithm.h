//
// Created by Dawid on 01.01.2023.
//

#ifndef TEP_GENETICALGORITHM_H
#define TEP_GENETICALGORITHM_H

#include <iostream>
#include <vector>
#include "KnapsackProblem.h"
#include "Individual.h"

class GeneticAlgorithm {
public:
    GeneticAlgorithm();
    ~GeneticAlgorithm();

    void setGeneticAlgorithm(KnapsackProblem* problem, unsigned int populationSize, unsigned int numberOfGenerations,
                             double mutationProbability, double crossoverProbability);

    void run();
    void clearPopulation();

    void printBestIndividual();

private:
    int populationSize;
    std::vector<MySmartPointer<Individual>> population;
    int numberOfGenerations;
    double crossoverProbability;
    double mutationProbability;
    KnapsackProblem* problem;

};


#endif //TEP_GENETICALGORITHM_H
