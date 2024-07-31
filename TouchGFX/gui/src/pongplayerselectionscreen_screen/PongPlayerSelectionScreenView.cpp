#include <gui/pongplayerselectionscreen_screen/PongPlayerSelectionScreenView.hpp>

PongPlayerSelectionScreenView::PongPlayerSelectionScreenView()
{

}

void PongPlayerSelectionScreenView::setupScreen()
{
    PongPlayerSelectionScreenViewBase::setupScreen();
}

void PongPlayerSelectionScreenView::tearDownScreen()
{
    PongPlayerSelectionScreenViewBase::tearDownScreen();
}

void PongPlayerSelectionScreenView::singleplayerButtonPressed() {
	presenter->setSingleplayer();
}

void PongPlayerSelectionScreenView::multiplayerButtonPressed() {
	presenter->setMultiplayer();
}
