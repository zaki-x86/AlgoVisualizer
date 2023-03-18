file(GLOB_RECURSE SRC_FILES source/*.cpp)
file(GLOB_RECURSE INC_FILES source/*.h)

add_library(${PROJECT_NAME}Model ${SRC_FILES})
add_library(${PROJECT_NAME}::Model ALIAS ${PROJECT_NAME}Model)

target_include_directories(
    ${PROJECT_NAME}Model 
    PUBLIC 
    include
)

set_target_properties(
    ${PROJECT_NAME}Model 
    PROPERTIES 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    LINKER_LANGUAGE CXX
)

target_link_libraries(
    ${PROJECT_NAME}Model 
    PRIVATE
    ${PROJECT_NAME}Core
    ${PROJECT_NAME}Control
    ${PROJECT_NAME}UI
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)