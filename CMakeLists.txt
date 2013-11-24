cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(myitk)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(myitk myitk.cpp)
target_link_libraries(myitk ${ITK_LIBRARIES})
