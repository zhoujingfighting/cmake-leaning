
set(SOURCE_FILES test.cpp)
add_library(arith SHARED ${SOURCE_FILES})
# INTERFACE means, the consumer need to include, but the producer do not
message("==>"${CMAKE_CURRENT_SOURCE_DIR}"<===")
target_include_directories(
  arith
  INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  arith
  lib_flags
)