#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace HelloWorldNativeMessageBox2Example {
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return "";}
    const String getApplicationVersion() override {return "";}
    
    void initialise(const String& commandLine) override {NativeMessageBox::showMessageBoxAsync(MessageBoxIconType::NoIcon, "", "Hello, World!", nullptr, ModalCallbackFunction::create([&](int result) {quit();}));}
    void shutdown() override {}
  };
}

START_JUCE_APPLICATION(HelloWorldNativeMessageBox2Example::Application)
