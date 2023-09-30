add_library(calculator)
target_sources(calculator PRIVATE calculator.cpp PUBLIC ${HEADER_LIST})
target_include_directories(calculator PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(RPN_Calculator)
target_sources(RPN_Calculator PRIVATE RPN-calculator.cpp PUBLIC ${HEADER_LIST})
target_include_directories(RPN_Calculator PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(userIO)
target_sources(userIO PRIVATE userIO.cpp PUBLIC ${HEADER_LIST})
target_include_directories(userIO PUBLIC "${PROJECT_SOURCE_DIR}/include")