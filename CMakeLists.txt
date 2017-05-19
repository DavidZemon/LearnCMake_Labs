cmake_minimum_required(VERSION 2.8)

project(LearnCMake)

option(WARN_ALL "Throw warnings when you write dumb code" ON)
if (WARN_ALL)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
endif ()

add_library(upper upper/upper.cpp)
target_include_directories(upper PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(useless useless/useless.cpp useless/messages.cpp)
target_include_directories(useless PRIVATE "${PROJECT_SOURCE_DIR}/useless")
target_include_directories(useless PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(useless upper)

add_executable(HelloWorld main.cpp)
target_link_libraries(HelloWorld useless)
