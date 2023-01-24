//
// Created by Dawid on 01.01.2023.
//

#include "Individual.h"
#include <cmath>

Individual::Individual() {
    fitness = 0;
}


void Individual::mutate(double mutationProbability) {
    for (int i = 0; i < problem->getNumberOfItems(); ++i) {
        if (rand() % 100 < mutationProbability * 100) {
            genes[i] = !genes[i];
        }
    }
    evaluate();
}

std::vector<MySmartPointer<Individual>> Individual::crossover(const MySmartPointer<Individual>& individual) const {
    int splitPoint = rand() % genes.size();

    MySmartPointer<Individual> firstChild = new Individual(problem);
    MySmartPointer<Individual> secondChild = new Individual(problem);

    std::vector<int> firstChildGenes = std::vector<int>(genes.size());
    std::vector<int> secondChildGenes = std::vector<int>(genes.size());

    for (int i = 0; i < genes.size(); ++i) {
        if (i < splitPoint) {
            firstChildGenes[i] = genes[i];
            secondChildGenes[i] = individual->getGenes()[i];
        } else {
            firstChildGenes[i] = individual->getGenes()[i];
            secondChildGenes[i] = genes[i];
        }
    }

    firstChild->setGenes(firstChildGenes);
    secondChild->setGenes(secondChildGenes);

    std::vector<MySmartPointer<Individual>> children;
    children.push_back(firstChild);
    children.push_back(secondChild);

    return children;
}

void Individual::setGenes(std::vector<int> genes) {
    this->genes = std::move(genes);
}

void Individual::evaluate() {
    fitness = problem->evaluateSolution(genes);
}

Individual::~Individual() = default;


Individual::Individual(const Individual &other) {
    this->genes = other.getGenes();
    this->fitness = other.getFitness();
    this->problem = other.problem;
}

Individual::Individual(KnapsackProblem *problem) {
    this->problem = problem;

    if (!checkAll()) {
        throw std::invalid_argument("Wrong input data! (Individual)");
    }

    for (int i = 0; i < problem->getNumberOfItems(); ++i) {
        if (problem->getFillingRatio() > (rand() % 100) / 100.0) {
            genes.push_back(1);
        } else {
            genes.push_back(0);
        }
    }

    evaluate();
}

bool Individual::checkProblem() const {
    return problem != nullptr && problem->getNumberOfItems() > 0;
}

bool Individual::checkAll() const {
    return checkProblem();
}

Individual::Individual(Individual &&other) {
    if (this != &other) {
        this->genes = other.getGenes();
        this->fitness = other.getFitness();
        this->problem = other.problem;

        other.genes.clear();
        other.fitness = 0;
        other.problem = nullptr;
    }
}

Individual &Individual::operator=(const Individual &other) {
    return *this = Individual(other);
}

Individual &Individual::operator=(Individual &&other) {
    return *this = Individual(other);
}
