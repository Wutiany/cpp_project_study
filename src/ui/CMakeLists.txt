add_library(ui "")

target_sources(ui
PRIVATE
    ui.hpp
PUBLIC
    ui.cpp
)

# 设置搜索 qt 的路径
set(CMAKE_PREFIX_PATH )
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

target_link_libraries(ui
    Qt5::Widgets
    Qt5::Core
)

