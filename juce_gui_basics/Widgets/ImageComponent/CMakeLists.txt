cmake_minimum_required(VERSION 3.22)

project(ImageComponent VERSION 0.0.1)
if (NOT JUCE_FOUND)
  find_package(JUCE CONFIG REQUIRED)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/logo.png ${CMAKE_CURRENT_BINARY_DIR}/ImageComponent_artefacts/resources/logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/logo.png ${CMAKE_CURRENT_BINARY_DIR}/ImageComponent_artefacts/Debug/resources/logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/logo.png ${CMAKE_CURRENT_BINARY_DIR}/ImageComponent_artefacts/Release/resources/logo.png COPYONLY)

juce_add_gui_app(${PROJECT_NAME})
juce_generate_juce_header(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/ImageComponent.cpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE JUCE_DISPLAY_SPLASH_SCREEN=0)
target_link_libraries(${PROJECT_NAME} PRIVATE juce::juce_gui_basics)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "juce_gui_basics/Widgets")
