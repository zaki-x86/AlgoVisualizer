file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB_RECURSE INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.h)

add_library(${PROJECT_NAME}Control ${SRC_FILES})
add_library(${PROJECT_NAME}::Control ALIAS ${PROJECT_NAME}Control)


target_include_directories(
    ${PROJECT_NAME}Control 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/source
    ${CMAKE_CURRENT_SOURCE_DIR}/source/include
)

set_target_properties(
    ${PROJECT_NAME}Control 
    PROPERTIES 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    LINKER_LANGUAGE CXX
)

target_link_libraries(
    ${PROJECT_NAME}Control 
    PRIVATE
    ${PROJECT_NAME}Core
    ${PROJECT_NAME}Model
    ${PROJECT_NAME}UI
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)