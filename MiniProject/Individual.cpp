//
// Created by Dawid on 01.01.2023.
//

#include "Individual.h"

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

std::vector<MySmartPointer<Individual>> Individual::crossover(MySmartPointer<Individual> individual) {
    int splitPoint = rand() % genesLength;

    MySmartPointer<Individual> firstChild = new Individual(genesLength, problem);
    MySmartPointer<Individual> secondChild = new Individual(genesLength, problem);

    std::vector<int> firstChildGenes = std::vector<int>(genesLength);
    std::vector<int> secondChildGenes = std::vector<int>(genesLength);

    for (int i = 0; i < genesLength; ++i) {
        if (i < splitPoint) {
            firstChildGenes[i] = genes[i];
            secondChildGenes[i] = individual->getGenes()[i];
        } else {
            firstChildGenes[i] = individual->getGenes()[i];
            secondChildGenes[i] = genes[i];
        }
    }

    firstChild->setGenes(firstChildGenes, genesLength);
    secondChild->setGenes(secondChildGenes, genesLength);

    std::vector<MySmartPointer<Individual>> children;
    children.push_back(firstChild);
    children.push_back(secondChild);

    return children;
}

void Individual::setGenes(std::vector<int> genes, unsigned int genesLength) {
    this->genes = genes;
    this->genesLength = genesLength;

}

void Individual::evaluate() {
    fitness = problem->evaluateSolution(genes);
}

Individual::~Individual() {
}

void Individual::print() {
    std::cout << "Genes: ";
    for (int i = 0; i < genesLength; ++i) {
        std::cout << genes[i] << " ";
    }
}

Individual::Individual(Individual &other) {
    this->genes = other.getGenes();
    this->genesLength = other.getGenesLength();
    this->fitness = other.getFitness();
    this->problem = other.problem;
}

Individual::Individual(int numberOfItems, KnapsackProblem *problem) {
    if (!checkAll(numberOfItems, problem)) {
        throw std::invalid_argument("Wrong input data! (Individual)");
    }
    this->genesLength = numberOfItems;
    this->problem = problem;
    for (int i = 0; i < numberOfItems; ++i) {
        genes.push_back(rand() % 2);
    }
    evaluate();
}

bool Individual::checkNumberOfItems(int numberOfItems) const {
    return numberOfItems > 0;
}

bool Individual::checkProblem(KnapsackProblem *problem) const {
    return problem != nullptr;
}

bool Individual::checkAll(int numberOfItems, KnapsackProblem *problem) const {
    return checkNumberOfItems(numberOfItems) && checkProblem(problem);
}

std::ostream &operator<<(std::ostream &os, const Individual &individual) {
    os << "genes: ";
    for (int i = 0; i < individual.genesLength; ++i) {
        os << individual.genes[i] << " ";
    }
    os << std::endl << "fitness: " << individual.fitness << std::endl;
    return os;
}
