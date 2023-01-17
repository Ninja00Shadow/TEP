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

private:
    int populationSize;
    std::vector<MySmartPointer<Individual>> population;
    int numberOfGenerations;
    double crossoverProbability;
    double mutationProbability;
    KnapsackProblem *problem;

    MySmartPointer<Individual> bestIndividual;

    MySmartPointer<Individual> selectParent();

    void generateAndAddChildrenToPopulation(std::vector<MySmartPointer<Individual>>& newPopulation);

    void bestIndividualUpdate(MySmartPointer<Individual> individual);

    bool checkPopulationSize(int populationSize) const;

    bool checkNumberOfGenerations(int numberOfGenerations) const;

    bool checkCrossoverProbability(double crossoverProbability) const;

    bool checkMutationProbability(double mutationProbability) const;

    bool checkProblem(KnapsackProblem *problem) const;

    bool checkAll(int populationSize, int numberOfGenerations, double crossoverProbability, double mutationProbability,
                  KnapsackProblem *problem) const;
};


#endif //TEP_GENETICALGORITHM_H
