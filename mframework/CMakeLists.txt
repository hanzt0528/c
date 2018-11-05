# 需要最小的CMake版本
cmake_minimum_required(VERSION 3.12.3)
# 工程的名称
project(mframework)
# 设置C++标志位
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# -fPIC则表明使用地址无关代码
add_compile_options(-fPIC)

SET(PROJECT_ROOT_PATH "${CMAKE_SOURCE_DIR}")

SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/")

SET(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib/")

INCLUDE_DIRECTORIES("${PROJECT_ROOT_PATH}/include/")

Link_DIRECTORIES("${CMAKE_SOURCE_DIR}/lib/")

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

ADD_SUBDIRECTORY(src)


# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径

