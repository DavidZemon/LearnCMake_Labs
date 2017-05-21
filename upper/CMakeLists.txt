add_library(upper upper.cpp)
target_include_directories(upper PUBLIC "../include")
target_compile_definitions(upper PUBLIC "UPPER")
