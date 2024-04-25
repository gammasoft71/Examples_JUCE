#include <algorithm>
#include <JuceHeader.h>

using namespace std;

namespace DesktopExample {
  class ProgressTimer : public Timer {
  public:
    function<void()> onTick;
    
  private:
    void timerCallback() override {if (onTick) onTick();}
  };
  
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Display informations example", Colours::darkblue, DocumentWindow::allButtons} {
      setBounds(200, 100, 450, 350);
      setContentOwned(&desktopInformations, false);
      setResizable(true, true);
      
      desktopInformations.setColour(TextEditor::backgroundColourId, Colours::darkblue);
      desktopInformations.setColour(TextEditor::textColourId, Colours::yellow);
      desktopInformations.setFont({Font::getDefaultMonospacedFontName(), desktopInformations.getFont().getHeight(), desktopInformations.getFont().getStyleFlags()});
      desktopInformations.setMultiLine(true);
      desktopInformations.setReadOnly(true);
      auto text = String {};
      text += "Number of displays: " + String {Desktop::getInstance().getDisplays().displays.size()} + NewLine();
      auto index = 1;
      for (auto display : Desktop::getInstance().getDisplays().displays) {
        text += NewLine();
        text += "Display: " + String {index} + NewLine();
        text += "  Is main: " + String {display.isMain ? "true" : "false"} + NewLine();
        text += "  Total area: " + toString(display.totalArea) + NewLine();
        text += "  User area: " + toString(display.userArea) + NewLine();
        text += "  Safe area insets: " + toString(display.safeAreaInsets) + NewLine();
        text += "  keyboard insets: " + toString(display.keyboardInsets) + NewLine();
        text += "  Top-Left physical: {x=" + String {display.topLeftPhysical.getX()} + ", y=" + String {display.topLeftPhysical.getY()} + "}" + NewLine();
        text += "  Scale: " + String {display.scale} + NewLine();
        text += "  DPI: " + String {display.dpi} + NewLine();
        text += "  vertical Frequency (hz): " + (display.verticalFrequencyHz.has_value() ? String {display.verticalFrequencyHz.value(), 2} : "<unknown>") + NewLine();
      }
      
      desktopInformations.setText(text);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    
  private:
    static String toString(const Rectangle<int>& rect) {
      return "{x=" + String {rect.getX()} + ", y=" + String {rect.getY()} + ", width=" + String {rect.getWidth()} + ", height=" + String {rect.getHeight()} + "}";
    }
    static String toString(const BorderSize<int>& bs) {
      return "{left=" + String {bs.getLeft()} + ", top=" + String {bs.getTop()} + ", right=" + String {bs.getRight()} + ", bottom=" + String {bs.getBottom()} + "}";
    }
    TextEditor desktopInformations;
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

START_JUCE_APPLICATION(DesktopExample::Application)
