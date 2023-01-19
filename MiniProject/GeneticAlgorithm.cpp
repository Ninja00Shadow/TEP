//
// Created by Dawid on 01.01.2023.
//

#include <tuple>
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
    this->populationSize = populationSize;
    this->numberOfGenerations = numberOfGenerations;
    this->mutationProbability = mutationProbability;
    this->crossoverProbability = crossoverProbability;
    this->problem = problem;

    if (!checkAll()) {
        throw std::invalid_argument("Wrong input data! (GeneticAlgorithm)");
    }
}

GeneticAlgorithm::~GeneticAlgorithm() = default;


void GeneticAlgorithm::run() {
    for (int i = 0; i < populationSize; ++i) {
        population.push_back(new Individual(problem));
    }

    for (int i = 0; i < numberOfGenerations; ++i) {
        std::vector<MySmartPointer<Individual>> newPopulation;

        fillNewPopulation(newPopulation);

        population = newPopulation;
        for (auto &j: newPopulation) {
            j->mutate(mutationProbability);
        }

        bestIndividualUpdate();
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

void GeneticAlgorithm::bestIndividualUpdate() {
    if (bestIndividual == nullptr) {
        bestIndividual = population[0];
    }
    for (int i = 0; i < population.size(); ++i) {
        if (population[i]->getFitness() > bestIndividual->getFitness()) {
            bestIndividual = MySmartPointer<Individual>(population[i]);
        }
    }
}

void GeneticAlgorithm::fillNewPopulation(std::vector<MySmartPointer<Individual>> &newPopulation) {
    for (int j = 0; newPopulation.size() < populationSize; ++j) {
        MySmartPointer<Individual> firstParent = selectParent();
        MySmartPointer<Individual> secondParent = selectParent();

        if (rand() % 100 < crossoverProbability * 100) {
            std::vector<MySmartPointer<Individual>> children = firstParent->crossover(secondParent);

            newPopulation.push_back(children[0]);
            newPopulation.push_back(children[1]);
        } else {
            newPopulation.push_back(MySmartPointer<Individual>(new Individual(*firstParent)));
            newPopulation.push_back(MySmartPointer<Individual>(new Individual(*secondParent)));
        }
    }
}


bool GeneticAlgorithm::checkPopulationSize() const {
    return populationSize > 0;
}

bool GeneticAlgorithm::checkNumberOfGenerations() const {
    return numberOfGenerations > 0;
}

bool GeneticAlgorithm::checkCrossoverProbability() const {
    return crossoverProbability >= 0;
}

bool GeneticAlgorithm::checkMutationProbability() const {
    return mutationProbability >= 0;
}

bool GeneticAlgorithm::checkProblem() const {
    return problem != nullptr;
}

bool GeneticAlgorithm::checkAll() const {
    return checkPopulationSize() && checkNumberOfGenerations() &&
           checkCrossoverProbability() &&
           checkMutationProbability() && checkProblem();
}

std::tuple<std::vector<int>, int> GeneticAlgorithm::getBestIndividual() {
    return std::make_tuple(bestIndividual->getGenes(), bestIndividual->getFitness());
}
