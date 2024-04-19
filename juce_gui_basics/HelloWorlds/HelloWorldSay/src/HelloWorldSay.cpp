#include <filesystem>
#include <fstream>
#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;
using namespace std;
using namespace std::filesystem;

namespace HelloWorldLabelExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Hello world (Say)", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      setBounds(200, 100, 300, 300);

      button1.setBounds(10, 10, 75, 25);
      button1.setButtonText("Say...");
      button1.onClick = [&] {
        Speak("Hello, World!");
      };
      
      mainComponent.addAndMakeVisible(&button1);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::getInstance()->quit();}
    
  private:
    // Very basic speech synthesizer using the command line.
    void Speak(const String& text) {
      static auto initialized = false;
      if (!initialized) {
        auto file = ofstream {temp_directory_path() / "say.cmd"};
        if ((SystemStats::getOperatingSystemType() & SystemStats::Windows) == SystemStats::Windows) file << "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say.vbs\n@echo Speaker.Speak %* >> %TEMP%\\say.vbs\n@%TEMP%\\say.vbs";
        else if ((SystemStats::getOperatingSystemType() & SystemStats::MacOSX) == SystemStats::MacOSX) file << "say $*";
        else file << "spd-say $*";
        permissions(temp_directory_path() / "say.cmd", perms::owner_all);
        initialized = true;
      }
      Process::openDocument((temp_directory_path() / "say.cmd").string(), text);
    }
    Component mainComponent;
    TextButton button1;
  };
  
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return "";}
    const String getApplicationVersion() override {return "";}
    
    void initialise(const String& commandLine) override {mainWindow.setVisible(true);}
    void shutdown() override {}
    
  private:
    Window1 mainWindow;
  };
}

START_JUCE_APPLICATION(HelloWorldLabelExample::Application)
