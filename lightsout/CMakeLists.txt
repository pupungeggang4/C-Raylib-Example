cmake_minimum_required(VERSION 3.20)
project(cmake_example LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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

file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" 
)

#file(COPY "${CMAKE_SOURCE_DIR}/asset/font" DESTINATION "${CMAKE_BINARY_DIR}/bin/asset")
file(COPY "${CMAKE_SOURCE_DIR}/asset" DESTINATION "${CMAKE_BINARY_DIR}/bin")

add_executable(main src/main.c ${ALL_SOURCES})
target_include_directories(main PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(main PUBLIC raylib)

if(EMSCRIPTEN)
    set_target_properties(main PROPERTIES OUTPUT_NAME "index" SUFFIX ".html")
    target_compile_options(main PRIVATE -Os)
    target_link_options(main PRIVATE 
        "-sUSE_GLFW=3"
        "-DPLATFORM_WEB" "-sEXPORTED_FUNCTIONS=['_main']" "--preload-file" "${CMAKE_SOURCE_DIR}/asset@asset"
    )
    target_link_libraries(main PRIVATE idbfs.js)
endif()

