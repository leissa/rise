add_thorin_plugin(rise
    SOURCES
        rise.cpp
        normalizers.cpp
)

target_include_directories(thorin_rise PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(thorin_rise PUBLIC thorin::libthorin)
