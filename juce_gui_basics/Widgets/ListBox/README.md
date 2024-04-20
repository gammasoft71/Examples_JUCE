# ListBox

Shows how to create a ListBox widget with [juce::ListBox](https://docs.juce.com/master/classListBox.html).

## Source

* [src/ListBox.cpp](src/ListBox.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ListBox.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ListBox.sln
```

Select `ListBox` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ListBox.xcodeproj
```

Select `ListBox` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ListBox.cbp > /dev/null 2>&1
```

Select `ListBox` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ListBox
```
