function(add_common_test name)
    add_executable(test.common.${name} test_${name}.cpp)

    target_link_libraries(test.common.${name} 
        PRIVATE 
            exercise::common 
            Catch2::Catch2WithMain
    )
endfunction()


add_executable(test.thread_pool test_thread_pool.cpp)
target_link_libraries(test.thread_pool PRIVATE exercise::common)

add_common_test(strings_utility)
add_common_test(lru_cache)
add_common_test(log)
add_common_test(generator)
