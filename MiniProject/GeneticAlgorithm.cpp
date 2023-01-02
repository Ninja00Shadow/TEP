//
// Created by Dawid on 01.01.2023.
//

#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm() {
    populationSize = 0;
    numberOfGenerations = 0;
    crossoverProbability = 0;
    mutationProbability = 0;
    problem = nullptr;

}

GeneticAlgorithm::~GeneticAlgorithm() {
    population.clear();
}

void GeneticAlgorithm::setGeneticAlgorithm(KnapsackProblem *problem, unsigned int populationSize,
                                           unsigned int numberOfGenerations, double mutationProbability,
                                           double crossoverProbability) {
    if (problem == nullptr || populationSize == 0 || numberOfGenerations == 0 || mutationProbability == 0 ||
        crossoverProbability == 0) {
        std::cout << "Wrong input data! (setGeneticAlgorithm)" << std::endl;
        return;
    }
    this->populationSize = populationSize;
    this->numberOfGenerations = numberOfGenerations;
    this->crossoverProbability = crossoverProbability;
    this->mutationProbability = mutationProbability;
    this->problem = problem;

    population.clear();
    population.resize(populationSize);
}

void GeneticAlgorithm::run() {
    for (int i = 0; i < populationSize; ++i) {
        std::vector<int> genes = std::vector<int>(problem->getNumberOfItems());
        for (int j = 0; j < problem->getNumberOfItems(); ++j) {
            genes[j] = rand() % 2;
        }
        population[i] = new Individual();
        population[i]->setIndividual(genes, problem->getNumberOfItems(), problem);
    }

    for (int i = 0; i < numberOfGenerations; ++i) {
        std::vector<MySmartPointer<Individual>> newPopulation;
        newPopulation.resize(populationSize);

        for (int j = 0; j < populationSize; ++j) {
            MySmartPointer<Individual> firstParent = population[rand() % populationSize];
            MySmartPointer<Individual> secondParent = population[rand() % populationSize];

            MySmartPointer<Individual> child = new Individual();
            if (rand() % 100 < crossoverProbability * 100) {
                std::vector<MySmartPointer<Individual>> children = firstParent->crossover(secondParent);
                child = children[rand() % 2];
            } else {
                child = firstParent;
            }
            child->mutate(mutationProbability);
            newPopulation[j] = child;
        }
    }
}

void GeneticAlgorithm::printBestIndividual() {
    MySmartPointer<Individual> bestIndividual = population[0];
    for (int i = 1; i < populationSize; ++i) {
        if (population[i]->getFitness() > bestIndividual->getFitness()) {
            bestIndividual = population[i];
        }
    }
    std::cout << "Best individual: ";
    for (int i = 0; i < problem->getNumberOfItems(); ++i) {
        std::cout << bestIndividual->getGenes()[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Best fitness: " << bestIndividual->getFitness() << std::endl;
}

void GeneticAlgorithm::clearPopulation() {
    population.clear();
}
