cmake_minimum_required(VERSION 3.22)
project(HelloWorlds)
if (NOT JUCE_FOUND)
  find_package(JUCE REQUIRED)
endif ()

add_subdirectory(HelloWorldAlertWindow)
add_subdirectory(HelloWorldAlertWindow2)
add_subdirectory(HelloWorldJUCE)
add_subdirectory(HelloWorldLabel)
add_subdirectory(HelloWorldNativeMessageBox)
add_subdirectory(HelloWorldNativeMessageBox2)
add_subdirectory(HelloWorldPaint)
add_subdirectory(HelloWorldSay)
