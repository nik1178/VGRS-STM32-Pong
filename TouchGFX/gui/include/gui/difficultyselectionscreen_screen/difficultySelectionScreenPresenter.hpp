#ifndef DIFFICULTYSELECTIONSCREENPRESENTER_HPP
#define DIFFICULTYSELECTIONSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class difficultySelectionScreenView;

class difficultySelectionScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    difficultySelectionScreenPresenter(difficultySelectionScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~difficultySelectionScreenPresenter() {}

    void changeToNormalDifficulty();
    void changeToHardDifficulty();

private:
    difficultySelectionScreenPresenter();

    difficultySelectionScreenView& view;
};

#endif // DIFFICULTYSELECTIONSCREENPRESENTER_HPP
