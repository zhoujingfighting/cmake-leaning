cmake_minimum_required(VERSION 3.14)
project(cmake_learning VERSION 4.5)

# determine which compiler our system is currently using to build
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(lib_flags INTERFACE)
target_compile_features(lib_flags INTERFACE cxx_std_17)
target_compile_options(lib_flags INTERFACE
"$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
"$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

message(">>>>"${cmake_learning_VERSION_MINOR}"<<<<<"${cmake_learning_VERSION_MAJOR})
configure_file(main.h.in ${PROJECT_SOURCE_DIR}/include/main.h)

set(ROOT ${PROJECT_SOURCE_DIR})
# need to speciific project name, hence we can get PROJECT_source_dir

# Check system information
if(APPLE)
  link_directories(${PROJECT_SOURCE_DIR}/libs/mac)
elseif(UNIX AND NOT APPLE)
  link_directories(${PROJECT_SOURCE_DIR}/libs/linux)
endif()

# Project output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")


set(
  SOURCE_FILES
  main.cpp
)

#  ADD optional args for this program
option(USE_CUMSTOMIZED_LIB "use our customized libraries" OFF)
if(USE_CUMSTOMIZED_LIB)
  add_subdirectory(src/test)
  list(APPEND EATRA_LIBS arith)
endif(USE_CUMSTOMIZED_LIB)

add_subdirectory(src/find-package)

add_executable(
  test
  ${SOURCE_FILES}
)

target_link_libraries(test PUBLIC ${EATRA_LIBS} lib_flags)
# specify all the header files for the root whole project
target_include_directories(
  test
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)