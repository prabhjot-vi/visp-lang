cmake_minimum_required(VERSION 4.0)

project(visp-lang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
  src/main.cpp
)