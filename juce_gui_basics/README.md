# juce_gui_basics examples

[This folder](.) contains the basic GUI classes such as GDI classes and widgets examples.

[![JUCE](../docs/Pictures/JUCE.png)](https://www.juce.com)

## [Hello World](HelloWorlds/README.md)

* [HelloWorldAlertWindow](HelloWorlds/HelloWorldAlertWindow/README.md) The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.
* [HelloWorldAlertWindow2](HelloWorlds/HelloWorldAlertWindow2/README.md) The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.
* [HelloWorldLabel](HelloWorlds/HelloWorldLabel/README.md) The classic first application HelloWorld with [Label](https://docs.juce.com/master/classLabel.html).
* [HelloWorldNativeMessageBox](HelloWorlds/HelloWorldNativeMessageBox/README.md) The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.
* [HelloWorldNativeMessageBox2](HelloWorlds/HelloWorldNativeMessageBox2/README.md) The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.
* [HelloWorldPaint](HelloWorlds/HelloWorldPaint/README.md) The classic first application HelloWorld with [juce::Component::paint](https://docs.juce.com/master/classComponent.html#a7cf1862f4af5909ea72827898114a182) method.

## [Applications](Applications/README.md)

* [Application](Applications/Application/README.md) shows how to create a simple JUCE application with [JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html).
* [ApplicationUsingNativeTitleBar](Applications/ApplicationUsingNativeTitleBar/README.md) shows how to create a simple JUCE application with [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class and [juce::TopLevelWindow::setUsingNativeTitleBar](https://docs.juce.com/master/classTopLevelWindow.html#a749fbd5e688ed8c9af3d0d99b21e18c8) method.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start juce_gui_basics.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./juce_gui_basics.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./juce_gui_basics.cbp > /dev/null 2>&1
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
