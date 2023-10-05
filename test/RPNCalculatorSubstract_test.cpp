#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

// ===========================================
// TESTING: RPN Calculator Substract Test
// ===========================================

TEST(RPNCalculatorSubstract, intSubstract)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2", "5", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (2 - 5));

    usrOperation = {"13", "12", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (13 - 12));

    usrOperation = {"13123", "12123", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (13123 - 12123));

    usrOperation = {"1", "1212", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (1 - 1212));
}

TEST(RPNCalculatorSubstract, floatSubstract)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2.123", "5", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (2.123 - 5));

    usrOperation = {"13.75", "12.28", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (13.75 - 12.28));

    usrOperation = {"13123.22145", "12123.11", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (13123.22145 - 12123.11));

    usrOperation = {"112.4", "1212.001", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (112.4 - 1212.001));
}