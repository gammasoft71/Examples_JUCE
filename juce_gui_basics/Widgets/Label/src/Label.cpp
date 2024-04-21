#include <JuceHeader.h>

namespace LabelExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Label example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      setBounds(200, 100, 390, 385);
      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      
      label1.setBounds(10, 50, 100, 23);
      label1.setText("Lorem ipsum", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&label1);
      
      label2.setTopLeftPosition(10, 100);
      label2.setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit.", NotificationType::dontSendNotification);
      label2.setSize(label2.getFont().getStringWidth(label2.getText()), label2.getFont().getHeight());
      mainComponent.addAndMakeVisible(&label2);
      
      label3.setBounds(10, 150, 100, 23);
      label3.setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit.", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&label3);
      
      label4.setBounds(10, 200, 350, 150);
      label4.setJustificationType(Justification::centredTop);
      label4.setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus.Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim.Pellentesque congue. Ut in risus volutpat libero pharetra tempor.Cras vestibulum bibendum augue. Praesent egestas leo in pede.Praesent blandit odio eu enim.Pellentesque sed dui ut augue blandit sodales.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum.Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar.Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula.Pellentesque rhoncus nunc et augue.Integer id felis.Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas.Lorem ipsum dolor sit amet, consectetuer adipiscing elit.Morbi vel erat non mauris convallis vehicula.Nulla et sapien.Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat.Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus.Fusce vulputate sem at sapien.Vivamus leo. Aliquam euismod libero eu enim.Nulla nec felis sed leo placerat imperdiet.Aenean suscipit nulla in justo.Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus.Curabitur eu amet.\n", NotificationType::dontSendNotification);
      mainComponent.addAndMakeVisible(&label4);
    }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::quit();}
    void resized() override {
      DocumentWindow::resized();
      label4.setSize(getWidth() - 40, getHeight() - 235);
    }
    
  private:
    Component mainComponent;
    Label label1;
    Label label2;
    Label label3;
    Label label4;
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

START_JUCE_APPLICATION(LabelExample::Application)
