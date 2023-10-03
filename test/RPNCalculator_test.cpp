#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

TEST(RPNCalculatorTest, SingleDigitAdd)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2", "2", "+"};
    int res = calc.solveOperation(usrOperation);
    EXPECT_EQ(res, 4);

    usrOperation = {"5", "9", "+"};
    res = calc.solveOperation(usrOperation);
    EXPECT_EQ(res, 14);

    usrOperation = {"3", "5", "+"};
    res = calc.solveOperation(usrOperation);
    EXPECT_EQ(res, 8);

    usrOperation = {"0", "2", "+"};
    res = calc.solveOperation(usrOperation);
    EXPECT_EQ(res, 2);
}