#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

int add(int a, int b) { return a + b; }
int substract(int a, int b) { return b - a; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b / a; }

RPNCalculator::RPNCalculator() : Calculator()
{
    operationMap = {{"+", &add},
                    {"-", &substract},
                    {"*", &multiply},
                    {"/", &divide}};
}

RPNCalculator::~RPNCalculator(){};

std::vector<std::string> RPNCalculator::extractOperation(std::string &operationString)
{
    std::vector<std::string> res;
    std::string curr = "";
    for (auto el : operationString)
    {
        if (el == ' ')
        {
            res.push_back(curr);
            curr = "";
        }
        else
        {
            curr += el;
        }
    }
    res.push_back(curr);
    return res;
}

int RPNCalculator::solveOperation(const std::vector<std::string> &instructions)
{
    if (instructions.empty())
    {
        return 0;
    }
    std::stack<int> valuesStack;
    for (std::string instruction : instructions)
    {
        if (this->operationMap.find(instruction) == operationMap.end())
        {
            valuesStack.push(stoi(instruction));
        }
        else
        {
            int a = valuesStack.top();
            valuesStack.pop();
            int b = valuesStack.top();
            valuesStack.pop();
            valuesStack.push(this->operationMap[instruction](a, b));
        }
    }
    return valuesStack.top();
}

void RPNCalculator::solve()
{
    int res;
    for (std::string operationString : this->operationStack)
    {
        res = solveOperation(extractOperation(operationString));
        this->resultMap[operationString] = res;
        this->history[operationString] = res;
    }
}