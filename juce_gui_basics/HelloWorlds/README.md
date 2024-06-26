# JUCE "Hello, world!" Examples

[This folder](.) contains JUCE "Hello, world!" examples.

* [HelloWorldAlertWindow](HelloWorldAlertWindow/README.md) The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.
* [HelloWorldAlertWindow2](HelloWorldAlertWindow2/README.md) The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.
* [HelloWorldJUCE](HelloWorldJUCE/README.md) The classic first application HelloWorld with [juce::Label](https://docs.juce.com/master/classLabel.html) and [juce::TextButton](https://docs.juce.com/master/classTextButton.html) widgets and [juce::Path](https://docs.juce.com/master/classPath.html) class.
* [HelloWorldLabel](HelloWorldLabel/README.md) The classic first application HelloWorld with [juce::Label](https://docs.juce.com/master/classLabel.html) widget.
* [HelloWorldNativeMessageBox](HelloWorldNativeMessageBox/README.md) The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.
* [HelloWorldNativeMessageBox2](HelloWorldNativeMessageBox2/README.md) The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.
* [HelloWorldPaint](HelloWorldPaint/README.md) The classic first application HelloWorld with [juce::Component::paint](https://docs.juce.com/master/classComponent.html#a7cf1862f4af5909ea72827898114a182) method.
* [HelloWorldSay](HelloWorldSay/README.md) The classic first application HelloWorld with [juce::TextButton](https://docs.juce.com/master/classTextButton.html) widget.

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
