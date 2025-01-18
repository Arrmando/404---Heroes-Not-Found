cmake_minimum_required(VERSION 3.14)
project(404/HeroesNotFound)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/libs/cppcoro/include)
link_directories(${CMAKE_SOURCE_DIR}/libs/cppcoro/build/lib)

add_executable(HeroesNotFound src/main.cpp)

target_link_libraries(HeroesNotFound cppcoro)