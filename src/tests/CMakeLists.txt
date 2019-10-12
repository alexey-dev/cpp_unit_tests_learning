cmake_minimum_required(VERSION 3.11)

project(TestMockStub)
set (TEST_SOURCES SchoolTests.cpp PupilsTests.cpp PaymentLogicTests.cpp)
set (LOGIC_SOURCES ../SchoolEntities.cpp)
set (CMAKE_CXX_STANDARD 11)

add_executable(TestsMain.o main.cpp ${TEST_SOURCES} ${LOGIC_SOURCES})

SET(GCC_COVERAGE_COMPILE_FLAGS "--coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "--coverage")


#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

include_directories(/Users/alexusachov/git/cpputest/include ../../src)
target_link_libraries(TestsMain.o PRIVATE /Users/alexusachov/git/cpputest/lib/libCppUTest.a /Users/alexusachov/git/cpputest/lib/libCppUTestExt.a)
