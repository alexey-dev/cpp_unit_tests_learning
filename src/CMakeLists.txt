cmake_minimum_required(VERSION 3.11)

project(TestMockStub)
set (LOGIC_SOURCES SchoolEntities.cpp Logger.cpp Notifier.cpp)
set (CMAKE_CXX_STANDARD 11)

add_executable(Main.o main.cpp ${LOGIC_SOURCES})
include_directories(tests)
add_subdirectory(tests)
