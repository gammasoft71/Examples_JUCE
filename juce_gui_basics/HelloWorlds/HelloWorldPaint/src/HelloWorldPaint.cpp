#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace HelloWorldLabelExample {
  class OwnerDrawComponent : public Component {
  protected:
    void paint(Graphics &g) override {
      Component::paint(g);

      g.fillAll({0x0, 0x20, 0x10});

      auto shadowRect = g.getClipBounds();
      shadowRect.translate(2, 2);
      g.setColour(Colours::springgreen.darker(2.0f));
      g.setFont({Font::getDefaultMonospacedFontName(), 40, Font::FontStyleFlags::bold | Font::FontStyleFlags::italic});
      g.drawText("Hello, World!", shadowRect, Justification::centred);

      g.setColour(Colours::springgreen);
      g.setFont({Font::getDefaultMonospacedFontName(), 40, Font::FontStyleFlags::bold | Font::FontStyleFlags::italic});
      g.drawText("Hello, World!", g.getClipBounds(), Justification::centred);
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
