#pragma once
#include <vector>
#include <string>
#include "../include/RPN-Calculator.h"

class userIO
{
public:
    std::string getInput(std::string message);
    std::vector<std::string> extractOperation(std::string &operationString);
    bool validateRPN(std::string input, std::vector<std::string> operations);

    template <class T>
    std::string actionScreen(T calc);
};
