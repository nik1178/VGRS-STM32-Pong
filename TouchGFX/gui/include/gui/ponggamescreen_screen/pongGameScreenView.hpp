#ifndef PONGGAMESCREENVIEW_HPP
#define PONGGAMESCREENVIEW_HPP

#include <gui_generated/ponggamescreen_screen/pongGameScreenViewBase.hpp>
#include <gui/ponggamescreen_screen/pongGameScreenPresenter.hpp>

class pongGameScreenView : public pongGameScreenViewBase
{
public:
    pongGameScreenView();
    virtual ~pongGameScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // Press, drag and release handlers
    void handleDragEvent(const DragEvent& evt);
    void handleClickEvent(const ClickEvent& evt);

    void redrawPong(int leftPlayerY, int rightPlayerY, int ballX, int ballY);
    void redrawBounces(int bounces);
    void endPongGame();
protected:
};

#endif // PONGGAMESCREENVIEW_HPP
