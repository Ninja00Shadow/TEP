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

    GeneticAlgorithm(int populationSize, int numberOfGenerations, double mutationProbability,
                     double crossoverProbability, KnapsackProblem *problem);

    ~GeneticAlgorithm();

    void run();

    void clearPopulation();

    void printBestIndividual();

    std::tuple<std::vector<int>, int> getBestIndividual();

private:
    int populationSize;
    std::vector<MySmartPointer<Individual>> population;
    int numberOfGenerations;
    double crossoverProbability;
    double mutationProbability;
    KnapsackProblem *problem;
    MySmartPointer<Individual> bestIndividual;



    MySmartPointer<Individual> selectParent();

    void fillNewPopulation(std::vector<MySmartPointer<Individual>>& newPopulation);

    void bestIndividualUpdate();

    bool checkPopulationSize() const;

    bool checkNumberOfGenerations() const;

    bool checkCrossoverProbability() const;

    bool checkMutationProbability() const;

    bool checkProblem() const;

    bool checkAll() const;
};


#endif //TEP_GENETICALGORITHM_H
