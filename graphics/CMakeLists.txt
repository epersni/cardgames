add_library(graphics SHARED "")

find_package (SFML REQUIRED system window graphics)
#target_include_directories(graphics PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(graphics 
                      PUBLIC 
                      graphics_config
                      sfml-graphics 
                      sfml-window 
                      blackjackgame)
add_subdirectory(src)
add_subdirectory(include)

set_target_properties(graphics PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS graphics
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
