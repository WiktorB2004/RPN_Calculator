#pragma once
#include "calculator.h"
#include <vector>
#include <string>

class RPNCalculator : public Calculator
{
protected:
    int solveOperation(const std::vector<std::string> &instructions);
    std::vector<std::string> extractOperation(std::string &operationString);

public:
    std::string parentName = "calculator";
    RPNCalculator();
    ~RPNCalculator();
    void solve();
};
