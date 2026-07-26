project(glad LANGUAGES C)

file(GLOB_RECURSE SRC_FILES
  src/**.c
  include/**.h
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
  include
)
