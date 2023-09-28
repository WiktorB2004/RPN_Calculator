#include <iostream>
#include <string>
#include <vector>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

int main()
{
    RPNCalculator a;

    std::string operation1 = "3 5 +";
    std::string operation2 = "5 3 -";
    std::string operation3 = "3 3 *";
    std::string operation4 = "8 4 /";
    a.insertOperation(operation1);
    a.insertOperation(operation2);
    a.insertOperation(operation3);
    a.insertOperation(operation4);
    // a.printOperations();
    a.solve();
    a.printSolution();
    std::cin.get();
}