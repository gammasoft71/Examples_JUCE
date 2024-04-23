# juce_gui_basics examples

[This folder](.) contains the basic GUI classes such as GDI classes and widgets examples.

[![JUCE](../docs/Pictures/JUCE.png)](https://www.juce.com)

## [Hello World](HelloWorlds/README.md)

* [HelloWorldAlertWindow](HelloWorlds/HelloWorldAlertWindow/README.md) The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.
* [HelloWorldAlertWindow2](HelloWorlds/HelloWorldAlertWindow2/README.md) The classic first application HelloWorld with [juce::AlertWindow](https://docs.juce.com/master/classAlertWindow.html) dialog.
* [HelloWorldJUCE](HelloWorlds/HelloWorldJUCE/README.md) The classic first application HelloWorld with [juce::Label](https://docs.juce.com/master/classLabel.html) and [juce::TextButton](https://docs.juce.com/master/classTextButton.html) widgets and [juce::Path](https://docs.juce.com/master/classPath.html) class.
* [HelloWorldLabel](HelloWorlds/HelloWorldLabel/README.md) The classic first application HelloWorld with [Label](https://docs.juce.com/master/classLabel.html) widget.
* [HelloWorldNativeMessageBox](HelloWorlds/HelloWorldNativeMessageBox/README.md) The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.
* [HelloWorldNativeMessageBox2](HelloWorlds/HelloWorldNativeMessageBox2/README.md) The classic first application HelloWorld with [juce::NativeMessageBox](https://docs.juce.com/master/classNativeMessageBox.html) dialog.
* [HelloWorldPaint](HelloWorlds/HelloWorldPaint/README.md) The classic first application HelloWorld with [juce::Component::paint](https://docs.juce.com/master/classComponent.html#a7cf1862f4af5909ea72827898114a182) method.
* [HelloWorldSay](HelloWorlds/HelloWorldSay/README.md) The classic first application HelloWorld with [juce::TextButton](https://docs.juce.com/master/classTextButton.html) widget.

## [Applications](Applications/README.md)

* [Application](Applications/Application/README.md) shows how to create a simple JUCE application with [JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html).
* [ApplicationAndException](Applications/ApplicationAndException/README.md) shows how to create a simple JUCE application with  [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class and how to manage exception.
* [ApplicationUsingNativeTitleBar](Applications/ApplicationUsingNativeTitleBar/README.md) shows how to create a simple JUCE application with [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class and [juce::TopLevelWindow::setUsingNativeTitleBar](https://docs.juce.com/master/classTopLevelWindow.html#a749fbd5e688ed8c9af3d0d99b21e18c8) method.
* [ApplicationWithProjectInfo](Applications/ApplicationWithProjectInfo/README.md) shows how to create a simple JUCE application with [juce::JUCEApplication](https://docs.juce.com/master/classJUCEApplication.html) class, [juce::Label](https://docs.juce.com/master/classLabel.html) and [juce::TextEditor](https://docs.juce.com/master/classTextEditor.html) widgets and how to use ProjectInfo..

## [Buttons](Buttons/README.md)

* [ArrowButton](Buttons/ArrowButton/README.md) shows how to create a ArrowButton widget with [juce::ArrowButton](https://docs.juce.com/master/classArrowButton.html) widget.
* [RadioButton](Buttons/RadioButton/README.md) shows how to create a RadioButton widget with [juce::ToggleButton](https://docs.juce.com/master/classToggleButton.html) widget.
* [TextButton](Buttons/TextButton/README.md) shows how to create a Button widget with [juce::TextButton](https://docs.juce.com/master/classTextButton.html) widget.
* [ToggleButton](Buttons/ToggleButton/README.md) shows how to create a ToggleButton widget with [juce::ToggleButton](https://docs.juce.com/master/classToggleButton.html) widget.

## [Widgets](Widgets/README.md)

* [ComboBox](Widgets/ComboBox/README.md) shows how to create a ComboBox widget with [juce::ComboBox](https://docs.juce.com/master/classComboBox.html).
* [ImageComponent](Widgets/ImageComponent/README.md) shows how to create a Image widget with [juce::ImageComponent](https://docs.juce.com/master/classImageComponent.html).
* [Label](Widgets/Label/README.md) shows how to create a ComboBox widget with [juce::Label](https://docs.juce.com/master/classLabel.html).
* [ListBox](Widgets/ListBox/README.md) shows how to create a ComboBox widget with [juce::ListBox](https://docs.juce.com/master/classListBox.html).
* [ProgressBar](Widgets/ProgressBar/README.md) shows how to create a ProgressBar widget with [juce::ProgressBar](https://docs.juce.com/master/classProgressBar.html).
* [Slider](Widgets/Slider/README.md) shows how to create a Slider widget with [juce::Slider](https://docs.juce.com/master/classSlider.html).

## [Others](Others/README.md)

* [ProgressBarCircular](Others/ProgressBarCircular/README.md) shows how to create a ProgressBar widget with [juce::ProgressBar](https://docs.juce.com/master/classProgressBar.html).

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
