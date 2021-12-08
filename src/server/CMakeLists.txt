# parent cmake list
project(server)
cmake_minimum_required(VERSION 3.2.0)
message("Start to build project " ${PROJECT_NAME})

# add lib
set(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE ALL_SRC *.cpp *.c)
FILE(GLOB MAIN_SRC server.cpp)

FOREACH(F ${ALL_SRC})
    IF (NOT ${F} STREQUAL ${MAIN_SRC})
        SET(LIB_SRC ${LIB_SRC} ${F})
    ENDIF()
ENDFOREACH()

# add target
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# set(BOOST_ROOT "/usr/local/src/boost")
# set(GLOBAL_LIB "/usr/local/lib")
message("Binary Output Dir: " ${EXECUTABLE_OUTPUT_PATH})

# include_directories(/usr/local/include/boost)
# link_directories(/usr/local/lib ${PROJECT_BINARY_DIR}/lib /usr/local/lib)

add_executable(${PROJECT_NAME} ${ALL_SRC})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
message("Archive Directory:" ${LIBRARY_OUTPUT_PATH})

add_library(${PROJECT_NAME}_static STATIC ${LIB_SRC})
set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# target_link_libraries(server ${GLOBAL_LIB}/libboost_regex.a)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
)

