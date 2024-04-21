cmake_minimum_required(VERSION 3.22)

project(Label VERSION 0.0.1)
if (NOT JUCE_FOUND)
  find_package(JUCE CONFIG REQUIRED)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

juce_add_gui_app(${PROJECT_NAME})
juce_generate_juce_header(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/Label.cpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE JUCE_DISPLAY_SPLASH_SCREEN=0)
target_link_libraries(${PROJECT_NAME} PRIVATE juce::juce_gui_basics)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "juce_gui_basics/Widgets")
