#include <JuceHeader.h>

using namespace std;

namespace RadioButtonExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"RadioButton example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 300);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      radioButton1.setBounds(30, 30, 75, 25);
      radioButton1.setRadioGroupId(0);
      radioButton1.setButtonText("Radio 1");
      radioButton1.onClick = [&] {
        radioButton1.setToggleState(false, NotificationType::dontSendNotification);
      };
      mainComponent.addAndMakeVisible(&radioButton1);
      
      radioButton2.setBounds(30, 60, 75, 25);
      radioButton2.setRadioGroupId(radioGroupId);
      radioButton2.setButtonText("Radio 2");
      radioButton2.setToggleState(true, NotificationType::dontSendNotification);
      radioButton2.onClick = bind(&Window1::updateLabelText, this);
      mainComponent.addAndMakeVisible(&radioButton2);
      
      radioButton3.setBounds(30, 90, 75, 25);
      radioButton3.setRadioGroupId(radioGroupId);
      radioButton3.setButtonText("Radio 3");
      radioButton3.onClick = bind(&Window1::updateLabelText, this);
      mainComponent.addAndMakeVisible(&radioButton3);
      
      radioButton4.setBounds(30, 120, 75, 25);
      radioButton4.setRadioGroupId(radioGroupId);
      radioButton4.setButtonText("Radio 4");
      radioButton4.onClick = bind(&Window1::updateLabelText, this);
      mainComponent.addAndMakeVisible(&radioButton4);

      label1.setBounds(30, 150, 200, 25);
      mainComponent.addAndMakeVisible(&label1);
      updateLabelText();
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}

  private:
    void updateLabelText() {label1.setText("Radio 3 checked = " + String {radioButton3.getToggleState() ? "true" : "false"}, NotificationType::dontSendNotification);}

    const int radioGroupId = 1;
    Component mainComponent;
    ToggleButton radioButton1;
    ToggleButton radioButton2;
    ToggleButton radioButton3;
    ToggleButton radioButton4;
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

START_JUCE_APPLICATION(RadioButtonExample::Application)
