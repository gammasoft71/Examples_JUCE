#include <JuceHeader.h>

namespace HelloWorldAlertWindow2Example {
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return ProjectInfo::projectName;}
    const String getApplicationVersion() override {return ProjectInfo::versionString;}
    
    void initialise(const String& commandLine) override { AlertWindow::showMessageBoxAsync(MessageBoxIconType::NoIcon, "", "Hello, World!", String {}, nullptr, ModalCallbackFunction::create([&](int result) {quit();}));}
    void shutdown() override {}
  };
}

START_JUCE_APPLICATION(HelloWorldAlertWindow2Example::Application)
