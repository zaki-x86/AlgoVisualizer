

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS ON)

message(STATUS "Building ${PROJECT_NAME} UI Components")
add_subdirectory(source/_AppComponents)

message(STATUS "Building ${PROJECT_NAME} UI Layouts")
add_subdirectory(source/_AppLayout)

message(STATUS "Building ${PROJECT_NAME} UI Graphical Views")
add_subdirectory(source/_GraphicalViews)

message(STATUS "Building ${PROJECT_NAME} UI Window Client")
add_subdirectory(source/_WindowClient)

message(STATUS "Building ${PROJECT_NAME} UI Utilities")
add_subdirectory(source/QBorderLayout)


if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_library(
        ${PROJECT_NAME}UI
        INTERFACE
    )
    add_library(
        ${PROJECT_NAME}::UI
        ALIAS
        ${PROJECT_NAME}UI
    )
else()
    add_library(
        ${PROJECT_NAME}UI 
        INTERFACE
    )
    add_library(
        ${PROJECT_NAME}::UI
        ALIAS
        ${PROJECT_NAME}UI
    )
endif()


target_link_libraries(
    ${PROJECT_NAME}UI
    INTERFACE
    AlgoViz::Core
    AlgoViz::UI::WindowClient
    AlgoViz::UI::Components
    AlgoViz::UI::Layout
    AlgoViz::UI::GraphicalViews
    QBorderLayout
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)
