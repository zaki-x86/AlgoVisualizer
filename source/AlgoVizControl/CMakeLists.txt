file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE INC_FILES include/*.h)

add_library(${PROJECT_NAME}Control ${SRC_FILES})

target_include_directories(
    ${PROJECT_NAME}Control 
    PUBLIC 
    include
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