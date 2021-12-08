project(test)

cmake_minimum_required(VERSION 3.2.0)
message("Begin to build " ${PROJECT_NAME})

message("Binary Dir: " ${PROJECT_BINARY_DIR})
message("Source Dir: " ${PROJECT_SOURCE_DIR})

INCLUDE_DIRECTORIES(. /usr/local/include SYSTEM)
LINK_DIRECTORIES(/usr/local/lib /usr/local/lib64 ${PROJECT_BINARY_DIR}/../lib)

enable_testing()

FILE(GLOB_RECURSE ALL_SRC *.cpp)
FOREACH(F ${ALL_SRC})
    get_filename_component(prjName ${F} NAME_WE)
    message("Build ${prjName} from ${F}")
    add_executable(${prjName} ${F})
ENDFOREACH(F)