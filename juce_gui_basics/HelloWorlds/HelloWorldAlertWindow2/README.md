# HelloWorldAlertWindow2

The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.

## Source

[src/HelloWorldAlertWindow2.cpp](src/HelloWorldAlertWindow2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldAlertWindow2.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldAlertWindow2.sln
```

Select `HelloWorldAlertWindow2` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldAlertWindow2.xcodeproj
```

Select `HelloWorldAlertWindow2` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldAlertWindow2.cbp > /dev/null 2>&1
```

Select `HelloWorldAlertWindow2` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldAlertWindow2
```
