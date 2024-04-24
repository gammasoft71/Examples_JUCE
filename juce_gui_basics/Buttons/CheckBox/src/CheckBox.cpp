#include <JuceHeader.h>

using namespace std;

namespace CheckBoxExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"CheckBox example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 300);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      checkBox1.setBounds(30, 30, 75, 25);
      checkBox1.setRadioGroupId(0);
      checkBox1.setButtonText("Unchecked");
      checkBox1.onClick = [&] {
        checkBox1.setToggleState(false, NotificationType::dontSendNotification);
        checkBox1.setButtonText(checkBox1.getToggleState() ? "Checked" : "Unchecked");
      };
      mainComponent.addAndMakeVisible(&checkBox1);
      
      checkBox2.setBounds(30, 60, 75, 25);
      checkBox2.setButtonText("Checked");
      checkBox2.setToggleState(true, NotificationType::dontSendNotification);
      checkBox2.onClick = [&] {checkBox2.setButtonText(checkBox2.getToggleState() ? "Checked" : "Unchecked");};
      mainComponent.addAndMakeVisible(&checkBox2);
      
      checkBox3.setBounds(30, 90, 75, 25);
      checkBox3.setButtonText("Checked");
      checkBox3.setToggleState(true, NotificationType::dontSendNotification);
      checkBox3.onClick = [&] {checkBox3.setButtonText(checkBox3.getToggleState() ? "Checked" : "Unchecked");};
      mainComponent.addAndMakeVisible(&checkBox3);
      
      checkBox4.setBounds(30, 120, 75, 25);
      checkBox4.setButtonText("Unchecked");
      checkBox4.onClick = [&] {checkBox4.setButtonText(checkBox4.getToggleState() ? "Checked" : "Unchecked");};
      mainComponent.addAndMakeVisible(&checkBox4);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}

  private:
    Component mainComponent;
    ToggleButton checkBox1;
    ToggleButton checkBox2;
    ToggleButton checkBox3;
    ToggleButton checkBox4;
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

START_JUCE_APPLICATION(CheckBoxExample::Application)
