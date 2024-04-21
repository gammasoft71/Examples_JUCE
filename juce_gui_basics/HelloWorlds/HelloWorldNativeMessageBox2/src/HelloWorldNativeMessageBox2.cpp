#include <JuceHeader.h>

namespace HelloWorldNativeMessageBox2Example {
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return ProjectInfo::projectName;}
    const String getApplicationVersion() override {return ProjectInfo::versionString;}
    
    void initialise(const String& commandLine) override {NativeMessageBox::showMessageBoxAsync(MessageBoxIconType::NoIcon, "", "Hello, World!", nullptr, ModalCallbackFunction::create([&](int result) {quit();}));}
    void shutdown() override {}
  };
}

START_JUCE_APPLICATION(HelloWorldNativeMessageBox2Example::Application)
