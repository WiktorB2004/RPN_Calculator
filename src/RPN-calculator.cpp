#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

double add(double a, double b) { return a + b; }
double substract(double a, double b) { return b - a; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return double(b) / double(a); }

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

double RPNCalculator::solveOperation(const std::vector<std::string> &instructions)
{
    if (instructions.empty())
    {
        return 0;
    }
    std::stack<double> valuesStack;
    for (std::string instruction : instructions)
    {
        if (this->operationMap.find(instruction) == operationMap.end())
        {
            valuesStack.push(stod(instruction));
        }
        else
        {
            double a = valuesStack.top();
            valuesStack.pop();
            double b = valuesStack.top();
            valuesStack.pop();
            valuesStack.push(this->operationMap[instruction](a, b));
        }
    }
    return valuesStack.top();
}

void RPNCalculator::solve()
{
    double res;
    for (std::string operationString : this->operationStack)
    {
        res = solveOperation(extractOperation(operationString));
        this->resultMap[operationString] = res;
        this->history[operationString] = res;
    }
}