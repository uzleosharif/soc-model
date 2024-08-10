

cmake_minimum_required(VERSION 3.22)

project(soc-model CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-fsanitize=address -Wall")

add_subdirectory(lib/libcoro/)

add_executable(soc_model src/main.cpp src/soc_model.cpp)
target_include_directories(soc_model PRIVATE include/)
target_link_libraries(soc_model PRIVATE libcoro)
