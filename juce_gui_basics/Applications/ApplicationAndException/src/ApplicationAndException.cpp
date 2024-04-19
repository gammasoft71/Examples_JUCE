#include <stdexcept>
#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;
using namespace std;

namespace ApplicationAndExceptionExample {
  class Window1 : public DocumentWindow {
  public:
    Window1() : DocumentWindow {"Application and exception example", Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons} {
      // Uncomment the following line to raise the exception in Application::initialise method :
      //throw overflow_error("Creation object error");

      setContentOwned(&mainComponent, false);
      setResizable(true, true);
      setBounds(200, 100, 300, 300);
      
      buttonGenerateHandledException.setBounds(10, 10, 200, 25);
      buttonGenerateHandledException.setButtonText("Generate handled exception");
      buttonGenerateHandledException.onClick = [&] {
        try {
          throw invalid_argument("Exception handled generated");
        } catch (const exception& e) {
          NativeMessageBox::showMessageBoxAsync(MessageBoxIconType::NoIcon, "Exception handled", e.what(), this);
        }
      };
      mainComponent.addAndMakeVisible(&buttonGenerateHandledException);

      buttonGenerateException.setBounds(10, 50, 200, 25);
      buttonGenerateException.setButtonText("Generate exception");
      buttonGenerateException.onClick = [&] {
        throw invalid_argument("Exception generated");
      };
      mainComponent.addAndMakeVisible(&buttonGenerateException);

      buttonGenerateUnknownException.setBounds(10, 90, 200, 25);
      buttonGenerateUnknownException.setButtonText("Generate unknown exception");
      buttonGenerateUnknownException.onClick = [&] {
        throw "Unknown exception generated";
      };
      mainComponent.addAndMakeVisible(&buttonGenerateUnknownException);
   }
    
  protected:
    void closeButtonPressed() override {JUCEApplication::getInstance()->quit();}
    
  private:
    Component mainComponent;
    TextButton buttonGenerateHandledException;
    TextButton buttonGenerateException;
    TextButton buttonGenerateUnknownException;
  };
  
  class Application : public JUCEApplication {
  protected:
    const String getApplicationName() override {return "";}
    const String getApplicationVersion() override {return "";}
    
    void initialise(const String& commandLine) override {
      try {
        mainWindow = make_unique<Window1>();
        mainWindow->setVisible(true);
      } catch(const exception& e) {
        ShowExceptionError(&e);
      } catch(...) {
        ShowExceptionError(nullptr);
      } 
    }
    void shutdown() override {}
    void unhandledException(const std::exception* exception, const String &sourceFilename, int lineNumber) override {ShowExceptionError(exception);}
    
  private:
    static void ShowExceptionError(const std::exception* exception) {
      auto message = String {"Unhandled exception occurred in your application. If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n"} + (exception ? exception->what() : "Unknown exception occurred");
      if (NativeMessageBox::showOkCancelBox(MessageBoxIconType::WarningIcon, "Exception occurred", message) == true) {
        JUCE_TRY {
          MessageManager::getInstance()->runDispatchLoop();
        } JUCE_CATCH_EXCEPTION
      }
    }
    unique_ptr<DocumentWindow> mainWindow;
  };
}

START_JUCE_APPLICATION(ApplicationAndExceptionExample::Application)
