#ifndef DIFFICULTYSELECTIONSCREENVIEW_HPP
#define DIFFICULTYSELECTIONSCREENVIEW_HPP

#include <gui_generated/difficultyselectionscreen_screen/difficultySelectionScreenViewBase.hpp>
#include <gui/difficultyselectionscreen_screen/difficultySelectionScreenPresenter.hpp>

class difficultySelectionScreenView : public difficultySelectionScreenViewBase
{
public:
    difficultySelectionScreenView();
    virtual ~difficultySelectionScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void normalDifficultyButtonPressed();
    void hardDifficultyButtonPressed();
protected:
};

#endif // DIFFICULTYSELECTIONSCREENVIEW_HPP
