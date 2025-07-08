add_library(ui "")

target_sources(ui
PRIVATE 
    ui.cpp
    widget.cpp 
PUBLIC
    ui.hpp
    widget.hpp
    ui_common.hpp
)

target_link_directories(ui
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

# 设置搜索 qt 的路径
set(CMAKE_PREFIX_PATH)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

target_link_libraries(ui
    Qt5::Widgets
    Qt5::Core
)

