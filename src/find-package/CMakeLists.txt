
find_package(OpenCL REQUIRED)
message(STATUS ${OpenCL_INCLUDE_DIRS})
message(STATUS ${OpenCL_FOUND})
message(STATUS ${OpenCL_LIBRARIES})
message(STATUS ${OpenCL_VERSION_MAJOR})
message(STATUS ${OpenCL_VERSION_MINOR})


set(SOURCE_FILE index.cl)

add_executable(index ${SOURCE_FILE})