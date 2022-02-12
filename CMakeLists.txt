cmake_minimum_required(VERSION 3.2.0)

project(ThreeBodySim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROJECT_SOURCES "src/*.cpp")
add_executable(ThreeBodySim "${PROJECT_SOURCES}")
target_include_directories(ThreeBodySim PUBLIC include)

list(APPEND CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/")
find_package(SFML REQUIRED COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(ThreeBodySim sfml-graphics sfml-audio sfml-network sfml-window sfml-system)