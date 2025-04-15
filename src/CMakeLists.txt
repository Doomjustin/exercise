set(EXERCISE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/)
set(EXERCISE_INTERNAL_INCLUDE_DIR ${EXERCISE_INCLUDE_DIR}/exercise)

configure_file(config.h.in ${PROJECT_SOURCE_DIR}/include/exercise/config.h @ONLY)


add_library(exercise_base INTERFACE)

add_library(exercise::base ALIAS exercise_base)

target_link_libraries(exercise_base INTERFACE base)

target_include_directories(exercise_base INTERFACE ${EXERCISE_INCLUDE_DIR})

target_compile_features(exercise_base INTERFACE cxx_std_23)

target_compile_definitions(exercise_base 
    INTERFACE
        $<$<CONFIG:Debug>:EXERCISE_DEBUG>
)


add_subdirectory(log)

add_library(exercise_common STATIC
    ${EXERCISE_INTERNAL_INCLUDE_DIR}/cache.h
    ${EXERCISE_INTERNAL_INCLUDE_DIR}/config.h
    ${EXERCISE_INTERNAL_INCLUDE_DIR}/log.h
    ${EXERCISE_INTERNAL_INCLUDE_DIR}/noncopyable.h
    ${EXERCISE_INTERNAL_INCLUDE_DIR}/thread_pool.h
    ${EXERCISE_INTERNAL_INCLUDE_DIR}/utility.h
    ${EXERCISE_INTERNAL_INCLUDE_DIR}/value.h
    log.cpp
    thread_pool.cpp
)

add_library(exercise::common ALIAS exercise_common)

target_link_libraries(exercise_common 
    PUBLIC 
        exercise::base
        exercise::log
)
