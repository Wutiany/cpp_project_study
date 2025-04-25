cmake_minimum_required(VERSION 3.16)

project(cpp_study)

set(PROJECT_NAME cpp_study)

set(CMAKE_CXX_STANDARD 11)              # c++ 11      gcc g++ 版本不支持 c++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # 要求编译器支持版本，否则报错
set(CMAKE_CXX_EXTENSIONS ON)

# 静态库目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
# 可执行文件输出目录      
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/bin)
# 动态库目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

# 获取下层cmakelist文件
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(external)
