#include <algorithm>
#include <JuceHeader.h>

using namespace std;

namespace ProgressBarExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ProgressBar example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 300);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      slider1.setBounds(50, 50, 200, 25);
      slider1.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
      slider1.setRange(.0, 1.0);
      slider1.setValue(progressValue1);
      slider1.onValueChange = [&] {
        progressValue1 = slider1.getValue();
        label1.setText(String {static_cast<int>(progressValue1 * 100)}, NotificationType::dontSendNotification);
      };
      mainComponent.addAndMakeVisible(&slider1);

      progressBar1.setBounds(50, 100, 200, 25);
      progressBar1.setPercentageDisplay(false);
      mainComponent.addAndMakeVisible(&progressBar1);

      label1.setBounds(50, 150, 200, 25);
      label1.setText("0", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&label1);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    double progressValue1 = .5;
    ProgressBar progressBar1 {progressValue1};
    Slider slider1;
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

START_JUCE_APPLICATION(ProgressBarExample::Application)
