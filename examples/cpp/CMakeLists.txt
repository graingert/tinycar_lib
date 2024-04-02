cmake_minimum_required(VERSION 3.8)
project(tinycar_lib_example C CXX)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3")

set(TINYCAR_DIR ../../)
include_directories(${TINYCAR_DIR})
file(GLOB TINYCAR_SOURCES ${TINYCAR_DIR}/*.cpp)

find_package( OpenCV REQUIRED )

add_executable(tinycar_lib_example main.cpp ${TINYCAR_SOURCES})
target_link_libraries(tinycar_lib_example PUBLIC ${OpenCV_LIBS})
target_compile_features(tinycar_lib_example PRIVATE cxx_std_17)
target_include_directories(tinycar_lib_example PUBLIC ${TINYCAR_DIR})