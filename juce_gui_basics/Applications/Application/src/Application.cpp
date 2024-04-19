#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace ApplicationExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Application", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {}
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
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

START_JUCE_APPLICATION(ApplicationExample::Application)
