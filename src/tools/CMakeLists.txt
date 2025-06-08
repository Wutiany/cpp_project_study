add_library(tools "")

target_sources(tools 
PRIVATE
    hardware.cpp
    network.cpp
PUBLIC
    hardware.hpp
    network.hpp
)

target_include_directories(tools
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)