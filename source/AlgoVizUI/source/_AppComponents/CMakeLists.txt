set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

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
        ${UI_AppComponents_HEADERS}
    )
    add_library(
        AlgoViz::UI::Components 
        ALIAS 
        UI_AppComponents
    )
else()
    add_library(UI_AppComponents
        ${UI_AppComponents_SOURCES}
        
    )
    add_library(
        AlgoViz::UI::Components 
        ALIAS 
        UI_AppComponents
    )

endif()

target_link_libraries(UI_AppComponents
        AlgoVizCore
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(UI_AppComponents
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
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