add_executable(main main.cpp)

add_subdirectory(tools)     # tools 工具函数
add_subdirectory(bes)       # bes 函数模块
add_subdirectory(ui)        # ui 模块

target_link_libraries(main
    PRIVATE
    tools  
    bes  
    timer
    ui
)

target_include_directories(main
PUBLIC
    tools
    bes
    ui
    ${CMAKE_SOURCE_DIR}/timer
)