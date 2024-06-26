#include <JuceHeader.h>

namespace HelloWorldPaintExample {
  class OwnerDrawComponent : public Component {
  protected:
    void paint(Graphics &g) override {
      g.fillAll(Colours::lightblue);
      g.setFont({Font::getDefaultMonospacedFontName(), 40, Font::FontStyleFlags::bold | Font::FontStyleFlags::italic});
      g.setColour(Colours::lightblue.darker());
      g.drawFittedText("Hello, World!", g.getClipBounds() + Point<int>(2, 2), Justification::centred, 2);
      g.setColour(Colours::darkblue);
      g.drawFittedText("Hello, World!", g.getClipBounds(), Justification::centred, 2);
    }
  };

  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Hello world (Paint)", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setContentOwned(&mainCompnent, false);
      setResizable(true, true);
      setBounds(200, 100, 300, 300);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    OwnerDrawComponent mainCompnent;
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

START_JUCE_APPLICATION(HelloWorldPaintExample::Application)
