#include <vector>
#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;
using namespace std;

namespace LabelExample {
  class StringVectorListBoxModel : public ListBoxModel, public vector<String> {
  public:
    StringVectorListBoxModel() = default;
    StringVectorListBoxModel(StringVectorListBoxModel&&) = default;
    StringVectorListBoxModel(const StringVectorListBoxModel&) = default;
    StringVectorListBoxModel& operator =(const StringVectorListBoxModel&) = default;
    StringVectorListBoxModel(const initializer_list<String>& il) : vector<String>(il) {}

    int getNumRows() override {return static_cast<int>(size());}
    
    void paintListBoxItem (int rowNumber, Graphics& g, int width, int height, bool rowIsSelected) override {
      if (rowIsSelected) g.fillAll(Colours::lightblue);
      
      g.setColour(LookAndFeel::getDefaultLookAndFeel().findColour(Label::textColourId));
      g.setFont((float) height * 0.7f);
      g.drawText(at(rowNumber), 5, 0, width, height, Justification::centredLeft, true);
    }
  };
  
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ListBox example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 360, 270);
      setContentOwned(&mainComponent, false);
      
      listBox1.setBounds(10, 10, 165, 220);
      listBox1.setModel(&stringVectorListmodel1);
      listBox1.doub
      mainComponent.addAndMakeVisible(&listBox1);
      
      listBox2.setBounds(185, 10, 165, 220);
      listBox2.setModel(&stringVectorListmodel2);
      mainComponent.addAndMakeVisible(&listBox2);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    void resized() override {
      DocumentWindow::resized();
      label4.setSize(getWidth() - 40, getHeight() - 235);
    }
    
  private:
    Component mainComponent;
    StringVectorListBoxModel stringVectorListmodel1 {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"};
    ListBox listBox1;
    StringVectorListBoxModel stringVectorListmodel2;
    ListBox listBox2;
    Label label3;
    Label label4;
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

START_JUCE_APPLICATION(LabelExample::Application)
