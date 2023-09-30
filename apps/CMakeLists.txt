add_executable(app main.cpp)
target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE calculator)
target_link_libraries(app PRIVATE RPN_Calculator)
target_link_libraries(app PRIVATE userIO)
