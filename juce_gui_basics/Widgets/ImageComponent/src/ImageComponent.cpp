#include <JuceHeader.h>

namespace ImageComponentExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"ImageComponent example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 300, 365);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      comboBox1.setBounds(20, 20, 260, 25);
      comboBox1.addItemList({"top-left", "top-right", "bottom-left", "bottom-right", "Center" , "Stretch to fit", "Fill destination", "Only reduce size", "Only Increase size", "Do not resize"}, 1);
      comboBox1.onChange = [&] {
        switch(comboBox1.getSelectedId()) {
          case 1 : imageComponent1.setImagePlacement(RectanglePlacement::yTop | RectanglePlacement::xLeft | RectanglePlacement::doNotResize); break;
          case 2 : imageComponent1.setImagePlacement(RectanglePlacement::yTop | RectanglePlacement::xRight | RectanglePlacement::doNotResize); break;
          case 3 : imageComponent1.setImagePlacement(RectanglePlacement::yBottom | RectanglePlacement::xLeft | RectanglePlacement::doNotResize); break;
          case 4 : imageComponent1.setImagePlacement(RectanglePlacement::yBottom | RectanglePlacement::xRight | RectanglePlacement::doNotResize); break;
          case 5 : imageComponent1.setImagePlacement(RectanglePlacement::centred | RectanglePlacement::doNotResize); break;
          case 6 : imageComponent1.setImagePlacement(RectanglePlacement::stretchToFit); break;
          case 7 : imageComponent1.setImagePlacement(RectanglePlacement::fillDestination); break;
          case 8 : imageComponent1.setImagePlacement(RectanglePlacement::onlyReduceInSize); break;
          case 9 : imageComponent1.setImagePlacement(RectanglePlacement::onlyIncreaseInSize); break;
          case 10 : imageComponent1.setImagePlacement(RectanglePlacement::doNotResize); break;
        }
      };
      comboBox1.setSelectedId(1);
      mainComponent.addAndMakeVisible(comboBox1);
      
      auto imagePath = File::getSpecialLocation(File::SpecialLocationType::currentExecutableFile).getParentDirectory();
      if ((SystemStats::getOperatingSystemType() & SystemStats::MacOSX) == SystemStats::MacOSX) {
        imagePath = imagePath.getParentDirectory();
        imagePath = imagePath.getParentDirectory();
        imagePath = imagePath.getParentDirectory();
      }
      imagePath = imagePath.getFullPathName() + File::getSeparatorString() + "Resources" + File::getSeparatorString() + "Logo.png";
      imageComponent1.setBounds(20, 65, 260, 260);
      imageComponent1.setImage(ImageFileFormat::loadFrom(imagePath), RectanglePlacement::yTop | RectanglePlacement::xLeft | RectanglePlacement::doNotResize);
      mainComponent.addAndMakeVisible(imageComponent1);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    void resized() override {
      DocumentWindow::resized();
      comboBox1.setSize(getWidth() - 40, comboBox1.getHeight());
      imageComponent1.setSize(getWidth() - 40, getHeight() - 95);
    }

  private:
    Component mainComponent;
    ComboBox comboBox1;
    ImageComponent imageComponent1;
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

START_JUCE_APPLICATION(ImageComponentExample::Application)
