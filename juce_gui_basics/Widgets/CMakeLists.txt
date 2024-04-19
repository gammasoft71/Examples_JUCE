cmake_minimum_required(VERSION 3.22)
project(Widgets)
if (NOT JUCE_FOUND)
  find_package(JUCE REQUIRED)
endif ()

add_subdirectory(ComboBox)
add_subdirectory(ImageComponent)
add_subdirectory(Label)
