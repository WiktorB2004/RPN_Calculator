#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "include/calculator.h"

void Calculator::insertOperation(std::string &newOperation)
{
    this->operationStack.push_back(newOperation);
}

void Calculator::printOperations()
{
    for (auto operation : this->operationStack)
    {
        std::cout << operation << std::endl;
    }
}

void Calculator::clearOperations()
{
    this->operationStack.clear();
}

void Calculator::printSolution()
{
    for (auto [operation, result] : this->resultMap)
    {
        std::cout << operation << " = " << result;
    }
}

void Calculator::printHistory()
{
    for (auto [operation, result] : this->history)
    {
        std::cout << operation << " = " << result << std::endl;
    }
}

void Calculator::clearHistory()
{
    this->history.clear();
}