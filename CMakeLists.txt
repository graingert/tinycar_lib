# This CMakeLists is not needed when using C++. This is only for Python bindings.
cmake_minimum_required(VERSION 3.5)
project(tinycar_lib)
SET(CMAKE_CXX_FLAGS "-std=c++0x")

set(TINYCAR_DIR ./)
include_directories(${TINYCAR_DIR})
file(GLOB TINYCAR_SOURCES ${TINYCAR_DIR}/*.cpp)

set(PYBIND11_FINDPYTHON ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(OpenCV REQUIRED)
find_package(pybind11 REQUIRED)
find_package(Python 3.12 REQUIRED COMPONENTS Interpreter Development.Module NumPy)

include(CMakePrintHelpers)
cmake_print_variables(Python_NumPy_INCLUDE_DIRS)

execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "import numpy; print(numpy.get_include())" OUTPUT_VARIABLE NUMPY_INCLUDE OUTPUT_STRIP_TRAILING_WHITESPACE)
message(STATUS "NUMPY_INCLUDE: " ${NUMPY_INCLUDE})

add_library(tinycar_lib STATIC ${TINYCAR_SOURCES})
target_link_libraries(tinycar_lib PRIVATE ${OpenCV_LIBS})
target_include_directories(tinycar_lib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/" ${NUMPY_INCLUDE})

pybind11_add_module(tinycar MODULE ${CMAKE_CURRENT_LIST_DIR}/tinycar_python/tinycar_pybindings.cpp ${CMAKE_CURRENT_LIST_DIR}/tinycar_python/ndarray_converter.cpp)
target_link_libraries(tinycar PRIVATE tinycar_lib ${OpenCV_LIBS})
