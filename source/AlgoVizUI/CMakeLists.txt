

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "Building ${PROJECT_NAME} UI Components")
add_subdirectory(libs/_AppComponents)

message(STATUS "Building ${PROJECT_NAME} UI Layouts")
add_subdirectory(libs/_AppLayout)

message(STATUS "Building ${PROJECT_NAME} UI Utilities")
add_subdirectory(libs/QBorderLayout)

file(GLOB_RECURSE UI_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_library(
        ${PROJECT_NAME}UI
        ${UI_SOURCES}
    )
else()
    add_library(
        ${PROJECT_NAME}UI 
        ${UI_SOURCES}
    )
endif()


target_link_libraries(${PROJECT_NAME}UI
    PUBLIC
    AlgoVizCore
    UI_AppComponents
    UI_AppLayout
    QBorderLayout
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(
    ${PROJECT_NAME}UI
    PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)