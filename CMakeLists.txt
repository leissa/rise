cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(rise)

# TODO this shouldn't be necessary
if(MSVC)
    set(CMAKE_CXX_STANDARD 23) # /std:c++latest - unlocks non-stable c++20 features
    add_compile_options(/utf-8 /wd4146 /wd4245)
else()
    set(CMAKE_CXX_STANDARD 20) # -std=c++20 for everyone else
endif()

add_subdirectory(thorin2)

add_thorin_dialect(rise
    SOURCES
        rise/rise.h
        rise/rise.cpp
)

# TODO this shouldn't be necessary
target_include_directories(thorin_rise PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)
