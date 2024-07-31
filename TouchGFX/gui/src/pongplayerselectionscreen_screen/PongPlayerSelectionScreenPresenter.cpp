#include <gui/pongplayerselectionscreen_screen/PongPlayerSelectionScreenView.hpp>
#include <gui/pongplayerselectionscreen_screen/PongPlayerSelectionScreenPresenter.hpp>

PongPlayerSelectionScreenPresenter::PongPlayerSelectionScreenPresenter(PongPlayerSelectionScreenView& v)
    : view(v)
{

}

void PongPlayerSelectionScreenPresenter::activate()
{

}

void PongPlayerSelectionScreenPresenter::deactivate()
{

}

void PongPlayerSelectionScreenPresenter::setSingleplayer() {
	model->shouldDoMultiplayer(false);
}

void PongPlayerSelectionScreenPresenter::setMultiplayer() {
	model->shouldDoMultiplayer(true);
}
