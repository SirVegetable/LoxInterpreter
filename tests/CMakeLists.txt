cmake_minimum_required(VERSION 3.15)


include(FetchContent)
FetchContent_Declare(
    googletest 
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

add_executable(runtests tests_main.cpp)

target_link_libraries(runtests gtest gtest_main)

target_include_directories(runtests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_test(NAME runtests COMMAND runtests)
