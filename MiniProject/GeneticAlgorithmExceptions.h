//
// Created by Dawid on 21.01.2023.
//

#ifndef TEP_GENETICALGORITHMEXCEPTIONS_H
#define TEP_GENETICALGORITHMEXCEPTIONS_H

#include <exception>

class InvalidPopulationSizeException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Population size must be greater than 0";
    }
};

class InvalidNumberOfGenerationsException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Number of generations must be greater than 0";
    }
};

class InvalidCrossoverProbabilityException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Crossover probability must be between 0 and 1";
    }
};

class InvalidMutationProbabilityException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Mutation probability must be between 0 and 1";
    }
};

class ProblemNotSetException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Problem not set";
    }
};

#endif //TEP_GENETICALGORITHMEXCEPTIONS_H
