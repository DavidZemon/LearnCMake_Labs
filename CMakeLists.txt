cmake_minimum_required(VERSION 2.8)

project(LearnCMake)

option(WARN_ALL "Throw warnings when you write dumb code" ON)
set(FORCE_CASE "UPPER" CACHE STRING "Should the case be forced to upper, lower, or original?")

if (WARN_ALL)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
endif ()

add_subdirectory(upper)
add_subdirectory(lower)
add_subdirectory(useless)
add_subdirectory(hello)
