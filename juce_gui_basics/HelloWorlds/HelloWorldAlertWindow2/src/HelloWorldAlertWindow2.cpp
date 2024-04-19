#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace HelloWorldAlertWindow2Example {
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return "";}
    const String getApplicationVersion() override {return "";}
    
    void initialise(const String& commandLine) override { AlertWindow::showMessageBoxAsync(MessageBoxIconType::NoIcon, "", "Hello, World!", String {}, nullptr, ModalCallbackFunction::create([&](int result) {quit();}));}
    void shutdown() override {}
  };
}

START_JUCE_APPLICATION(HelloWorldAlertWindow2Example::Application)
