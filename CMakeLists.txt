cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(jtlox)

enable_testing()




add_subdirectory(src)
add_subdirectory(tests)

include_directories(${PROJECT_SOURCE_DIR}/include)

