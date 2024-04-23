# ArrowButton

Shows how to create a ArrowButton widget with [juce::ArrowButton](https://docs.juce.com/master/classArrowButton.html) widgets.

## Source

* [src/ArrowButton.cpp](src/ArrowButton.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ArrowButton.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ArrowButton.sln
```

Select `ArrowButton` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ArrowButton.xcodeproj
```

Select `ArrowButton` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ArrowButton.cbp > /dev/null 2>&1
```

Select `ArrowButton` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ArrowButton
```
