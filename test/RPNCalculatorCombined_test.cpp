#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

// ===========================================
// TESTING: RPN Calculator Combined operations
// ===========================================

TEST(RPNCalculatorCombined, integerOperations)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2", "4", "+", "2", "*", "25", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (6 * 2 + 25));

    usrOperation = {"225", "451", "*", "225", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (451));

    usrOperation = {"225", "451", "+", "225", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (451));
}

TEST(RPNCalculatorCombined, floatOperations)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2.1", "4.25", "+", "2.13", "*", "25.2", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), ((2.1 + 4.25) * 2.13 + 25.2));

    usrOperation = {"225.12", "12.541", "*", "225.12", "/"};
    EXPECT_EQ(calc.solveOperation(usrOperation), 12.541);
}

TEST(RPNCalculatorCombined, negativeOperations)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"-2.1", "4.76", "+", "2.291", "*", "-25.2", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), ((-2.1 + 4.76) * 2.291 + (-25.2)));

    usrOperation = {"-2.1", "-2.25", "-"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (-2.1 + 2.25));

    usrOperation = {"-2", "-2", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), 4);

    usrOperation = {"-2", "-2", "*", "-2", "*"};
    EXPECT_EQ(calc.solveOperation(usrOperation), -8);
}
