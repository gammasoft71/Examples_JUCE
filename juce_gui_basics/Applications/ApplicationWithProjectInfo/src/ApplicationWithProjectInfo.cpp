#include <JuceHeader.h>

namespace ApplicationWithProjectInfoExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {ProjectInfo::projectName, Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setResizable(true, true);
      setBounds(200, 100, 350, 130);
      setContentOwned(&mainComponent, false);
      
      company.setBounds(10, 10, 100, 25);
      company.setText("Company name", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&company);
      
      product.setBounds(10, 40, 100, 25);
      product.setText("Product name", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&product);
      
      version.setBounds(10, 70, 100, 25);
      version.setText("Product Version", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&version);
      
      companyName.setBounds(120, 10, 220, 25);
      companyName.setReadOnly(true);
      companyName.setText(ProjectInfo::companyName, NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&companyName);
      
      productName.setBounds(120, 40, 220, 25);
      productName.setReadOnly(true);
      productName.setText(ProjectInfo::projectName, NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&productName);
      
      productVersion.setBounds(120, 70, 220, 25);
      productVersion.setReadOnly(true);
      productVersion.setText(ProjectInfo::versionString, NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&productVersion);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    void resized() override {
      DocumentWindow::resized();
      companyName.setSize(getWidth() - 130, companyName.getHeight());
      productName.setSize(getWidth() - 130, productName.getHeight());
      productVersion.setSize(getWidth() - 130, productVersion.getHeight());
    }
    
  private:
    Component mainComponent;
    Label company;
    Label product;
    Label version;
    TextEditor companyName;
    TextEditor productName;
    TextEditor productVersion;
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

START_JUCE_APPLICATION(ApplicationWithProjectInfoExample::Application)
