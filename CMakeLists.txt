cmake_minimum_required(VERSION 3.22.1)
project(Phones_Statistic C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})