add_library(timer "")

target_sources(timer
PRIVATE
    watch.cpp
PUBLIC
    watch.hpp
)


target_include_directories(timer
PUBLIC
${CMAKE_CURRENT_LIST_DIR}
)

