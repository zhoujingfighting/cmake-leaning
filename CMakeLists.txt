cmake_minimum_required(VERSION 3.12)
project(cmake_learning)
set(CMAKE_CXX_STANDARD 11)
configure_file(main.h.in ${PROJECT_SOURCE_DIR}/include/main.h)
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

#  ADD optional args for this program
option(USE_CUMSTOMIZED_LIB "use our customized libraries" on)
if(USE_CUMSTOMIZED_LIB)
  add_subdirectory(src/test)
  list(APPEND EATRA_LIBS arith)
  list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/src)
endif(USE_CUMSTOMIZED_LIB)

add_executable(
  test
  ${SOURCE_FILES}
)

target_link_libraries(test PUBLIC ${EATRA_LIBS})
# specify all the header files for the root whole project
target_include_directories(
  test
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${EXTRA_INCLUDES}
)