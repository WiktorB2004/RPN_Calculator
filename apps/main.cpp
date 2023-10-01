#include <iostream>
#include <string>
#include <vector>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"
#include "../include/userIO.h"

void clear();
std::string getOperation(userIO usr);

RPNCalculator calc;
userIO usr;
int main()
{
    std::string usrOperation = "0";
    while (stoi(usrOperation) <= 0 || stoi(usrOperation) > 6)
    {
        usrOperation = usr.actionScreen<RPNCalculator>(calc);
    }

    switch (stoi(usrOperation))
    {
    case 1:
        usrOperation = getOperation(usr);
        calc.insertOperation(usrOperation);
        return main();
        break;
    case 2:
        clear();
        calc.printOperations();
        std::cout << "Click any button to go back";
        std::cin.get();
        return main();
        break;
    case 3:
        clear();
        calc.solve();
        calc.printSolution();
        std::cout << "Click any button to go back";
        std::cin.get();
        return main();
        break;
    case 4:
        clear();
        calc.printHistory();
        std::cout << "Click any button to go back";
        std::cin.get();
        return main();
    case 5:
        clear();
        calc.clearHistory();
        return main();
    }
}

std::string getOperation(userIO usr)
{
    std::string usrOperation = "";
    std::vector<std::string> validOperations{"+", "-", "*", "/"};
    while (!usr.validateRPN(usrOperation, validOperations) && usrOperation != "quit")
    {
        clear();
        usrOperation = usr.getInput("Please provide valid RPN string (type quit to stop): ");
    }
    return usrOperation;
}