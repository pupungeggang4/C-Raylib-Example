cmake_minimum_required(VERSION 3.20)
project(cmake_example LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(EMSCRIPTEN)
    set(PLATFORM "Web" CACHE STRING "raylib platform")
else()
    set(PLATFORM "Desktop" CACHE STRING "raylib platform")
endif()

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG master
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(PLATFORM ${PLATFORM} CACHE STRING "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(main src/main.c)
target_link_libraries(main raylib)

if(EMSCRIPTEN)
    set_target_properties(main PROPERTIES OUTPUT_NAME "index" SUFFIX ".html")
    target_compile_options(main PRIVATE -Os)
    target_link_options(main PRIVATE 
        "-Os"
        "-sUSE_GLFW=3"
        "-DPLATFORM_WEB"
    )
endif()

