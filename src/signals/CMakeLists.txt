add_library(signals "")


target_sources(signals
PRIVATE
    signals.cpp
PUBLIC
    signals.hpp
    signal_common.hpp
    
)

target_include_directories(signals
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)