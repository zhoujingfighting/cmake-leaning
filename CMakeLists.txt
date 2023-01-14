cmake_minimum_required(VERSION 3.12)
project(cmake_learning)
set(CMAKE_CXX_STANDARD 20)

message("" ${PROJECT_SOURCE_DIR} )
set(ROOT ${PROJECT_SOURCE_DIR})
# need to speciific project name, hence we can get PROJECT_source_dir

# Check system information
if(APPLE)
  link_directories(${PROJECT_SOURCE_DIR}/libs/mac)
elseif(UNIX AND NOT APPLE)
  link_directories(${PROJECT_SOURCE_DIR}/libs/linux)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

set(
  SOURCE_FILES
  main.cpp
)

add_subdirectory(src/test)
link_libraries(arith)
add_executable(
  test
  ${SOURCE_FILES}
)

# specify all the header files for the root whole project
target_include_directories(
  test
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)