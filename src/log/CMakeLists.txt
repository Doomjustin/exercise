set(LOG_INCLUDE_DIR ${EXERCISE_INTERNAL_INCLUDE_DIR}/log)

add_library(exercise_log OBJECT
    ${LOG_INCLUDE_DIR}/appender.h
    ${LOG_INCLUDE_DIR}/base_logger.h
    ${LOG_INCLUDE_DIR}/console_appender.h
    ${LOG_INCLUDE_DIR}/entry.h
    ${LOG_INCLUDE_DIR}/formatter.h
    ${LOG_INCLUDE_DIR}/simple_formatter.h
    base_logger.cpp
    console_appender.cpp
    formattable_appender.cpp
    simple_formatter.cpp
)

add_library(exercise::log ALIAS exercise_log)

target_include_directories(exercise_log PUBLIC ${EXERCISE_INCLUDE_DIR})

target_link_libraries(exercise_log
    PUBLIC 
        exercise::base
)