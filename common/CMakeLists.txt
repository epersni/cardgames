add_library(cardgamescommon SHARED "")

add_subdirectory(test)
add_subdirectory(src)
add_subdirectory(include)

set_target_properties(cardgamescommon PROPERTIES VERSION ${PROJECT_VERSION})
target_link_libraries(cardgamescommon PRIVATE logging)

install(TARGETS cardgamescommon
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


