# ADD TEST
add_executable(
  RPNCalculator_test
  RPNCalculatorAdd_test.cpp
  RPNCalculatorSubstract_test.cpp
  RPNCalculatorMultiply_test.cpp
  RPNCalculatorDivide_test.cpp
)

target_link_libraries(
  RPNCalculator_test
  RPN_Calculator
)

target_link_libraries(
  RPNCalculator_test
  calculator
)

target_link_libraries(
  RPNCalculator_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(RPNCalculator_test)
