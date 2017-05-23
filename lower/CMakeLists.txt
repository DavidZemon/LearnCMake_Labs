add_library(lower SHARED lower.cpp)
target_include_directories(lower PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_compile_definitions(lower PUBLIC "-DLOWER")

add_custom_target(install_lower
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${INSTALL_ROOT}/lib"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:lower>" "${INSTALL_ROOT}/lib")
