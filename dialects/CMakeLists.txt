add_thorin_dialect(rise
    SOURCES
        rise/rise.h
        rise/rise.cpp
        rise/normalizers.cpp
)

target_include_directories(thorin_rise PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
