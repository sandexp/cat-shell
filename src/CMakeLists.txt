# parent cmake list
project(cat-shell)
cmake_minimum_required(VERSION 3.2.0)
message("Start to build project " ${PROJECT_NAME})

# add lib
set(CMAKE_CXX_STANDARD 14)

# add sub-module
message("Config client and server...")
add_subdirectory(client)
add_subdirectory(server)
