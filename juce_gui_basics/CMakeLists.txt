cmake_minimum_required(VERSION 3.22)
project(juce_gui_basics)
if (NOT JUCE_FOUND)
  find_package(JUCE CONFIG REQUIRED)
endif ()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(HelloWorlds)
add_subdirectory(Applications)
add_subdirectory(Buttons)
add_subdirectory(Widgets)
add_subdirectory(Others)
