#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;
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
      setBounds(200, 100, 300, 300);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      timer1.onTicks = [&] {
        progressValue4 = min(progressValue4 < 1.0 ? progressValue4 + .01 : .0, 1.0);
      };
      timer1.startTimer(50);
      
      progressBar1.setBounds(50, 50, 200, 25);
      progressBar1.setPercentageDisplay(false);
      mainComponent.addAndMakeVisible(&progressBar1);
      
      progressBar2.setBounds(50, 80, 200, 25);
      progressBar2.setTextToDisplay("Progress");
      mainComponent.addAndMakeVisible(&progressBar2);
      
      progressBar3.setBounds(50, 110, 200, 25);
      mainComponent.addAndMakeVisible(&progressBar3);
      
      progressBar4.setBounds(50, 140, 200, 25);
      mainComponent.addAndMakeVisible(&progressBar4);
      
      progressBar5.setBounds(50, 170, 200, 25);
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
    ProgressBar progressBar1 {progressValue1};
    ProgressBar progressBar2 {progressValue2};
    ProgressBar progressBar3 {progressValue3};
    ProgressBar progressBar4 {progressValue4};
    ProgressBar progressBar5 {progressValue5};
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

START_JUCE_APPLICATION(ProgressBarExample::Application)
