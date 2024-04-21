#include <JuceHeader.h>

namespace HelloWorldAlertWindowExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Hello world (AlertWindow)", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      setBounds(200, 100, 300, 300);

      button1.setBounds(10, 10, 75, 25);
      button1.setButtonText("Click me");
      button1.onClick = [] {
        AlertWindow::showMessageBoxAsync(MessageBoxIconType::NoIcon, "", "Hello, World!");
      };
      
      mainComponent.addAndMakeVisible(&button1);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    TextButton button1;
  };
  
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return ProjectInfo::projectName;}
    const String getApplicationVersion() override {return ProjectInfo::versionString;}
    
    void initialise(const String& commandLine) override {mainWindow.setVisible(true);}
    void shutdown() override {}
    
  private:
    Window1 mainWindow;
  };
}

START_JUCE_APPLICATION(HelloWorldAlertWindowExample::Application)
