//
// Created by Dawid on 01.01.2023.
//

#include <iostream>
#include <chrono>

#include "GeneticAlgorithm.h"

void test1() {
    int capacity = 15;
    int numberOfItems = 9;
    int weights[] = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    int values[] = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    KnapsackProblem* problem = new KnapsackProblem(capacity, numberOfItems, weights, 9, values, 9);
    GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm(200, 1000, 0.05, 0.8, problem);

    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < 100; ++i) {
    geneticAlgorithm->run();
    geneticAlgorithm->printBestIndividual();
    geneticAlgorithm->clearPopulation();
//    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms" << std::endl;

    delete geneticAlgorithm;
}

void testSaving() {
    int capacity = 15;
    int numberOfItems = 9;
    int weights[] = {2, 3, 4, 5, 9, 7, 8, 6, 1};
    int values[] = {3, 4, 5, 8, 10, 2, 9, 7, 6};
    KnapsackProblem* problem = new KnapsackProblem(capacity, numberOfItems, weights, 9, values, 9);
    problem->saveToFile("test.txt");

    GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm(200, 10000, 0.05, 0.8, problem);
    geneticAlgorithm->run();
    geneticAlgorithm->printBestIndividual();
    geneticAlgorithm->clearPopulation();

    delete geneticAlgorithm;
    delete problem;
}

void testLoading() {
    KnapsackProblem* problem = new KnapsackProblem();
    std::string paths[] = {"instances_01_KP/low-dimensional/f1_l-d_kp_10_269", "instances_01_KP/low-dimensional/f2_l-d_kp_20_878", "instances_01_KP/low-dimensional/f3_l-d_kp_4_20",
                           "instances_01_KP/low-dimensional/f4_l-d_kp_4_11", "instances_01_KP/low-dimensional/f6_l-d_kp_10_60",
                           "instances_01_KP/low-dimensional/f7_l-d_kp_7_50", "instances_01_KP/low-dimensional/f8_l-d_kp_23_10000",
                           "instances_01_KP/low-dimensional/f9_l-d_kp_5_80", "instances_01_KP/low-dimensional/f10_l-d_kp_20_879"};
    problem->loadFromFile(paths[8]);

    GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm(500, 1000, 0.1, 0.7, problem);

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

    testSaving();

    std::cout << "-------------------------------------------------------------------------------------" << std::endl;

    testLoading();
}