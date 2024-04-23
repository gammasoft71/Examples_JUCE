#include <JuceHeader.h>

namespace ArrowButtonExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ArrowButton example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 300);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      textEditor1.setBounds(50, 50, 100, 25);
      textEditor1.setReadOnly(true);
      textEditor1.setText(String {value});
      mainComponent.addAndMakeVisible(&textEditor1);
      
      buttonUp.setBounds(152, 50, 12, 12);
      buttonUp.setRepeatSpeed(300, 100);
      buttonUp.onClick = [&] {textEditor1.setText(String {++value});};
      mainComponent.addAndMakeVisible(&buttonUp);

      buttonDown.setBounds(152, 66, 12, 12);
      buttonDown.setRepeatSpeed(300, 100);
      buttonDown.onClick = [&] {textEditor1.setText(String {--value});};
      mainComponent.addAndMakeVisible(&buttonDown);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    int value = 0;
    Component mainComponent;
    TextEditor textEditor1;
    ArrowButton buttonUp {"", 0.75, Desktop::getInstance().getDefaultLookAndFeel().findColour(Label::textColourId)};
    ArrowButton buttonDown {"", 0.25, Desktop::getInstance().getDefaultLookAndFeel().findColour(Label::textColourId)};
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

START_JUCE_APPLICATION(ArrowButtonExample::Application)
