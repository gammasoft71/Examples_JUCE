# Buttons examples

[This folder](.) contains JUCE Buttons examples.

* [ArrowButton](ArrowButton/README.md) shows how to create a ArrowButton widget with [juce::ArrowButton](https://docs.juce.com/master/classArrowButton.html) widget.
* [RadioButton](RadioButton/README.md) shows how to create a RadioButton widget with [juce::ToggleButton](https://docs.juce.com/master/classToggleButton.html) widget.
* [TextButton](TextButton/README.md) shows how to create a Button widget with [juce::TextButton](https://docs.juce.com/master/classTextButton.html) widget.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Buttons.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Buttons.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Buttons.cbp > /dev/null 2>&1
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
