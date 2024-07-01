cmake_minimum_required(VERSION 3.15)


include(FetchContent)
FetchContent_Declare(
    googletest 
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

add_executable(
    runtests
    scanner_tests.cpp

)
target_link_libraries(
    runtests
    GTest::gtest_main
    LOX
)