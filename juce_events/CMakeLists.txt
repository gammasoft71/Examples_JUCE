cmake_minimum_required(VERSION 3.22)
project(juce_events)
if (NOT JUCE_FOUND)
  find_package(JUCE CONFIG REQUIRED)
endif ()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(Timers)
