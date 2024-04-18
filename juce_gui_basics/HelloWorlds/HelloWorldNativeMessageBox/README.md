# HelloWorldNativeMessageBox

The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.

## Source

[src/HelloWorldNativeMessageBox.cpp](src/HelloWorldNativeMessageBox.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldNativeMessageBox.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldNativeMessageBox.sln
```

Select Application project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldNativeMessageBox.xcodeproj
```

Select Application project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldNativeMessageBox.cbp > /dev/null 2>&1
```

Select Application project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldNativeMessageBox
```
