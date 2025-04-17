cmake_minimum_required(VERSION 3.8)

project(cpp_study)

set(PROJECT_NAME cpp_study)

set(CMAKE_CXX_STANDARD 11)              # c++ 11      gcc g++ 版本不支持 c++17
set(CMAKE_CXX_STANDARD_REQUIRED on)     # 要求编译器支持版本，否则报错
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)   # bin 文件生成目录

# 设置本地头文件目录
include_directories(
    include
    ${SUB_INCLUDE_DIR}         # 下层头文件
)

aux_source_directory(.   SRC_LIST)
aux_source_directory(src SRC_LIST)

# 使用下层传递上来的文件来拼接可执行文件
add_executable(${PROJECT_NAME} ${SRC_LIST})

# 获取下层cmakelist文件
add_subdirectory(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

