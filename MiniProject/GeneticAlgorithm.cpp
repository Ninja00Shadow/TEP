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

GeneticAlgorithm::GeneticAlgorithm(int populationSize, int numberOfGenerations, double mutationProbability,
                                   double crossoverProbability, KnapsackProblem *problem) {
    if (!checkAll(populationSize, numberOfGenerations, mutationProbability, crossoverProbability, problem)) {
        throw std::invalid_argument("Invalid arguments");
    }
    this->populationSize = populationSize;
    this->numberOfGenerations = numberOfGenerations;
    this->mutationProbability = mutationProbability;
    this->crossoverProbability = crossoverProbability;
    this->problem = problem;
}

GeneticAlgorithm::~GeneticAlgorithm() {

}


void GeneticAlgorithm::run() {
    for (int i = 0; i < populationSize; ++i) {
        population.push_back(new Individual(problem->getNumberOfItems(), problem));
    }

    for (int i = 0; i < numberOfGenerations; ++i) {
        std::vector<MySmartPointer<Individual>> newPopulation;

        generateAndAddChildrenToPopulation(newPopulation);

        for (int j = 0; j < newPopulation.size(); ++j) {
            newPopulation[j]->mutate(mutationProbability);
        }
    }
}

void GeneticAlgorithm::printBestIndividual() {
    MySmartPointer<Individual> bestIndividualNow = population[0];
    for (int i = 1; i < populationSize; ++i) {
        if (population[i]->getFitness() > bestIndividualNow->getFitness()) {
            bestIndividualNow = population[i];
        }
    }

    if (bestIndividualNow->getFitness() > bestIndividual->getFitness()) {
        bestIndividual = bestIndividualNow;
    }

    std::cout << "Best individual: " << std::endl;
    std::cout << *bestIndividual << std::endl;

}

void GeneticAlgorithm::clearPopulation() {
    population.clear();
    bestIndividual = nullptr;
}

MySmartPointer<Individual> GeneticAlgorithm::selectParent() {
    MySmartPointer<Individual> parent = population[rand() % populationSize];
    MySmartPointer<Individual> temp = population[rand() % populationSize];

    if (temp->getFitness() > parent->getFitness()) return temp;
    return parent;
}

void GeneticAlgorithm::bestIndividualUpdate(MySmartPointer<Individual> individual) {
    if (bestIndividual == nullptr) {
        bestIndividual = individual;
        return;
    }
    bestIndividual->evaluate();
    if (individual->getFitness() > bestIndividual->getFitness()) {
        bestIndividual = MySmartPointer<Individual>(individual);
    }

}

void GeneticAlgorithm::generateAndAddChildrenToPopulation(std::vector<MySmartPointer<Individual>> newPopulation) {
    for (int j = 0; newPopulation.size() < populationSize; ++j) {
        MySmartPointer<Individual> firstParent = selectParent();
        MySmartPointer<Individual> secondParent = selectParent();

        bestIndividualUpdate(firstParent);
        bestIndividualUpdate(secondParent);

        if (rand() % 100 < crossoverProbability * 100) {
            std::vector<MySmartPointer<Individual>> children = firstParent->crossover(secondParent);
            bestIndividualUpdate(children[0]);
            bestIndividualUpdate(children[1]);

            newPopulation.push_back(children[0]);
            if (newPopulation.size() < populationSize) {
                newPopulation.push_back(children[1]);
            }

        } else {
            newPopulation.push_back(MySmartPointer<Individual>(new Individual(*firstParent)));
            newPopulation.push_back(MySmartPointer<Individual>(new Individual(*secondParent)));

        }
    }
}


bool GeneticAlgorithm::checkPopulationSize(int populationSize) const {
    return populationSize > 0;
}

bool GeneticAlgorithm::checkNumberOfGenerations(int numberOfGenerations) const {
    return numberOfGenerations > 0;
}

bool GeneticAlgorithm::checkCrossoverProbability(double crossoverProbability) const {
    return crossoverProbability >= 0;
}

bool GeneticAlgorithm::checkMutationProbability(double mutationProbability) const {
    return mutationProbability >= 0;
}

bool GeneticAlgorithm::checkProblem(KnapsackProblem *problem) const {
    return problem != nullptr;
}

bool GeneticAlgorithm::checkAll(int populationSize, int numberOfGenerations, double crossoverProbability,
                                double mutationProbability,
                                KnapsackProblem *problem) const {
    return checkPopulationSize(populationSize) && checkNumberOfGenerations(numberOfGenerations) &&
           checkCrossoverProbability(crossoverProbability) &&
           checkMutationProbability(mutationProbability) && checkProblem(problem);
}
