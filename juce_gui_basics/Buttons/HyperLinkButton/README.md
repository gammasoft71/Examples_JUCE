# HyperLinkButton

Shows how to create a HyperLinkButton widget with [juce::HyperLinkButton](https://docs.juce.com/master/classHyperLinkButton.html) widgets.

## Source

* [src/HyperLinkButton.cpp](src/HyperLinkButton.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HyperLinkButton.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HyperLinkButton.sln
```

Select `HyperLinkButton` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HyperLinkButton.xcodeproj
```

Select `HyperLinkButton` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HyperLinkButton.cbp > /dev/null 2>&1
```

Select `HyperLinkButton` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HyperLinkButton
```
