#pragma once
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

class Calculator
{
protected:
    // Contains history of the operations
    std::unordered_map<std::string, int> history;
    // Contains map of operands - function eg. "+" - Add ...
    std::unordered_map<std::string, int (*)(int a, int b)> operationMap;
    // Contains operations inserted by user, not yet solved
    std::vector<std::string> operationStack;
    // Contains solved operations
    std::unordered_map<std::string, int> resultMap;
    virtual int solveOperation(const std::vector<std::string> &instructions) = 0;

public:
    Calculator();
    virtual ~Calculator();
    virtual void solve() = 0;

    void insertOperation(std::string &newOperation);
    void printOperations();
    void clearOperations();
    void printHistory();
    void clearHistory();
    void printSolution();
};
