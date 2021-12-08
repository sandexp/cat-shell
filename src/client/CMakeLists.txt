# parent cmake list
project(server)
cmake_minimum_required(VERSION 3.2.0)
message("Start to build project " ${PROJECT_NAME})

# add lib
set(CMAKE_CXX_STANDARD 14)

# add source
set(SRC
    ${PROJECT_SOURCE_DIR}/src/client/client.cpp
)


