add_executable(hello_test hello_test.cc)
target_link_libraries(hello_test 
    PRIVATE 
        format 
        GTest::gtest 
        GTest::gtest_main
)
gtest_discover_tests(hello_test)
