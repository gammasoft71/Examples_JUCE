# HelloWorldAlertWindow

The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.

## Source

* [src/HelloWorldAlertWindow.cpp](src/HelloWorldAlertWindow.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldAlertWindow.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldAlertWindow.sln
```

Select `HelloWorldAlertWindow` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldAlertWindow.xcodeproj
```

Select `HelloWorldAlertWindow` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldAlertWindow.cbp > /dev/null 2>&1
```

Select `HelloWorldAlertWindow` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldAlertWindow
```
