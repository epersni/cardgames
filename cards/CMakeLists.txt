add_library(cards SHARED "")

add_subdirectory(test)
add_subdirectory(src)
add_subdirectory(include)

set_target_properties(cards PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS cards
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


