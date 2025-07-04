add_executable(main main.cpp)

add_subdirectory(tools)     # tools 工具函数
add_subdirectory(bes)       # bes 函数模块
add_subdirectory(ui)        # ui 模块
add_subdirectory(signals)   # signals 模块，测试信号代码

target_link_libraries(main
    PRIVATE
    tools  
    bes  
    timer
    ui
    signals
)

target_include_directories(main
PUBLIC
    tools
    bes
    ui
    signals
    ${CMAKE_SOURCE_DIR}/timer
)