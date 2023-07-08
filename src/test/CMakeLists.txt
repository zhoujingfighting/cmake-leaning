
file(GLOB_RECURSE test_resoruce CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(arith SHARED ${test_resoruce})
# INTERFACE means, the consumer need to include, but the producer do not
message("==>" ${CMAKE_CURRENT_SOURCE_DIR} "<===")
target_include_directories(
  arith
  INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  arith
  lib_flags
)