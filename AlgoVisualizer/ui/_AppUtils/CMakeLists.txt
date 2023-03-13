# Export all symbols
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB AppUtils_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

message(STATUS "AppUtils_SRCS: ${AppUtils_SRCS}")

add_library(UI_AppUtils Utils.cpp)

set(AppStyleSheetsPath ${CMAKE_SOURCE_DIR}/AlgoVisualizer/ui/_AppResources/stylesheets/)
set(AppImagesPath ${CMAKE_SOURCE_DIR}/AlgoVisualizer/ui/_AppResources/images/)
set(AppIconsPath ${CMAKE_SOURCE_DIR}/AlgoVisualizer/ui/_AppResources/icons/)
set(AppFontsPath ${CMAKE_SOURCE_DIR}/AlgoVisualizer/ui/_AppResources/fonts/)

# ! THIS COMPILE DEFINITION SHOULD ALWAYS BE PUBLIC TO BE ACCESSIBLE TO ALL TARGETS THAT LINK TO THIS LIBRARY
target_compile_definitions(UI_AppUtils PUBLIC
    APP_STYLESHEETS_PATH="${AppStyleSheetsPath}"
    APP_IMAGES_PATH="${AppImagesPath}"
    APP_ICONS_PATH="${AppIconsPath}"
    APP_FONTS_PATH="${AppFontsPath}"
)

target_include_directories(
    UI_AppUtils
    PUBLIC
    ${CMAKE_SOURCE_DIR}/AlgoVisualizer
)

target_link_libraries(
    UI_AppUtils
    PUBLIC
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Widgets
)
