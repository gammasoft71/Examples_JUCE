cmake_minimum_required(VERSION 3.22)
project(Others)
if (NOT JUCE_FOUND)
  find_package(JUCE CONFIG REQUIRED)
endif ()

add_subdirectory(ProgressBarCircular)
