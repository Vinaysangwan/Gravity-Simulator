cmake_minimum_required(VERSION 3.28)
project(GravitySim LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  src/**.c
  include/**.h
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

# Sub Directories
add_subdirectory(vendor)

target_include_directories(${PROJECT_NAME} PRIVATE
  include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  glfw
)
