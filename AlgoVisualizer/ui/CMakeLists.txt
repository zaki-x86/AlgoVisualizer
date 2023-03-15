

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "Building ${PROJECT_NAME} UI Components")
add_subdirectory(_AppComponents)

message(STATUS "Building ${PROJECT_NAME} UI Layouts")
add_subdirectory(_AppLayout)

message(STATUS "Building ${PROJECT_NAME} UI Utilities")
add_subdirectory(_AppCore)


if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_library(
        ${PROJECT_NAME}_UI
        INTERFACE
    )
else()
    add_library(
        ${PROJECT_NAME}_UI 
        INTERFACE
    )
endif()



target_link_libraries(${PROJECT_NAME}_UI
    INTERFACE
    UI_AppComponents
    UI_AppLayout
    UI_AppCore
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(
    ${PROJECT_NAME}_UI
    INTERFACE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)