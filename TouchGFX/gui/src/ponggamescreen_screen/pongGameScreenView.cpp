#include <gui/ponggamescreen_screen/pongGameScreenView.hpp>

pongGameScreenView::pongGameScreenView()
{

}

int r;
void pongGameScreenView::setupScreen()
{
	pongBall.getRadius(r);
	presenter->pongSetup(r, playerLeftBox.getWidth(), playerLeftBox.getHeight(), getScreenWidth(), getScreenHeight());
	presenter->pongStart();
    pongGameScreenViewBase::setupScreen();
}

void pongGameScreenView::tearDownScreen()
{
    pongGameScreenViewBase::tearDownScreen();
}

void pongGameScreenView::handleDragEvent(const DragEvent& evt) {
	/*touchgfx::Unicode::snprintf(textArea1Buffer1, TEXTAREA1BUFFER1_SIZE, "%u", evt.getNewY());
	touchgfx::Unicode::snprintf(textArea1Buffer2, TEXTAREA1BUFFER2_SIZE, "%u", evt.getNewX());
	textArea1.invalidate();*/
	presenter->receiveDragEvent(evt);
}

void pongGameScreenView::handleClickEvent(const ClickEvent& evt) {
	/*touchgfx::Unicode::snprintf(textArea1Buffer1, TEXTAREA1BUFFER1_SIZE, "%u", evt.getY());
	touchgfx::Unicode::snprintf(textArea1Buffer2, TEXTAREA1BUFFER2_SIZE, "%u", evt.getX());
	textArea1.invalidate();*/
	presenter->receiveClickEvent(evt);
}

void pongGameScreenView::redrawPong(int leftPlayerY, int rightPlayerY, int ballX, int ballY) {

	pongBall.setPosition(ballX, ballY, 20, 20);
	playerLeftBox.setPosition(playerLeftBox.getX(), leftPlayerY, playerLeftBox.getWidth(), playerLeftBox.getHeight());
	playerRightBox.setPosition(playerRightBox.getX(), rightPlayerY, playerRightBox.getWidth(), playerRightBox.getHeight());

	backgroundBox.invalidate();

	pongBall.invalidate();
	playerLeftBox.invalidate();
	playerRightBox.invalidate();
}

void pongGameScreenView::redrawBounces(int bounces) {
	Unicode::snprintf(bouncesTextAreaBuffer, BOUNCESTEXTAREA_SIZE, "%u", bounces);
	bouncesTextArea.invalidate();
}

void pongGameScreenView::endPongGame() {
	application().gotogameOverScreenScreenNoTransition();
}
