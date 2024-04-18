cmake_minimum_required(VERSION 3.22)
project(Applications)
if (NOT JUCE_FOUND)
  find_package(JUCE REQUIRED)
endif ()

add_subdirectory(Application)
add_subdirectory(ApplicationAndException)
add_subdirectory(ApplicationUsingNativeTitleBar)
