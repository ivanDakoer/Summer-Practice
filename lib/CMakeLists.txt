project(MYLIB LANGUAGES C)

file(GLOB TARGET_SRC "./src/*.c")
add_library(${PROJECT_NAME} ${TARGET_SRC})
add_library(my::lib ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)   
