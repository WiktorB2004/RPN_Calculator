#pragma once
#include <vector>
#include <string>
#include "calculator.h"

class RPNCalculator : public Calculator
{
protected:
    std::vector<std::string> extractOperation(std::string &operationString);

public:
    std::string parentName = "calculator";
    RPNCalculator();
    ~RPNCalculator();
    void solve();
    int solveOperation(const std::vector<std::string> &instructions);
};
