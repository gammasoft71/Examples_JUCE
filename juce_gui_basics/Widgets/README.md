# Widgets examples

[This folder](.) contains JUCE widgets examples.

* [ComboBox](ComboBox/README.md) shows how to create a ComboBox widget with [juce::ComboBox](https://docs.juce.com/master/classComboBox.html).
* [ImageComponent](ImageComponent/README.md) shows how to create a Image widget with [juce::ImageComponent](https://docs.juce.com/master/classImageComponent.html).
* [Label](Label/README.md) shows how to create a ComboBox widget with [juce::Label](https://docs.juce.com/master/classLabel.html).
* [ListBox](ListBox/README.md) shows how to create a ComboBox widget with [juce::ListBox](https://docs.juce.com/master/classListBox.html).
* [ProgressBar](ProgressBar/README.md) shows how to create a ComboBox widget with [juce::ProgressBar](https://docs.juce.com/master/classProgressBar.html).

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Widgets.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Widgets.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Widgets.cbp > /dev/null 2>&1
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
