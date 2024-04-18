# JUCE "Hello, world!" Examples

[This folder](.) contains JUCE "Hello, world!" examples.

* [HelloWorldLabel](HelloWorldLabel/README.md) The classic first application HelloWorld with []juce::Label](https://docs.juce.com/master/classLabel.html) class.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start HelloWorlds.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorlds.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorlds.cbp > /dev/null 2>&1
```

Select any project and type F10 to build and run it.

### Linux :

``` shell
mkdir build
cd build
cmake ..
cmake --build . --config Debug
./AnyProject
```
