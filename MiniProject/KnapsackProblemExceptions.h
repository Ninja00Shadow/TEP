//
// Created by Dawid on 21.01.2023.
//

#ifndef TEP_KNAPSACKPROBLEMEXCEPTIONS_H
#define TEP_KNAPSACKPROBLEMEXCEPTIONS_H

#include <exception>
#include <string>

class InvalidWeightException : public std::exception {
public:
    InvalidWeightException() {
        message = "Invalid weight";
    }

    explicit InvalidWeightException(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class InvalidValueException : public std::exception {
public:
    InvalidValueException() {
        message = "Invalid value";
    }

    explicit InvalidValueException(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class InvalidCapacityException : public std::exception {
public:
    InvalidCapacityException() {
        message = "Invalid capacity";
    }

    explicit InvalidCapacityException(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class InvalidNumberOfItemsException : public std::exception{
public:
    InvalidNumberOfItemsException() {
        message = "Invalid number of items";
    }

    explicit InvalidNumberOfItemsException(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class FileProblemException : public std::exception {
public:
    FileProblemException() {
        message = "File problem";
    }

    explicit FileProblemException(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class InvalidFileFormatException : public std::exception {
public:
    InvalidFileFormatException() {
        message = "Invalid file format";
    }

    explicit InvalidFileFormatException(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class InvalidCharacterException : public std::exception {
public:
    InvalidCharacterException() {
        message = "Invalid character";
    }

    explicit InvalidCharacterException(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif //TEP_KNAPSACKPROBLEMEXCEPTIONS_H
