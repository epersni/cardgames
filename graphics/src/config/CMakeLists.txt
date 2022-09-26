cmake_minimum_required(VERSION 3.19)

add_library(graphics_config SHARED "")

add_subdirectory(src)
add_subdirectory(include)

target_include_directories(
    graphics_config 
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
)

#if(NOT TARGET yaml-cpp)
#    find_package(cpp REQUIRED)
#endif()

