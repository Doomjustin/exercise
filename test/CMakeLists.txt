add_executable(test.thread_pool test_thread_pool.cpp)
target_link_libraries(test.thread_pool PRIVATE exercise::common)

# include(CTest)
# include(Catch)
# catch_discover_tests(tests)