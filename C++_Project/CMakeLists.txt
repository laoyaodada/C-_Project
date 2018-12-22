# CMakeList.txt: C++_Project 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 当前目录下所有源文件赋给DIR_MAIN
AUX_SOURCE_DIRECTORY(. DIR_MAIN)

# 包含的头文件
include_directories(
    ./Headers
)
# 设置编译器,编译参数，构建类型
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

#生成可执行文件
add_executable(main ${DIR_MAIN})

#添加Src子目录
add_subdirectory(Sources)

#添加链接库
target_link_libraries(main Sources)
