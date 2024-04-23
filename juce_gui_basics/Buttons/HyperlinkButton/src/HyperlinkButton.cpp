#include <JuceHeader.h>

namespace TextButtonExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"HyperLinkButton example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 325);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      button1.setBounds(50, 50, 200, 25);
      button1.setButtonText("Gammasoft");
      button1.setURL(URL {"https://gammasoft71.wixsite.com/gammasoft"});
      mainComponent.addAndMakeVisible(&button1);
      
      button2.setBounds(50, 100, 200, 25);
      button2.setButtonText("JUCE");
      button2.setURL(URL {"https://juce.com"});
      mainComponent.addAndMakeVisible(&button2);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    HyperlinkButton button1;
    HyperlinkButton button2;
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

START_JUCE_APPLICATION(TextButtonExample::Application)
