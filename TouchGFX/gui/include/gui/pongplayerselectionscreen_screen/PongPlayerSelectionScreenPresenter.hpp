#ifndef PONGPLAYERSELECTIONSCREENPRESENTER_HPP
#define PONGPLAYERSELECTIONSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PongPlayerSelectionScreenView;

class PongPlayerSelectionScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PongPlayerSelectionScreenPresenter(PongPlayerSelectionScreenView& v);

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

    virtual ~PongPlayerSelectionScreenPresenter() {}

    void setSingleplayer();
    void setMultiplayer();

private:
    PongPlayerSelectionScreenPresenter();

    PongPlayerSelectionScreenView& view;
};

#endif // PONGPLAYERSELECTIONSCREENPRESENTER_HPP
