# AlgoViz::UI::WindowClient
## Description
# This class is the launcher of the GUI. It initializes the GUI and the main window.

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE UI_WindowClient_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc
)

file(GLOB_RECURSE UI_WindowClient_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_library(UI_WindowClient
        ${UI_WindowClient_SOURCES}
        ${UI_WindowClient_HEADERS}
    )
    add_library(
        AlgoViz::UI::WindowClient
        ALIAS 
        UI_WindowClient
    )
else()
    add_library(UI_WindowClient
        ${UI_WindowClient_SOURCES}
        
    )
    add_library(
        AlgoViz::UI::WindowClient
        ALIAS 
        UI_WindowClient
    )

endif()

target_link_libraries(UI_WindowClient
        AlgoVizCore
        AlgoViz::UI::Components
        AlgoViz::UI::Layout
        AlgoViz::UI::GraphicalViews
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(UI_WindowClient
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(UI_WindowClient
    PRIVATE
        QT_DEPRECATED_WARNINGS
        QT_DISABLE_DEPRECATED_BEFORE=0x060000
)

set_target_properties(
    UI_WindowClient
    PROPERTIES
        LINKER_LANGUAGE CXX
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_target(UI_WindowClient)
endif()