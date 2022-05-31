#   base
cmake_minimum_required(VERSION 3.5)
project(exercise-7)

#   standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# ################# DEBUG  ################
# set(
#     CMAKE_DEBUG_TARGET_PROPERTIES
#     INCLUDE_DIRECTORIES
#     COMPILE_DEFINITIONS
#     CLASS_VERSION
# )

# #################  library  ################
# #   dependency library
# add_library(lib7 exercise.cpp)
# target_include_directories(lib7 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# #   library version setting
# set_property(TARGET lib7 PROPERTY INTERFACE_CLASS_VERSION 1.0)
# set_property(TARGET lib7 APPEND PROPERTY COMPATIBLE_INTERFACE_STRING INTERFACE_CLASS_VERSION)
# #   library compile macro
# target_compile_definitions(lib7 PUBLIC SHOW_EXERCISE7_H)

# #################  executable  ################
# add_executable(exe7 main.cpp)
# target_link_libraries(exe7 lib7)

add_executable(main main.cpp)