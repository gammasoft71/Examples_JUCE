#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace HelloWorldJUCEExample {
  class HelloWorldDemo : public Component {
  public:
    HelloWorldDemo() {
      addAndMakeVisible(helloWorldLabel);
      
      helloWorldLabel.setFont({40.00f, Font::bold});
      helloWorldLabel.setJustificationType(Justification::centred);
      helloWorldLabel.setEditable(false, false, false);
      helloWorldLabel.setColour(Label::textColourId, Colours::black);
      helloWorldLabel.setColour(TextEditor::textColourId, Colours::black);
      helloWorldLabel.setColour(TextEditor::backgroundColourId, Colour {0x00000000});
      
      addAndMakeVisible(quitButton);
      quitButton.onClick = [] {JUCEApplication::quit();};
      
      setSize(600, 300);
    }
    
    void paint(Graphics& g) override {
      g.fillAll(Colour {0xffc1d0ff});
      
      g.setColour(Colours::white);
      g.fillPath(internalPath);
      
      g.setColour(Colour {0xff6f6f6f});
      g.strokePath(internalPath, PathStrokeType {5.200f});
    }
    
    void resized() override {
      helloWorldLabel.setBounds(152, 80, 296, 48);
      quitButton.setBounds(getWidth() - 176, getHeight() - 60, 120, 32);
      
      internalPath.clear();
      internalPath.startNewSubPath(136.0f, 80.0f);
      internalPath.quadraticTo(176.0f, 24.0f, 328.0f, 32.0f);
      internalPath.quadraticTo(472.0f, 40.0f, 472.0f, 104.0f);
      internalPath.quadraticTo(472.0f, 192.0f, 232.0f, 176.0f);
      internalPath.lineTo(184.0f, 216.0f);
      internalPath.lineTo(200.0f, 168.0f);
      internalPath.quadraticTo(96.0f, 136.0f, 136.0f, 80.0f);
      internalPath.closeSubPath();
    }
    
  private:
    Label helloWorldLabel {{}, "Hello World!"};
    TextButton quitButton {"Quit"};
    Path internalPath;
  };

  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"HelloWorldDemo", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setContentOwned(&mainComponent, true);
      centreWithSize(getWidth(), getHeight());
      setResizable(true, true);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    HelloWorldDemo mainComponent;
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

START_JUCE_APPLICATION(HelloWorldJUCEExample::Application)
