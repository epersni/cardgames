option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" ON)

if(ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)
    if(WARNINGS_AS_ERRORS)
      list(APPEND CMAKE_CXX_CLANG_TIDY -warnings-as-errors=*)
    endif()
    
    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
      ${PROJECT_SOURCE_DIR}/src/*.[ch]pp
      ${PROJECT_SOURCE_DIR}/src/*.[ch]
      ${PROJECT_SOURCE_DIR}/include/*.[h]pp
      ${PROJECT_SOURCE_DIR}/include/*.[h]
      )
    message("sources = ${ALL_CXX_SOURCE_FILES}") 
    add_custom_target(
      tidy
      COMMAND /usr/bin/clang-tidy
      -p ./compile_commands.json
      ${ALL_CXX_SOURCE_FILES}
      --
      -I${PROJECT_SOURCE_DIR}/include
      )
  else()
    message(SEND_ERROR "clang-tidy requested but executable not found")
  endif()
endif()
