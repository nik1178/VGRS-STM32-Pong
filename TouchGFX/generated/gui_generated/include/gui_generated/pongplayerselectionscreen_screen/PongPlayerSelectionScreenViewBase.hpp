/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef PONGPLAYERSELECTIONSCREENVIEWBASE_HPP
#define PONGPLAYERSELECTIONSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/pongplayerselectionscreen_screen/PongPlayerSelectionScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class PongPlayerSelectionScreenViewBase : public touchgfx::View<PongPlayerSelectionScreenPresenter>
{
public:
    PongPlayerSelectionScreenViewBase();
    virtual ~PongPlayerSelectionScreenViewBase();
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void singleplayerButtonPressed()
    {
        // Override and implement this function in PongPlayerSelectionScreen
    }
    virtual void multiplayerButtonPressed()
    {
        // Override and implement this function in PongPlayerSelectionScreen
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Button onePlayerButton;
    touchgfx::Button twoPlayerButton;
    touchgfx::TextArea onePlayerTextArea;
    touchgfx::TextArea twoPlayerTextArea;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<PongPlayerSelectionScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // PONGPLAYERSELECTIONSCREENVIEWBASE_HPP
