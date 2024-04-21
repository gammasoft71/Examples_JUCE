# JUCE examples

Shows how to use [JUCE](https://juce.com) components only by programming code ([c++17](https://en.cppreference.com/w/)).

[![JUCE](docs/Pictures/JUCE.png)](https://juce.com)

<!---
## [juce_analytics](juce_analytics/README.md) 

* Not yet implemented

## [juce_audio_basics](juce_audio_basics/README.md) 

* Not yet implemented

## [juce_audio_devices](juce_audio_devices/README.md) 

* Not yet implemented

## [juce_audio_formats](juce_audio_formats/README.md) 

* Not yet implemented

## [juce_audio_plugin_client](juce_audio_plugin_client/README.md) 

* Not yet implemented

## [juce_audio_processors](juce_audio_processors/README.md) 

* Not yet implemented

## [juce_audio_utils](juce_audio_utils/README.md) 

* Not yet implemented

## [juce_box2d](juce_box2d/README.md) 

* Not yet implemented

## [juce_core](juce_core/README.md) 

* Not yet implemented

## [juce_cryptography](juce_cryptography/README.md) 

* Not yet implemented

## [juce_data_structures](juce_data_structures/README.md) 

* Not yet implemented

## [juce_dsp](juce_dsp/README.md) 

* Not yet implemented

## [juce_events](juce_events/README.md) 

* Not yet implemented

## [juce_graphics](juce_graphics/README.md) 

* Not yet implemented
--->

## [juce_gui_basics](juce_gui_basics/README.md) 

[juce_gui_basics examples](juce_gui_basics/README.md) contains [juce_gui_basics](https://docs.juce.com/master/group__juce__gui__basics.html) (GUI) examples.

* [Hello World](juce_gui_basics/HelloWorlds/README.md) contains JUCE "Hello, World!" examples.
* [Applications](juce_gui_basics/Applications/README.md) contains applications examples.
* [Widgets](juce_gui_basics/Widgets/README.md) contains widgets examples.
* [Others](juce_gui_basics/Others/README.md) contains others examples.

<!---
## [juce_gui_extra](juce_gui_extra/README.md) 

* Not yet implemented

## [juce_midi_ci](juce_midi_ci/README.md) 

* Not yet implemented

## [juce_opengl](juce_opengl/README.md) 

* Not yet implemented

## [juce_osc](juce_osc/README.md) 

* Not yet implemented

## [juce_product_unlocking](juce_product_unlocking/README.md) 

* Not yet implemented

## [juce_video](juce_video/README.md) 

* Not yet implemented
--->

## Download

``` shell
git clone https://github.com/gammasoft71/Examples_JUCE
```

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows

``` shell
mkdir build && cd build
cmake ..
start JUCEExamples.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./JUCEExamples.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./JUCEExamples.cbp > /dev/null 2>&1
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

## Remarks

This project run with  [JUCE](https://juce.com) 7.0.12 or above and [CMake](https://cmake.org) 3.22 or above.
