add_executable(main main.cpp)

add_subdirectory(tools)

target_link_libraries(main
    PRIVATE
    tools    
)

target_include_directories(main
PUBLIC
    tools
)