cmake_minimum_required(VERSION 3.15.0)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}" 
    CACHE PATH "${CMAKE_SOURCE_DIR}/build/")


project("Summer Practice" 
        LANGUAGES C
)

set(MY_PROJECT_EXECUTABLES 
    DoesCircleContainPoint
    ArrayCalculate
    ArraySort
    MatrixCalculate1
    MatrixCalculate2
    MatrixCalculate3
    MatrixCalculate4
    MatrixCalculate5
    Votes
    String1
    UserFunction1
    Recursion
)

foreach(exe ${MY_PROJECT_EXECUTABLES})
    add_executable(${exe} "src/${exe}/main.c")
endforeach()

add_subdirectory(lib)

foreach(exe ${MY_PROJECT_EXECUTABLES})
  target_link_libraries(${exe} my::lib)
endforeach()

install(TARGETS ${MY_PROJECT_EXECUTABLES} DESTINATION "${CMAKE_SOURCE_DIR}/bin/")
