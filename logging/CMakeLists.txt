cmake_minimum_required(VERSION 3.19)

add_library(logging STATIC "")

add_subdirectory(src)
add_subdirectory(include)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

target_link_libraries(logging PUBLIC spdlog::spdlog)

install(TARGETS cards
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

