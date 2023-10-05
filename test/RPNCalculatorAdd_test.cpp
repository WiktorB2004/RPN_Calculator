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

TEST(RPNCalculatorAdd, intAdd)
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

TEST(RPNCalculatorAdd, floatAdd)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation{"2.25", "2.37", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (2.25 + 2.37));

    usrOperation = {"5.991", "95.12", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (5.991 + 95.12));

    usrOperation = {"3.817", "23.1231", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (3.817 + 23.1231));

    usrOperation = {"0", "2.12", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), 2.12);
}

TEST(RPNCalculatorAdd, CombinedAddition)
{
    RPNCalculator calc;
    std::vector<std::string> usrOperation;

    usrOperation = {"22", "2", "+", "15", "30", "+", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (22 + 2 + 15 + 30));

    usrOperation = {"54", "9", "+", "1", "25", "+", "+"};
    EXPECT_EQ(calc.solveOperation(usrOperation), (54 + 9 + 1 + 25));
}