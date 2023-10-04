#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

// ===========================================
// TESTING: RPN Calculator Multiply Test
// ===========================================

TEST(RPNCalculatorMultiply, singleDigitMultiply)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2", "5", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (2 * 5));
}