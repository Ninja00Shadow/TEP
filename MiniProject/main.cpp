//
// Created by Dawid on 01.01.2023.
//

#include <iostream>
#include <chrono>
#include <tuple>

#include "GeneticAlgorithm.h"

std::ostream &operator<<(std::ostream &os, const std::tuple<std::vector<int>, int>& solution) {
    os << "genes: ";
    for (auto gene : std::get<0>(solution)) {
        os << gene << " ";
    }
    os << std::endl << "fitness: " << std::get<1>(solution) << std::endl;
    return os;
}


void test1() {
    int capacity = 15;
    int numberOfItems = 9;
    std::vector<int> weights = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    std::vector<int> values = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    KnapsackProblem problem = KnapsackProblem(capacity, numberOfItems, weights, values);
    GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(200, 1000, 0.05, 0.8, &problem);

    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < 100; ++i) {
    geneticAlgorithm.run();
    std::cout << geneticAlgorithm.getBestIndividual() << std::endl;
    geneticAlgorithm.clearPopulation();
//    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms" << std::endl;

}

void problemExceptionTest() {
    int capacity = 15;
    int numberOfItems = 9;
    std::vector<int> weights = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    std::vector<int> invalidWeights = {2, 3, -4, 5, 9, 7, 8, 6, 1, 1};
    std::vector<int> values = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    std::vector<int> invalidValues = {3, 4, 5, 8, 10, 2, 9, 7, 6, 1};

    try {
        KnapsackProblem problem = KnapsackProblem(capacity, 0, weights, values);
    }
    catch (InvalidNumberOfItemsException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        KnapsackProblem problem = KnapsackProblem(0, numberOfItems, weights, values);
    }
    catch (InvalidCapacityException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        KnapsackProblem problem = KnapsackProblem(capacity, numberOfItems, invalidWeights, values);
    }
    catch (InvalidWeightException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        KnapsackProblem problem = KnapsackProblem(capacity, numberOfItems, weights, invalidValues);
    }
    catch (InvalidValueException& e) {
        std::cout << e.what() << std::endl;
    }
}

void geneticAlgorithmExceptionTest() {
    int capacity = 15;
    int numberOfItems = 9;
    std::vector<int> weights = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    std::vector<int> values = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    KnapsackProblem problem = KnapsackProblem(capacity, numberOfItems, weights, values);

    try {
        GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(0, 1000, 0.05, 0.8, &problem);
    }
    catch (InvalidPopulationSizeException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(200, 0, 0.05, 0.8, &problem);
    }
    catch (InvalidNumberOfGenerationsException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(200, 1000, -0.05, 0.8, &problem);
    }
    catch (InvalidMutationProbabilityException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(200, 1000, 0.05, -0.8, &problem);
    }
    catch (InvalidCrossoverProbabilityException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(200, 1000, 0.05, 0.8, nullptr);
    }
    catch (ProblemNotSetException& e) {
        std::cout << e.what() << std::endl;
    }
}

void testSaving() {
    int capacity = 15;
    int numberOfItems = 9;
    std::vector<int> weights = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    std::vector<int> values = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    KnapsackProblem problem = KnapsackProblem(capacity, numberOfItems, weights, values);
    problem.saveToFile("test.txt");

    GeneticAlgorithm geneticAlgorithm =  GeneticAlgorithm(200, 100, 0.05, 0.8, &problem);
    geneticAlgorithm.run();
    geneticAlgorithm.printBestIndividual();
    geneticAlgorithm.clearPopulation();
}

void testLoadingSmallProblems() {
    std::string paths[] = {"instances_01_KP/low-dimensional/f1_l-d_kp_10_269", "instances_01_KP/low-dimensional/f2_l-d_kp_20_878", "instances_01_KP/low-dimensional/f3_l-d_kp_4_20",
                           "instances_01_KP/low-dimensional/f4_l-d_kp_4_11", "instances_01_KP/low-dimensional/f6_l-d_kp_10_60",
                           "instances_01_KP/low-dimensional/f7_l-d_kp_7_50", "instances_01_KP/low-dimensional/f8_l-d_kp_23_10000",
                           "instances_01_KP/low-dimensional/f9_l-d_kp_5_80", "instances_01_KP/low-dimensional/f10_l-d_kp_20_879"};
    KnapsackProblem problem = KnapsackProblem(paths[1]);

    GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(30, 1000, 0.1, 0.7, &problem);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; ++i) {
        geneticAlgorithm.run();
        geneticAlgorithm.printBestIndividual();
        geneticAlgorithm.clearPopulation();
    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms" << std::endl;
}

void testLoadingLargeProblems() {
    std::string paths[] = {"instances_01_KP/large_scale/knapPI_1_100_1000_1", "instances_01_KP/large_scale/knapPI_1_200_1000_1", "instances_01_KP/large_scale/knapPI_1_500_1000_1",
                           "instances_01_KP/large_scale/knapPI_1_1000_1000_1", "instances_01_KP/large_scale/knapPI_1_2000_1000_1",
                           "instances_01_KP/large_scale/knapPI_1_5000_1000_1", "instances_01_KP/large_scale/knapPI_1_10000_1000_1",
                           "instances_01_KP/large_scale/knapPI_2_100_1000_1", "instances_01_KP/large_scale/knapPI_2_200_1000_1"};
    KnapsackProblem* problem = new KnapsackProblem(paths[0]);

    GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm(100, 2000, 0.0, 0.7, problem);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; ++i) {
        geneticAlgorithm->run();
        geneticAlgorithm->printBestIndividual();
        geneticAlgorithm->clearPopulation();
    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms" << std::endl;
}

int main() {
    test1();

    std::cout << "-------------------------------------------------------------------------------------" << std::endl;

    problemExceptionTest();

    std::cout << "-------------------------------------------------------------------------------------" << std::endl;

    geneticAlgorithmExceptionTest();

    std::cout << "-------------------------------------------------------------------------------------" << std::endl;

    testSaving();

    std::cout << "-------------------------------------------------------------------------------------" << std::endl;

    testLoadingSmallProblems();
//    testLoadingLargeProblems();
}