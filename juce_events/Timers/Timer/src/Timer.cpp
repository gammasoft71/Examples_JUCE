#include <functional>
#include <JuceHeader.h>

using namespace std;

namespace ProgressBarExample {
  class CounterTimer : public Timer {
  public:
    function<void()> onTick;
    
  private:
    void timerCallback() override {if (onTick) onTick();}
  };
  
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Timer example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 230, 155);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      timer1.onTick = [&] {
        label1.setText(String {++counter / 10.0, 1}, NotificationType::dontSendNotification);
      };
      
      label1.setBounds(10, 10, 210, 70);
      label1.setColour(Label::ColourIds::textColourId, Colours::dodgerblue);
      label1.setText("0.0", NotificationType::dontSendNotification);
      label1.setFont({68, Font::FontStyleFlags::bold | Font::FontStyleFlags::italic});
      mainComponent.addAndMakeVisible(&label1);
      
      button1.setBounds(10, 90, 75, 25);
      button1.setButtonText("Start");
      button1.onClick = [&] {
        if (timer1.isTimerRunning()) timer1.stopTimer();
        else timer1.startTimer(100);
        button1.setButtonText(timer1.isTimerRunning() ? "Stop" : "Start");
      };
      mainComponent.addAndMakeVisible(&button1);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    CounterTimer timer1;
    Label label1;
    TextButton button1;
    int counter = 0;
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
