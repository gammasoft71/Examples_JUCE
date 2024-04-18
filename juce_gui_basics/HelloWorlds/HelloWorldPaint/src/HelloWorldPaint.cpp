#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace HelloWorldLabelExample {
  class OwnerDrawComponent : public Component {
  protected:
    void paint(Graphics &g) override {
      g.fillAll({0x0, 0x20, 0x10});
      
      g.setFont({Font::getDefaultMonospacedFontName(), 40, Font::FontStyleFlags::bold | Font::FontStyleFlags::italic});
      auto text = "Hello, World!";
      auto textColour = Colours::springgreen;
      g.setColour(textColour.darker(2.0f));
      auto textRect = g.getClipBounds();
      auto shadowTextRect = textRect;
      shadowTextRect.translate(2, 2);
      g.drawText(text, shadowTextRect, Justification::centred);
      
      g.setColour(textColour);
      g.drawText(text, textRect, Justification::centred);
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
    void closeButtonPressed() override {JUCEApplication::getInstance()->quit();}
    
  private:
    OwnerDrawComponent mainCompnent;
  };
  
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return JUCE_APPLICATION_NAME_STRING;}
    const String getApplicationVersion() override {return JUCE_APPLICATION_VERSION_STRING;}
    
    void initialise(const String& commandLine) override {mainWindow.setVisible(true);}
    void shutdown() override {}
    
  private:
    Window1 mainWindow;
  };
}

START_JUCE_APPLICATION(HelloWorldLabelExample::Application)
