include(googletest)

add_executable(my_test test_main.cpp)
target_link_libraries(my_test gtest gtest_main pthread)

add_test(test_name my_test)
