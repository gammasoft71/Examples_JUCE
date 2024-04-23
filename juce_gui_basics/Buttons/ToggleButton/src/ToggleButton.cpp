#include <JuceHeader.h>

using namespace std;

namespace ToggleButtonExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ToggleButton example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 300);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      toggleButton1.setBounds(30, 30, 105, 25);
      toggleButton1.setButtonText("Checked");
      toggleButton1.setToggleable(true);
      toggleButton1.setToggleState(true, NotificationType::dontSendNotification);
      toggleButton1.onClick = [&] {
        toggleButton1.setToggleState(!toggleButton1.getToggleState(), NotificationType::dontSendNotification);
        toggleButton1.setButtonText(toggleButton1.getToggleState() ? "Checked" : "Unchecked");
      };
      mainComponent.addAndMakeVisible(&toggleButton1);
      
      toggleButton2.setBounds(30, 60, 105, 25);
      toggleButton1.setToggleable(true);
      toggleButton2.setButtonText("Unchecked");
      toggleButton2.onClick = [&] {
        toggleButton2.setToggleState(!toggleButton2.getToggleState(), NotificationType::dontSendNotification);
        toggleButton2.setButtonText(toggleButton2.getToggleState() ? "Checked" : "Unchecked");
      };
      mainComponent.addAndMakeVisible(&toggleButton2);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}

  private:
    Component mainComponent;
    TextButton toggleButton1;
    TextButton toggleButton2;
    Label label1;
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

START_JUCE_APPLICATION(ToggleButtonExample::Application)
