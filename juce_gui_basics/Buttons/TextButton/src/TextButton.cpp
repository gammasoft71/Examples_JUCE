#include <JuceHeader.h>

namespace ProgressBarExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"TextButton example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 350);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      button1.setBounds(50, 50, 75, 25);
      button1.setButtonText("Button 1");
      button1.onClick = [&] {
        label1.setText("Button 1 clicked " + String {++button1Clicked} + " times", NotificationType::dontSendNotification);
      };
      mainComponent.addAndMakeVisible(&button1);
      
      button2.setBounds(50, 100, 200, 75);
      button2.setButtonText("Button 2");
      button2.setRepeatSpeed(300, 100);
      button2.onClick = [&] {
        label2.setText("Button 2 clicked " + String {++button2Clicked } + " times", NotificationType::dontSendNotification);
      };
      mainComponent.addAndMakeVisible(&button2);
      
      label1.setBounds(50, 200, 200, 25);
      label1.setText("Button 1 clicked 0 times", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&label1);
      
      label2.setBounds(50, 230, 200, 25);
      label2.setText("Button 2 clicked 0 times", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&label2);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    TextButton button1;
    TextButton button2;
    Label label1;
    Label label2;
    int button1Clicked = 0;
    int button2Clicked = 0;
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

START_JUCE_APPLICATION(ProgressBarExample::Application)
