#include <gui/ponggamescreen_screen/pongGameScreenView.hpp>
#include <gui/ponggamescreen_screen/pongGameScreenPresenter.hpp>

pongGameScreenPresenter::pongGameScreenPresenter(pongGameScreenView& v)
    : view(v)
{

}

void pongGameScreenPresenter::activate()
{

}

void pongGameScreenPresenter::deactivate()
{

}

void pongGameScreenPresenter::pongSetup(int ballRadius, int playerWidth, int playerHeight, int screenWidth, int screenHeight) {
	model->pongSetup(ballRadius, playerWidth, playerHeight, screenWidth, screenHeight);
}

void pongGameScreenPresenter::pongStart() {
	model->pongStart();
}

void pongGameScreenPresenter::receiveDragEvent(const DragEvent& evt) {
	int y = (int) evt.getNewY();

	model->receiveTouchDestination(y);
}

void pongGameScreenPresenter::receiveClickEvent(const ClickEvent& evt) {
	//int x = (int) evt.getX();
	int y = (int) evt.getY();

	model->receiveTouchDestination(y);
}

void pongGameScreenPresenter::redrawPong(int leftPlayerY, int rightPlayerY, int ballX, int ballY, int playerWidth, int playerLength, int ballRadius) {
	view.redrawPong(leftPlayerY - playerLength/2, rightPlayerY - playerLength/2, ballX-ballRadius, ballY-ballRadius);
}

void pongGameScreenPresenter::redrawBounces(int bounces) {
	view.redrawBounces(bounces);
}

void pongGameScreenPresenter::endPongGame() {
	view.endPongGame();
}
