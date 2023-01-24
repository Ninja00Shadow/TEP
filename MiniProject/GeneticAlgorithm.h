//
// Created by Dawid on 01.01.2023.
//

#ifndef TEP_GENETICALGORITHM_H
#define TEP_GENETICALGORITHM_H

#include <iostream>
#include <vector>
#include "KnapsackProblem.h"
#include "Individual.h"
#include "GeneticAlgorithmExceptions.h"

class GeneticAlgorithm {
public:
    GeneticAlgorithm();

    GeneticAlgorithm(int populationSize, int numberOfGenerations, double mutationProbability,
                     double crossoverProbability, KnapsackProblem *problem);

    ~GeneticAlgorithm();

    void run();

    void clearPopulation();

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

    void checkPopulationSize() const;

    void checkNumberOfGenerations() const;

    void checkCrossoverProbability() const;

    void checkMutationProbability() const;

    void checkProblem() const;

    void checkAll() const;
};


#endif //TEP_GENETICALGORITHM_H
