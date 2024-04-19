cmake_minimum_required(VERSION 3.22)

# Project
project(HelloWorldPaint)
set(SOURCES
  src/HelloWorldPaint.cpp
)
source_group(src FILES ${SOURCES})
if (NOT JUCE_FOUND)
  find_package(JUCE REQUIRED)
endif ()

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Application properties
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})
target_compile_definitions(${PROJECT_NAME} PRIVATE JUCE_DISPLAY_SPLASH_SCREEN=0)
target_link_libraries(${PROJECT_NAME} juce::juce_gui_basics)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "juce_gui_basics/HelloWorlds")
