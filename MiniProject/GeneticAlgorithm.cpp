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

}

void GeneticAlgorithm::setGeneticAlgorithm(KnapsackProblem* problem, unsigned int populationSize,
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
}

void GeneticAlgorithm::run() {
    for (int i = 0; i < populationSize; ++i) {
        std::vector<int> genes = std::vector<int>(problem->getNumberOfItems());
        for (int j = 0; j < problem->getNumberOfItems(); ++j) {
            genes[j] = rand() % 2;
        }
        population.push_back(new Individual());
        population[i]->setIndividual(genes, problem->getNumberOfItems(), problem);
    }

    for (int i = 0; i < numberOfGenerations; ++i) {
        std::vector<MySmartPointer<Individual>> newPopulation;

        for (int j = 0; newPopulation.size() < populationSize; ++j) {
            MySmartPointer<Individual> firstParent = population[rand() % populationSize];
            MySmartPointer<Individual> temp = population[rand() % populationSize];

            if (temp->getFitness() > firstParent->getFitness()) {
                firstParent = temp;
            }

            MySmartPointer<Individual> secondParent = population[rand() % populationSize];
            temp = population[rand() % populationSize];

            if (temp->getFitness() > secondParent->getFitness()) {
                secondParent = temp;
            }

            if (rand() % 100 < crossoverProbability * 100) {
                std::vector<MySmartPointer<Individual>> children = firstParent->crossover(secondParent);
                newPopulation.push_back(children[0]);
                if (newPopulation.size() < populationSize) {
                    newPopulation.push_back(children[0]);
                    newPopulation.push_back(children[1]);
                }
            } else {
                newPopulation.push_back(firstParent);
                newPopulation.push_back(secondParent);
            }
        }
        for (int j = 0; j < newPopulation.size(); ++j) {
            newPopulation[j]->mutate(mutationProbability);
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
