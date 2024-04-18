#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace ApplicationExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Application", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setResizable(true, true);
      setBounds(200, 100, 300, 300);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::getInstance()->quit();}
  };
  
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return JUCE_APPLICATION_NAME_STRING;}
    const String getApplicationVersion() override {return JUCE_APPLICATION_VERSION_STRING;}
    
    void initialise(const String& commandLine) override {mainWindow.setVisible(true);}
    void shutdown() override {}
    
  private:
    Window1 mainWindow;
  };
}

START_JUCE_APPLICATION(ApplicationExample::Application)
