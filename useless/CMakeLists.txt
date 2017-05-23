add_library(useless SHARED useless.cpp messages.cpp)
target_include_directories(useless PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(useless PUBLIC "${PROJECT_SOURCE_DIR}/include")
if (LOWER STREQUAL FORCE_CASE)
    target_link_libraries(useless lower)
elseif (UPPER STREQUAL FORCE_CASE)
    target_link_libraries(useless upper)
endif ()

add_custom_target(install_useless
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${INSTALL_ROOT}/lib"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:useless>" "${INSTALL_ROOT}/lib")
