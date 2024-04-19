# HelloWorldSay

The classic first application HelloWorld with [juce::TextButton](https://docs.juce.com/master/classTextButton.html) widget.

## Source

[src/HelloWorldSay.cpp](src/HelloWorldSay.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldSay.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldSay.sln
```

Select `HelloWorldSay` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldSay.xcodeproj
```

Select `HelloWorldSay` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldSay.cbp > /dev/null 2>&1
```

Select `HelloWorldSay` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldSay
```
