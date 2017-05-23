add_library(upper SHARED upper.cpp)
target_include_directories(upper PUBLIC "../include")
target_compile_definitions(upper PUBLIC "UPPER")
target_compile_definitions(upper PRIVATE "$<$<CONFIG:Debug>:TRACE=1>")

add_custom_target(install_upper
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${INSTALL_ROOT}/lib"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:upper>" "${INSTALL_ROOT}/lib")
