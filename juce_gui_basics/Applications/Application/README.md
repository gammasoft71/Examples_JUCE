# Application

Shows how to create a simple JUCE application with [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class.

## Source

* [src/Application.cpp](src/Application.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Application.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Application.sln
```

Select `Application` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Application.xcodeproj
```

Select `Application` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Application.cbp > /dev/null 2>&1
```

Select `Application` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Application
```
