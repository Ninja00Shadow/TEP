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
    Individual(const Individual& other);
    Individual(KnapsackProblem *problem);
    Individual(Individual&& other);
    ~Individual();

    Individual& operator=(const Individual& other);
    Individual& operator=(Individual&& other) ;

    void mutate(double mutationProbability);
    std::vector<MySmartPointer<Individual>> crossover(MySmartPointer<Individual> const& individual) const;

    void evaluate();

    int getFitness() const { return fitness; }
    std::vector<int> getGenes() const { return genes; }
    int getGenesLength() const { return genes.size(); }

    friend std::ostream &operator<<(std::ostream &os, const Individual &individual);

private:
    std::vector<int> genes;
    int fitness;

    KnapsackProblem* problem{};

    void setGenes(std::vector<int> genes);

    bool checkProblem() const;
    bool checkAll() const;
};


#endif //TEP_INDIVIDUAL_H
