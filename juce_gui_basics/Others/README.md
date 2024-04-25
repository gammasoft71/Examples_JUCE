# Others examples

[This folder](.) contains JUCE others examples.

* [DisplayInformations](DisplayInformations/README.md) shows how to use [juce::Display](https://docs.juce.com/master/classDisplay.html) class.
* [ProgressBarCircular](ProgressBarCircular/README.md) shows how to create a ProgressBar widget with [juce::ProgressBar](https://docs.juce.com/master/classProgressBar.html).

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Others.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Others.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Others.cbp > /dev/null 2>&1
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
