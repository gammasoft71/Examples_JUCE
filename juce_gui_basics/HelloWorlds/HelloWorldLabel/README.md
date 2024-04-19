# HelloWorldLabel

The classic first application HelloWorld with [juce::Label](https://docs.juce.com/master/classLabel.html) widget.

## Source

[src/HelloWorldLabel.cpp](src/HelloWorldLabel.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldLabel.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldLabel.sln
```

Select `HelloWorldLabel` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldLabel.xcodeproj
```

Select `HelloWorldLabel` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldLabel.cbp > /dev/null 2>&1
```

Select `HelloWorldLabel` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldLabel
```
