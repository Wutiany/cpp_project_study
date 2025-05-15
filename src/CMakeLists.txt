add_executable(main main.cpp)

add_subdirectory(tools)
add_subdirectory(bes)


target_link_libraries(main
    PRIVATE
    tools  
    bes  
    timer
)

target_include_directories(main
PUBLIC
    tools
    bes
    ${CMAKE_SOURCE_DIR}/timer
)