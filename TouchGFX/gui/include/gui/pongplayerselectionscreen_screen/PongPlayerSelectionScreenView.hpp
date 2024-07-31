#ifndef PONGPLAYERSELECTIONSCREENVIEW_HPP
#define PONGPLAYERSELECTIONSCREENVIEW_HPP

#include <gui_generated/pongplayerselectionscreen_screen/PongPlayerSelectionScreenViewBase.hpp>
#include <gui/pongplayerselectionscreen_screen/PongPlayerSelectionScreenPresenter.hpp>

class PongPlayerSelectionScreenView : public PongPlayerSelectionScreenViewBase
{
public:
    PongPlayerSelectionScreenView();
    virtual ~PongPlayerSelectionScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void singleplayerButtonPressed();
    void multiplayerButtonPressed();
protected:
};

#endif // PONGPLAYERSELECTIONSCREENVIEW_HPP
