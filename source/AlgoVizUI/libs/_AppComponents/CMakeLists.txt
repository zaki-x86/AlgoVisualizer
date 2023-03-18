file(GLOB_RECURSE UI_AppComponents_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc
)

file(GLOB_RECURSE UI_AppComponents_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_library(UI_AppComponents
        ${UI_AppComponents_SOURCES}
    )
else()
    add_library(UI_AppComponents
        ${UI_AppComponents_SOURCES}
    )

endif()

target_link_libraries(UI_AppComponents
    PRIVATE
        AlgoVizCore
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(UI_AppComponents
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}
)

target_compile_definitions(UI_AppComponents
    PRIVATE
        QT_DEPRECATED_WARNINGS
        QT_DISABLE_DEPRECATED_BEFORE=0x060000
)

set_target_properties(
    UI_AppComponents
    PROPERTIES
        LINKER_LANGUAGE CXX
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_target(UI_AppComponents)
endif()