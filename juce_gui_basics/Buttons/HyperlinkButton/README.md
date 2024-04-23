# HyperlinkButton

Shows how to create a HyperlinkButton widget with [juce::HyperlinkButton](https://docs.juce.com/master/classHyperlinkButton.html) widgets.

## Source

* [src/HyperlinkButton.cpp](src/HyperlinkButton.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HyperlinkButton.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HyperlinkButton.sln
```

Select `HyperlinkButton` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HyperlinkButton.xcodeproj
```

Select `HyperlinkButton` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HyperlinkButton.cbp > /dev/null 2>&1
```

Select `HyperlinkButton` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HyperlinkButton
```
