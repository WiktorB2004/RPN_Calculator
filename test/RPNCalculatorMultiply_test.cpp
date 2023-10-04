#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

// ===========================================
// TESTING: RPN Calculator Multiply Test
// ===========================================

TEST(RPNCalculatorMultiply, integerMultiply)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2", "5", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (2 * 5));

    usrOperation = {"29", "52", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (29 * 52));

    usrOperation = {"29", "52", "*", "2", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (29 * 52 * 2));
}

TEST(RPNCalculatorMultiply, floatMultiply)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2.50", "4", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (2.50 * 4));

    usrOperation = {"29.25", "52.98", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (29.25 * 52.98));

    usrOperation = {"29.59", "52.37", "*", "2.25", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (29.59 * 52.37 * 2.25));
}