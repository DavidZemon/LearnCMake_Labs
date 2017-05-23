cmake_minimum_required(VERSION 2.8)

project(LearnCMake)

option(WARN_ALL "Throw warnings when you write dumb code" ON)
set(FORCE_CASE "UPPER" CACHE STRING "Should the case be forced to upper, lower, or original?")

if (WARN_ALL)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
endif ()

set(INSTALL_ROOT_PARENT "${PROJECT_BINARY_DIR}/custom_install")
set(INSTALL_ROOT "${INSTALL_ROOT_PARENT}/${PROJECT_NAME}")
add_custom_target(install_headers
    COMMAND "${CMAKE_COMMAND}" -E copy_directory "${PROJECT_SOURCE_DIR}/include" "${INSTALL_ROOT}/include")
add_custom_target(my_install
    COMMAND "${CMAKE_COMMAND}" -E tar -czf "${PROJECT_NAME}.tar.gz" "${PROJECT_NAME}"
    COMMAND "${CMAKE_COMMAND}" -E rename "${PROJECT_NAME}.tar.gz" "${PROJECT_BINARY_DIR}/${PROJECT_NAME}.tar.gz"
    WORKING_DIRECTORY "${INSTALL_ROOT_PARENT}"
    DEPENDS install_headers)

set(SUB_DIRECTORIES
    upper
    lower
    useless
    hello)
foreach (dir IN LISTS SUB_DIRECTORIES)
    add_subdirectory("${dir}")
endforeach ()

add_dependencies(my_install install_hello install_hello install_useless install_lower install_upper)
