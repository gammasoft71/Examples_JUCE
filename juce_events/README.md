# juce_events examples

[This folder](.) contains events exampes.

[![JUCE](../docs/Pictures/JUCE.png)](https://www.juce.com)

## [Timers](Timers/README.md)

* [Timer](Timers/Timer/README.md) shows how to create a Timer with [juce::Timer](https://docs.juce.com/master/classTimer.html) class.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start juce_events.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./juce_events.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./juce_events.cbp > /dev/null 2>&1
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
