add_executable(test.thread_pool test_thread_pool.cpp)
target_link_libraries(test.thread_pool PRIVATE exercise::common)

add_executable(test.strings_utility test_strings_utility.cpp)
target_link_libraries(test.strings_utility PRIVATE exercise::common Catch2::Catch2WithMain)
