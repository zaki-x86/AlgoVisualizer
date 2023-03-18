cmake_minimum_required(VERSION 3.20)

##################################################################################
# Project details

# TODO: Add project documentation website in HOMEPAGE_URL
# TODO : Add project description
# TODO: Configure automated version adjustment from a version.txt file
##################################################################################

project(
  AlgoViz
  VERSION 0.1.0
  DESCRIPTION ""
  LANGUAGES CXX
)

##################################################################################
# MAIN_PROJECT CHECK

# determine if project is built as a subproject (using add_subdirectory) or if it is the main project
##################################################################################

set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
    message(STATUS "AlgoViz is being built as a main project")
endif()

##################################################################################
# Setup the include path
##################################################################################

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake ${CMAKE_MODULE_PATH})
message(STATUS "Module path is set to: ${CMAKE_MODULE_PATH}")
# include(Utils)
# include(CompilerWarnings)

##################################################################################
# set project options
##################################################################################

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  if (UNIX OR MINGW OR CMAKE_COMPILER_IS_GNUCXX )    
    add_compile_options("$<$<CONFIG:DEBUG>:-D_DEBUG>")    #this will allow to use same _DEBUG macro available in both Linux as well as Windows - MSCV environment. Easy to put Debug specific code.
  endif()  
  message(STATUS "_DEBUG macro is added for debugging specific code\n")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

#
# Prevent building in the source directory
#

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

##################################################################################
# Add configuration related header files
##################################################################################

# TODO: Add configuration related header files

##################################################################################
# Qt Configurations
##################################################################################
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

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
##################################################################################
# Setup target, library and executable output directories
##################################################################################

file(GLOB_RECURSE SOURCE_FILES source/*.cpp)
file(GLOB_RECURSE HEADER_FILES source/*.h)

message(STATUS "Found the following source files: ")
foreach(SOURCE_FILE ${SOURCE_FILES})
  message(STATUS "  ${SOURCE_FILE}")
endforeach()

message(STATUS "Found the following header files: ")
foreach(HEADER_FILE ${HEADER_FILES})
  message(STATUS "  ${HEADER_FILE}")
endforeach()

message(STATUS "Building ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

message(STATUS "Setting up ${PROJECT_NAME}Core facilities...\n")
add_subdirectory(source/${PROJECT_NAME}Core)
if(TARGET ${PROJECT_NAME}Core)
  message(STATUS "Configured ${PROJECT_NAME}Core target...\n")
endif()

message(STATUS "Setting up ${PROJECT_NAME}Control...\n")
add_subdirectory(source/${PROJECT_NAME}Control)
if(TARGET ${PROJECT_NAME}Control)
  message(STATUS "Configured ${PROJECT_NAME}Control target...\n")
endif()

message(STATUS "Setting up UI...\n")
add_subdirectory(source/${PROJECT_NAME}UI)
if(TARGET ${PROJECT_NAME}UI)
  message(STATUS "Configured ${PROJECT_NAME}UI target...\n")
endif(TARGET ${PROJECT_NAME}UI)

message(STATUS "Setting up ${PROJECT_NAME}Model...\n")
add_subdirectory(source/${PROJECT_NAME}Model)
if(TARGET ${PROJECT_NAME}Model)
  message(STATUS "Configured ${PROJECT_NAME}Model target...\n")
endif(TARGET ${PROJECT_NAME}Model)


message(STATUS "Setting up executable target...\n")
add_executable(${PROJECT_NAME} source/main.cpp)

if(TARGET ${PROJECT_NAME})

    target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})

    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

    target_link_libraries(
      ${PROJECT_NAME} 
      PRIVATE 
      ${PROJECT_NAME}UI 
      ${PROJECT_NAME}Model
      ${PROJECT_NAME}Control
      ${PROJECT_NAME}Core 
      Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    )
    
    target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)  
    
    if(MSVC)
      set_target_properties(
      ${PROJECT_NAME}
      PROPERTIES
      LINKER_LANGUAGE CXX
      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
      )
    else()
      set_target_properties(
      ${PROJECT_NAME}
      PROPERTIES
      LINKER_LANGUAGE CXX
      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
      )
    endif()
endif()

if(TARGET ${PROJECT_NAME})
  message(STATUS "Configured ${PROJECT_NAME} target...\n")
endif()


##################################################################################
# Enable Doxygen

## TODO : Export xml docs
##################################################################################

# include(Doxygen)

##################################################################################
# Unit testing setup

## TODO Add unit testing setup
##################################################################################

if(EnableTesting)
  enable_testing()
  verbose_message("Build unit tests for the project. Tests should always be found in the test folder\n")
  add_subdirectory(test)
endif()
