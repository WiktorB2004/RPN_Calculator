#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

// ===========================================
// TESTING: RPN Calculator Divide Test
// ===========================================

TEST(RPNCalculatorDivide, singleDigitDivide)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"8", "4", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (8 / 4));
}