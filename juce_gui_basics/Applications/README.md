# Application Examples

[This folder](.) contains JUCE application examples.

* [Application](Application/README.md) shows how to create a simple JUCE application with  [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class.
* [ApplicationAndException](ApplicationAndException/README.md) shows how to create a simple JUCE application with  [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class and how to manage exception.
* [ApplicationUsingNativeTitleBar](ApplicationUsingNativeTitleBar/README.md) shows how to create a simple JUCE application with [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class and [juce::TopLevelWindow::setUsingNativeTitleBar](https://docs.juce.com/master/classTopLevelWindow.html#a749fbd5e688ed8c9af3d0d99b21e18c8) method.
* [ApplicationWithProjectInfo](ApplicationWithProjectInfo/README.md) shows how to create a simple JUCE application with [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class, [juce::Label](https://docs.juce.com/master/classLabel.html) and [juce::TextEditor](https://docs.juce.com/master/classTextEditor.html) widgets and how to use ProjectInfo..

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Applications.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Applications.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Applications.cbp > /dev/null 2>&1
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
