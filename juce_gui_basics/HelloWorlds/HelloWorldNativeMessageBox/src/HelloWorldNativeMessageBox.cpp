#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace HelloWorldLabelExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Hello world (NativeMessageBox)", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      setBounds(200, 100, 300, 300);

      button1.setBounds(10, 10, 75, 25);
      button1.setButtonText("Click me");
      button1.onClick = [&] {
        NativeMessageBox::showMessageBoxAsync(MessageBoxIconType::NoIcon, "", "Hello, World!", this);
      };
      
      mainComponent.addAndMakeVisible(&button1);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::getInstance()->quit();}
    
  private:
    Component mainComponent;
    TextButton button1;
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

START_JUCE_APPLICATION(HelloWorldLabelExample::Application)
