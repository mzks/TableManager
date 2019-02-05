cmake_minimum_required(VERSION 3.8)

add_subdirectory(source)
add_custom_target(alltar DEPENDS source)