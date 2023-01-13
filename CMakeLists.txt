cmake_minimum_required(VERSION 3.12)

project(cmake_learning)

set(
  SOURCE_FILES
  main.cpp
)

add_executable(
  test
  ${SOURCE_FILES}
)