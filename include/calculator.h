#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class Calculator
{
private:
    // Contains history of the operations
    std::unordered_map<std::string, int> history;
    std::unordered_map<std::string, int (*)(int, int)> operationMap;
    std::vector<std::string> operationStack;
    std::unordered_map<std::string, int> resultMap;

public:
    void insertOperation(std::string &newOperation);
    void printOperations();
    void clearOperations();
    void printHistory();
    void clearHistory();
    void printSolution();
    virtual int solve() = 0;
};
