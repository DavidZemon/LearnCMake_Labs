add_executable(HelloWorld main.cpp)
target_link_libraries(HelloWorld useless "${REVERSE_LIBRARY}")
target_include_directories(HelloWorld PRIVATE "${REVERSE_INCLUDE_DIR}")

add_custom_target(install_hello
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${INSTALL_ROOT}/bin"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:HelloWorld>" "${INSTALL_ROOT}/bin")
