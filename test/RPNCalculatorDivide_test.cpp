#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

// ===========================================
// TESTING: RPN Calculator Divide Test
// ===========================================

TEST(RPNCalculatorDivide, integerDivide)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"16", "2", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (16 / 2));

    usrOperation = {"96", "3", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (96 / 3));
}

TEST(RPNCalculatorDivide, floatDivide)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"4", "8", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (double(4) / double(8)));

    usrOperation = {"15.5", "3", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (double(15.5) / double(3)));

    usrOperation = {"15.51", "3.256", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (double(15.51) / double(3.256)));
}