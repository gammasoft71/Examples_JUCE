#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace HelloWorldLabelExample {
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return JUCE_APPLICATION_NAME_STRING;}
    const String getApplicationVersion() override {return JUCE_APPLICATION_VERSION_STRING;}
    
    void initialise(const String& commandLine) override { AlertWindow::showMessageBoxAsync(MessageBoxIconType::NoIcon, "", "Hello, World!", String {}, nullptr, ModalCallbackFunction::create([&](int result) {quit();}));}
    void shutdown() override {}
  };
}

START_JUCE_APPLICATION(HelloWorldLabelExample::Application)
