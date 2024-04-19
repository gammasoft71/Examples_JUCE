# HelloWorldNativeMessageBox2

The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.

## Source

[src/HelloWorldNativeMessageBox2.cpp](src/HelloWorldNativeMessageBox2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldNativeMessageBox2.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldNativeMessageBox2.sln
```

Select `HelloWorldNativeMessageBox2` project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldNativeMessageBox2.xcodeproj
```

Select `HelloWorldNativeMessageBox2` project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldNativeMessageBox2.cbp > /dev/null 2>&1
```

Select `HelloWorldNativeMessageBox2` project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldNativeMessageBox2
```
