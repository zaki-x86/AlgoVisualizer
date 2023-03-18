# Export all symbols
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE AppUtils_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

message(STATUS "${PROJECT_NAME}Core: ${AppUtils_SRCS}")

add_library(${PROJECT_NAME}Core ${AppUtils_SRCS})
add_library(${PROJECT_NAME}::Core ALIAS ${PROJECT_NAME}Core)

set(AppStyleSheetsPath ${CMAKE_SOURCE_DIR}/source/AlgoVizUI/resources/stylesheets/)
set(AppImagesPath ${CMAKE_SOURCE_DIR}/source/AlgoVizUI/resources/images/)
set(AppIconsPath ${CMAKE_SOURCE_DIR}/source/AlgoVizUI/resources/icons/)
set(AppFontsPath ${CMAKE_SOURCE_DIR}/source/AlgoVizUI/resources/fonts/)
set(AppDataPath ${CMAKE_SOURCE_DIR}/source/AlgoVizModel/data/)

# ! THIS COMPILE DEFINITION SHOULD ALWAYS BE PUBLIC TO BE ACCESSIBLE TO ALL TARGETS THAT LINK TO THIS LIBRARY
target_compile_definitions(
    ${PROJECT_NAME}Core 
    PUBLIC
    APP_STYLESHEETS_PATH="${AppStyleSheetsPath}"
    APP_IMAGES_PATH="${AppImagesPath}"
    APP_ICONS_PATH="${AppIconsPath}"
    APP_FONTS_PATH="${AppFontsPath}"
    APP_DATA_PATH="${AppDataPath}"
)

target_include_directories(
    ${PROJECT_NAME}Core
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/source
    ${CMAKE_CURRENT_SOURCE_DIR}/source/include
)

target_link_libraries(
    ${PROJECT_NAME}Core
    PUBLIC
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Widgets
)
