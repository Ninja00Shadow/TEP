//
// Created by Dawid on 01.01.2023.
//

#ifndef TEP_INDIVIDUAL_H
#define TEP_INDIVIDUAL_H

#include <vector>
#include "KnapsackProblem.h"
#include "C:\Users\Dawid\CLionProjects\TEP\TEP5\MySmartPointer.h"


class Individual {
public:
    Individual();
    ~Individual();

    void setIndividual(std::vector<int> genes, unsigned int genesLength, KnapsackProblem* problem);

    void mutate(double mutationProbability);
    std::vector<MySmartPointer<Individual>> crossover(MySmartPointer<Individual> individual);

    void evaluate();

    int getFitness() const { return fitness; }
    std::vector<int> getGenes() const { return genes; }
    unsigned int getGenesLength() const { return genesLength; }

    void print();

private:
    std::vector<int> genes;
    int genesLength;
    int fitness;

    KnapsackProblem* problem;

    void setGenes(std::vector<int> genes, unsigned int genesLength);
};


#endif //TEP_INDIVIDUAL_H
