#include <iostream>
#include <string>
#include <vector>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"
#include "../include/userIO.h"

int main()
{
    RPNCalculator calc;
    userIO usr;
    std::string usrOperation = "";
    std::vector<std::string> validOperations{"+", "-", "*", "/"};

    while (!usr.validateRPN(usrOperation, validOperations) && usrOperation != "quit")
    {
        usrOperation = usr.getInput("Please provide valid RPN string (type quit to stop): ");
    }
    if (usrOperation == "quit")
    {
        return 0;
    }

    calc.insertOperation(usrOperation);
    calc.solve();
    calc.printSolution();

    std::cin.get();
}