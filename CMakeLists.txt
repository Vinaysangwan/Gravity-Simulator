cmake_minimum_required(VERSION 3.28)
project(GravitySim LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  src/**.c
  include/**.h
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

# sub directories
add_subdirectory(vendor)

# include directories
target_include_directories(${PROJECT_NAME} PRIVATE
  include
)

# packages
find_package(OPENGL REQUIRED)

# link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
  glfw
  glad
  OpenGL::GL
)
