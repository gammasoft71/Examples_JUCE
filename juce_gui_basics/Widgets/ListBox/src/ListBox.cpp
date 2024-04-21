#include <vector>
#include <JuceHeader.h>

using namespace std;

namespace ListBoxExample {
  class StringVectorListBoxModel : public ListBoxModel, public vector<String> {
  public:
    StringVectorListBoxModel() = default;
    StringVectorListBoxModel(StringVectorListBoxModel&&) = default;
    StringVectorListBoxModel(const StringVectorListBoxModel&) = default;
    StringVectorListBoxModel& operator =(const StringVectorListBoxModel&) = default;
    StringVectorListBoxModel(const initializer_list<String>& il) : vector<String>(il) {}
    
    function<void(int row)> onDoubleClick;

  protected:
    int getNumRows() override {return static_cast<int>(size());}
    
    void listBoxItemDoubleClicked(int row, const MouseEvent& e) override {
      ListBoxModel::listBoxItemDoubleClicked(row, e);
      if (onDoubleClick) onDoubleClick(row);
    }
    
    void paintListBoxItem(int rowNumber, Graphics& g, int width, int height, bool rowIsSelected) override {
      if (rowIsSelected) g.fillAll(Colours::dodgerblue);
      
      g.setColour(LookAndFeel::getDefaultLookAndFeel().findColour(Label::textColourId));
      g.setFont(height * 0.7f);
      g.drawText(at(rowNumber), 5, 0, width, height, Justification::centredLeft, true);
    }
  };
  
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ListBox example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 360, 270);
      setContentOwned(&mainComponent, false);

      stringVectorListmodel1.onDoubleClick = [&](int row) {
        auto item = *(stringVectorListmodel1.begin() + row);
        stringVectorListmodel1.erase(stringVectorListmodel1.begin() + row);
        listBox1.updateContent();
        stringVectorListmodel2.push_back(item);
        sort(stringVectorListmodel2.begin(), stringVectorListmodel2.end());
        listBox2.updateContent();
      };

      listBox1.setBounds(10, 10, 165, 220);
      listBox1.setModel(&stringVectorListmodel1);
      listBox1.selectRow(0);
      mainComponent.addAndMakeVisible(&listBox1);

      stringVectorListmodel2.onDoubleClick = [&](int row) {
        auto item = *(stringVectorListmodel2.begin() + row);
        stringVectorListmodel2.erase(stringVectorListmodel2.begin() + row);
        listBox2.updateContent();
        stringVectorListmodel1.push_back(item);
        listBox1.updateContent();
      };

      listBox2.setBounds(185, 10, 165, 220);
      listBox2.setModel(&stringVectorListmodel2);
      mainComponent.addAndMakeVisible(&listBox2);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    Component mainComponent;
    StringVectorListBoxModel stringVectorListmodel1 {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"};
    ListBox listBox1;
    StringVectorListBoxModel stringVectorListmodel2;
    ListBox listBox2;
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

START_JUCE_APPLICATION(ListBoxExample::Application)
