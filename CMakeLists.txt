cmake_minimum_required(VERSION 3.6)
project(cec13ccode_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        readme.txt
        test_func.cpp DE.cpp DE.h statistics.h Individual.cpp Individual.h DE_mutations.cpp Individual_Operations.cpp)

add_executable(cec13ccode_2 ${SOURCE_FILES})