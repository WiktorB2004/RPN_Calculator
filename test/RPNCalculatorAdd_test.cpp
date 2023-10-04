#include <gtest/gtest.h>
#include "../include/calculator.h"
#include "../include/RPN-Calculator.h"

// ===========================================
// TESTING: RPN Calculator Addition Test
// ===========================================

TEST(RPNCalculatorTest, EmptyInput)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{};
    EXPECT_EQ(calc.solveOperation(usrOperation), 0);
}

TEST(RPNCalculatorAdd, SingleDigitAdd)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2", "2", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), 4);

    usrOperation = {"5", "9", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), 14);

    usrOperation = {"3", "5", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), 8);

    usrOperation = {"0", "2", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), 2);
}

TEST(RPNCalculatorAdd, DifferentDigitAdd)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"22", "2", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (22 + 2));

    usrOperation = {"54", "9", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (54 + 9));

    usrOperation = {"360", "54", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (360 + 54));

    usrOperation = {"102", "2", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (102 + 2));

    usrOperation = {"50000", "20198", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (50000 + 20198));
}

TEST(RPNCalculatorAdd, MultiAddition)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation;

    usrOperation = {"22", "2", "+", "15", "30", "+", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (22 + 2 + 15 + 30));

    usrOperation = {"54", "9", "+", "1", "25", "+", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (54 + 9 + 1 + 25));
}