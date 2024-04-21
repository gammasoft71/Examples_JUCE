#include <algorithm>
#include <JuceHeader.h>

using namespace std;

namespace ProgressBarExample {
  class ProgressTimer : public Timer {
  public:
    function<void()> onTicks;
    
  private:
    void timerCallback() override {if (onTicks) onTicks();}
  };
  
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ProgressBar example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 350);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      timer1.onTicks = [&] {
        progressValue4 = clamp(progressValue4 < 1.0 ? progressValue4 + .01 : .0, .0, 1.0);
      };
      timer1.startTimer(50);
      
      progressBar1.setBounds(50, 20, 80, 80);
      progressBar1.setColour(ProgressBar::ColourIds::foregroundColourId, Colours::dodgerblue);
      progressBar1.setPercentageDisplay(false);
      mainComponent.addAndMakeVisible(&progressBar1);
      
      progressBar2.setBounds(170, 20, 80, 80);
      progressBar2.setColour(ProgressBar::ColourIds::foregroundColourId, Colours::dodgerblue);
      progressBar2.setTextToDisplay("Progress");
      mainComponent.addAndMakeVisible(&progressBar2);
      
      progressBar3.setBounds(50, 110, 80, 80);
      progressBar3.setColour(ProgressBar::ColourIds::foregroundColourId, Colours::dodgerblue);
      mainComponent.addAndMakeVisible(&progressBar3);
      
      progressBar4.setBounds(170, 110, 80, 80);
      progressBar4.setColour(ProgressBar::ColourIds::foregroundColourId, Colours::dodgerblue);
      mainComponent.addAndMakeVisible(&progressBar4);
      
      progressBar5.setBounds(110, 200, 80, 80);
      progressBar5.setColour(ProgressBar::ColourIds::foregroundColourId, Colours::dodgerblue);
      mainComponent.addAndMakeVisible(&progressBar5);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    double progressValue1 = .0;
    double progressValue2 = .5;
    double progressValue3 = 1.0;
    double progressValue4 = .0;
    double progressValue5 = -1.0;
    ProgressTimer timer1;
    ProgressBar progressBar1 {progressValue1, ProgressBar::Style::circular};
    ProgressBar progressBar2 {progressValue2, ProgressBar::Style::circular};
    ProgressBar progressBar3 {progressValue3, ProgressBar::Style::circular};
    ProgressBar progressBar4 {progressValue4, ProgressBar::Style::circular};
    ProgressBar progressBar5 {progressValue5, ProgressBar::Style::circular};
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
