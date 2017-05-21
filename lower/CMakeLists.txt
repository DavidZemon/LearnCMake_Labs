add_library(lower lower.cpp)
target_include_directories(lower PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_compile_definitions(lower PUBLIC "-DLOWER")
