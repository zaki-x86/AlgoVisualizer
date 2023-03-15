file(GLOB_RECURSE UI_AppLayout_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc
)

file(GLOB_RECURSE UI_AppLayout_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_library(UI_AppLayout
        ${UI_AppLayout_SOURCES}
    )
else()
    add_library(UI_AppLayout
        ${UI_AppLayout_SOURCES}
    )

endif()

target_link_libraries(UI_AppLayout
    PRIVATE
        UI_AppCore
        UI_AppComponents
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(UI_AppLayout
    PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(UI_AppLayout
    PRIVATE
        QT_DEPRECATED_WARNINGS
        QT_DISABLE_DEPRECATED_BEFORE=0x060000
)

set_target_properties(
    UI_AppLayout
    PROPERTIES
        LINKER_LANGUAGE CXX
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_target(UI_AppLayout)
endif()