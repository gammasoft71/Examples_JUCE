# ProgressBar

Shows how to create a ProgressBar widget with [juce::ProgressBar](https://docs.juce.com/master/classProgressBar.html).

## Source

* [src/ProgressBar.cpp](src/ProgressBar.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ProgressBar.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ProgressBar.sln
```

Select `ProgressBar` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ProgressBar.xcodeproj
```

Select `ProgressBar` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ProgressBar.cbp > /dev/null 2>&1
```

Select `ProgressBar` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ProgressBar
```
