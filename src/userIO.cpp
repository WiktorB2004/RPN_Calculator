#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include "../include/userIO.h"

void clear()
{
    system("clear");
}

std::string userIO::getInput(std::string message = "")
{
    std::string res = "";
    std::cout << message;
    std::getline(std::cin, res);
    return res;
}

bool isNumber(const std::string &s)
{
    for (char const &ch : s)
    {
        if (std::isdigit(ch) == 0 && ch != '.')
        {
            return false;
        }
    }
    return true;
}

// This function is copied from RPN-calculator

std::vector<std::string> userIO::extractOperation(std::string &operationString)
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

bool userIO::validateRPN(std::string input, std::vector<std::string> operations)
{
    std::vector<std::string> inputList = extractOperation(input);
    int n = inputList.size();
    // Base case - first two elements must be a number and the last one is operation
    if (n <= 2 || !isNumber(inputList[0]) || !isNumber(inputList[1]) || std::find(operations.begin(), operations.end(), inputList[n - 1]) == operations.end())
    {
        return false;
    }
    // Used to check if for k numbers there is k - 1 operations
    int numberCount = 2, i = 2;
    while (i < n && numberCount > 0)
    {
        if (isNumber(inputList[i]))
        {
            numberCount++;
        }
        else if (std::find(operations.begin(), operations.end(), inputList[i]) != operations.end())
        {
            numberCount--;
        }
        else
        {
            return false;
        }
        i++;
    }
    return numberCount == 1;
}

template <class T>
std::string userIO::actionScreen(T calc)
{
    clear();
    std::string operation;
    std::cout << "Choose the action: " << std::endl
              << "1. Insert operation" << std::endl
              << "2. Show current operations" << std::endl
              << "3. Solve and print solution" << std::endl
              << "4. Show history" << std::endl
              << "5. Clear history" << std::endl
              << "6. quit" << std::endl;
    operation = getInput();
    if (isNumber(operation))
    {
        return operation;
    }
    else
    {
        return "-1";
    }
}

template std::string userIO::actionScreen<RPNCalculator>(RPNCalculator calc);