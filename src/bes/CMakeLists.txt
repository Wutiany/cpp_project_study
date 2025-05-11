add_library(bes "")

target_sources(bes
PRIVATE
    bes.cpp
    bytes.cpp
    file_operator.cpp
PUBLIC
    bes.hpp
    bytes.hpp
    file_operator.hpp
    types.hpp
)

target_include_directories(bes
PUBLIC
${CMAKE_CURRENT_LIST_DIR}
${CMAKE_SOURCE_DIR}/include             # 公共头文件
)

