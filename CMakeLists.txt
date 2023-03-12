cmake_minimum_required(VERSION 3.5)

project(AlgoVisualizer VERSION 1.0 LANGUAGES CXX)


################
# CMake Configs
################

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_BUILD_TYPE Debug)

# set(Qt6EntryPointPrivate_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6EntryPointPrivate)
# set(QT_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6)
# set(Qt6CoreTools_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6CoreTools)
# set(Qt6Core_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6Core)
# set(Qt6GuiTools_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6GuiTools)
# set(Qt6Gui_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6Gui)
# set(Qt6WidgetsTools_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6WidgetsTools)
# set(Qt6Widgets_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6Widgets)
# set(Qt6_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6)
# set(Qt6ZlibPrivate_DIR C:/Qt/6.6.0/mingw_64/lib/cmake/Qt6ZlibPrivate)
# set(WINDEPLOYQT_EXECUTABLE C:/Qt/6.6.0/mingw_64/bin/windeployqt.exe)

if(WIN32)
    if(MSVC)
        set(QT_DIR C:/Qt/6.4.2/msvc2019_64/lib/cmake/Qt6)
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.4.2\\msvc2019_64")
    else()
        set(QT_DIR C:/Qt/6.4.2/mingw_64/lib/cmake/Qt6)
        set(CMAKE_PREFIX_PATH "C:\\Qt\\6.4.2\\mingw_64")
    endif(MSVC)
else(WIN32)
    set(QT_DIR /usr/lib/x86_64-linux-gnu/cmake/Qt6)
    set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt6")
endif(WIN32)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

message(STATUS "Detected Qt version: ${QT_VERSION_MAJOR} (${QT_VERSION})")

set(PROJECT_SOURCES
        src/main.cpp
        src/app/borderlayout.cpp
        src/app/main_window.cpp
#        mainwindow.h
#        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(
    ${PROJECT_NAME} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/algos
    ${CMAKE_CURRENT_SOURCE_DIR}/include/app

    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algos
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
