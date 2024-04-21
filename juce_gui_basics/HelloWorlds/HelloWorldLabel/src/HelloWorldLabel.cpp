#include <JuceHeader.h>

namespace HelloWorldLabelExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Hello world (Label)", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setContentOwned(&label1, false);
      setResizable(true, true);
      setBounds(200, 100, 300, 300);

      label1.setColour(Label::ColourIds::textColourId, Colours::lime);
      label1.setFont({46, Font::FontStyleFlags::bold | Font::FontStyleFlags::italic});
      label1.setJustificationType(Justification::centred);
      label1.setText("Hello, World!", NotificationType::dontSendNotification);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Label label1;
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

START_JUCE_APPLICATION(HelloWorldLabelExample::Application)
