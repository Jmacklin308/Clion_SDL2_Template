cmake_minimum_required(VERSION 3.27)
project(ProjectOne)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.c)
add_executable(ProjectOne ${SOURCE_FILES})

target_link_libraries(ProjectOne mingw32 SDL2main SDL2)