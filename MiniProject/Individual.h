//
// Created by Dawid on 01.01.2023.
//

#ifndef TEP_INDIVIDUAL_H
#define TEP_INDIVIDUAL_H

#include <vector>
#include <ostream>
#include "KnapsackProblem.h"
#include "C:\Users\Dawid\CLionProjects\TEP\TEP5\MySmartPointer.h"


class Individual {
public:
    Individual();
    Individual(Individual& other);
    Individual(int numberOfItems, KnapsackProblem *problem);
    ~Individual();

    void mutate(double mutationProbability);
    std::vector<MySmartPointer<Individual>> crossover(MySmartPointer<Individual> individual);

    void evaluate();

    int getFitness() const { return fitness; }
    std::vector<int> getGenes() const { return genes; }
    unsigned int getGenesLength() const { return genesLength; }

    void print();

    friend std::ostream &operator<<(std::ostream &os, const Individual &individual);

private:
    std::vector<int> genes;
    int genesLength;
    int fitness;

    KnapsackProblem* problem;

    void setGenes(std::vector<int> genes, unsigned int genesLength);

    bool checkNumberOfItems(int numberOfItems) const;
    bool checkProblem(KnapsackProblem *problem) const;
    bool checkAll(int numberOfItems, KnapsackProblem *problem) const;
};


#endif //TEP_INDIVIDUAL_H
