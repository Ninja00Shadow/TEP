//
// Created by Dawid on 01.01.2023.
//

#include "Individual.h"

Individual::Individual() {
    fitness = 0;
}

void Individual::setIndividual(std::vector<int> genes, unsigned int genesLength, KnapsackProblem *problem) {
    if (problem == nullptr || genesLength != problem->getNumberOfItems() || genes.empty() || genesLength == 0) {
        std::cout << "Wrong input data! (setIndividual)" << std::endl;
        return;
    }
    this->genes = genes;
    this->genesLength = genesLength;
    this->problem = problem;
    fitness = 0;
    for (int i = 0; i < genesLength; ++i) {
        if (genes[i] == 1) {
            fitness += problem->getValues()[i];
        }
    }
    evaluate();
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

    MySmartPointer<Individual> firstChild = new Individual();
    MySmartPointer<Individual> secondChild = new Individual();

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

    firstChild->setIndividual(firstChildGenes, genesLength, problem);
    secondChild->setIndividual(secondChildGenes, genesLength, problem);

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
