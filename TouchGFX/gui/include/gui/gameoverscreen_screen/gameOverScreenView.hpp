#ifndef GAMEOVERSCREENVIEW_HPP
#define GAMEOVERSCREENVIEW_HPP

#include <gui_generated/gameoverscreen_screen/gameOverScreenViewBase.hpp>
#include <gui/gameoverscreen_screen/gameOverScreenPresenter.hpp>

class gameOverScreenView : public gameOverScreenViewBase
{
public:
    gameOverScreenView();
    virtual ~gameOverScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // GAMEOVERSCREENVIEW_HPP
