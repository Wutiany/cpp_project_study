add_executable(main main.cpp)

add_subdirectory(tools)
add_subdirectory(bes)


target_link_libraries(main
    PRIVATE
    tools    
)

target_include_directories(main
PUBLIC
    tools
)