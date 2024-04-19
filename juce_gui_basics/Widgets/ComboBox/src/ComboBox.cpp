#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;

namespace ComboBoxExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ComboBox example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 300);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      comboBox1.setBounds(10, 10, 105, 25);
      comboBox1.addItemList({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"}, 1);
      comboBox1.onChange = [&] {
        comboBox2.setSelectedId(comboBox1.getSelectedId());
      };
      mainComponent.addAndMakeVisible(&comboBox1);
      
      comboBox2.setBounds(10, 50, 105, 25);
      comboBox2.addItemList({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"}, 1);
      comboBox2.setEditableText(true);
      comboBox2.onChange = [&] {
        comboBox1.setSelectedId(comboBox2.getSelectedId());
      };
      mainComponent.addAndMakeVisible(&comboBox2);

      comboBox1.setSelectedId(1);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    ComboBox comboBox1;
    ComboBox comboBox2;
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

START_JUCE_APPLICATION(ComboBoxExample::Application)
