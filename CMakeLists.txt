cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}" 
    CACHE PATH "${CMAKE_SOURCE_DIR}/build/")


project("Summer Practice" 
        LANGUAGES C
)

set(MY_PROJECT_EXECUTABLES 
    1
    2.1 2.2
    3.1 3.2 3.3
    4.2
    5
    6.1 6.2
    7.1 7.2
    8
    9
    10
    11
    12
    13.1 13.2
    14.1 14.2 14.3
)

foreach(exe ${MY_PROJECT_EXECUTABLES})
    add_executable(${exe} "src/${exe}/main.c")
endforeach()

add_subdirectory(lib)

foreach(exe ${MY_PROJECT_EXECUTABLES})
  target_link_libraries(${exe} my::lib)
endforeach()

install(TARGETS ${MY_PROJECT_EXECUTABLES} DESTINATION "${CMAKE_SOURCE_DIR}/bin/")
