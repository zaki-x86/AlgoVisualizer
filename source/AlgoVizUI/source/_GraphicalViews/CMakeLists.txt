set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE VIEWS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc
)

file(GLOB_RECURSE VIEWS_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_library(UI_GraphicalViews
        ${UI_AppComponents_SOURCES}
        ${UI_AppComponents_HEADERS}
    )
    add_library(
        AlgoViz::UI::GraphicalViews 
        ALIAS 
        UI_GraphicalViews
    )
else()
    add_library(UI_GraphicalViews
        ${UI_AppComponents_SOURCES}
        
    )
    add_library(
        AlgoViz::UI::GraphicalViews 
        ALIAS 
        UI_GraphicalViews
    )
endif()

target_link_libraries(
    UI_GraphicalViews
    AlgoVizCore
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(
    UI_GraphicalViews
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(
    UI_GraphicalViews
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_target(UI_GraphicalViews)
endif()