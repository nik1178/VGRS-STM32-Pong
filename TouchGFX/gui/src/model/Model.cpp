#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "cmsis_os.h"

extern "C"
{
	extern osMessageQueueId_t buttonQueueHandle;
}

Model::Model() : modelListener(0)
{

}

// Game setup
bool gameRunning = true; // Change default to false later

const int maxPlayerMoveSpeed = 10; // How fast the players can move up and down

bool multiplayer = false;
bool hardDifficulty = false;

int screenWidth = 480;
int screenHeight = 272;

int ballRadius = 0;
int playerWidth = 0;
int playerLength = 0;

// Player movement
int leftPlayerY = 0; // LEFT == PLAYER 1. Represents center of paddle
int leftPlayerDestinationY = 0;
int rightPlayerY = 0; // Change to default position later
int rightPlayerDestinationY = 0;

// Game progression trackers
const int ballSpeedDefault = 2;
int ballSpeed = ballSpeedDefault;
const int ballSpeedAdder = 25; // Divide by 100 for actual speed increase
int ballSpeedAddCounter = 0;
int bounces = 0;

const int ballXDefault = screenWidth/2;
const int ballYDefault = screenHeight/2;
int ballX = ballXDefault;
int ballY = ballYDefault;
int ballHorizontalDirection = 1; // 1 == right, -1 == left
int ballVerticalDirection = 1;

// Hard AI variables
int lastHitY = -100;
int lastBallYDirection = 0;

void Model::shouldDoHardDifficulty(bool selectedHard) {
	hardDifficulty = selectedHard;
}

void Model::shouldDoMultiplayer(bool selectedMultiplayer) {
	multiplayer = selectedMultiplayer;
}

void Model::pongSetup(int ballRadius1, int playerWidth1, int playerHeight1, int screenWidth1, int screenHeight1) {
	ballRadius = ballRadius1;
	playerWidth = playerWidth1;
	playerLength = playerHeight1;
	screenWidth = screenWidth1;
	screenHeight = screenHeight1;
}

void Model::pongStart() {
	ballSpeed = ballSpeedDefault;
	ballSpeedAddCounter = 0;
	bounces = 0;
	ballX = ballXDefault;
	ballY = ballYDefault;
	lastHitY = -100;

	gameRunning = true;
}

int playerTwoMovementDirection = -1;
void Model::tick()
{
	uint16_t buttonPinState = 0;
	osStatus_t status = osMessageQueueGet(buttonQueueHandle, &buttonPinState, NULL, 0);

	if (!gameRunning) {
		return;
	}

	if (!multiplayer) {
		updateAIpos();
	} else {

		if (status == osOK) {
			// Received new button direction
			if (buttonPinState == 0) {
				playerTwoMovementDirection = -1;
			} else {
				playerTwoMovementDirection = 1;
			}
		}

		updateButtonPlayerDestination();
	}
	updatePlayerPosition();
	updateBallPosition();
	checkCollision();
	redrawPong();
}

void Model::receiveTouchDestination(int y) {
	int player=1;
	if (multiplayer) {
		player=2;
	}
	changePlayerDestination(y, player);
}

void Model::updateButtonPlayerDestination() {
	leftPlayerDestinationY += maxPlayerMoveSpeed * playerTwoMovementDirection;
	if (leftPlayerDestinationY < 0 + playerLength/2) {
		leftPlayerDestinationY = 0 + playerLength/2;
	}
	if (leftPlayerDestinationY > screenHeight - playerLength/2) {
		leftPlayerDestinationY = screenHeight - playerLength/2;
	}
}

void Model::changePlayerDestination(int y, int player) {
	if (player==1) {
		leftPlayerDestinationY = y;
	} else {
		rightPlayerDestinationY = y;
	}
}

void Model::updateAIpos() {
	if (!hardDifficulty) {
		updateAIposNormal();
	} else {
		updateAIposHard();
	}
}

void Model::updateAIposHard() {
	if (lastHitY == -100) {
		updateAIposNormal();
		return;
	}

	int rawBallYDelta = 2*(screenWidth - 2*playerWidth - 2*ballRadius) * lastBallYDirection;
	int expectedBallY = lastHitY + rawBallYDelta;
	int bounceCount = 0;

	while (expectedBallY > screenHeight) {
		expectedBallY -= screenHeight - 2*ballRadius;
		bounceCount++;
	}
	while (expectedBallY < 0) {
		expectedBallY += screenHeight - 2*ballRadius;
		bounceCount++;
	}

	if (bounceCount%2==0) {
		rightPlayerDestinationY = expectedBallY;
	} else {
		rightPlayerDestinationY = (screenHeight - ballRadius) - expectedBallY;
	}
}

void Model::updateAIposNormal() {
	rightPlayerDestinationY = ballY;
}

void Model::updatePlayerPosition() {
	// Update left player
	int moveDistance = leftPlayerDestinationY - leftPlayerY;
	if (moveDistance > maxPlayerMoveSpeed) {
		moveDistance = maxPlayerMoveSpeed;
	}
	if (moveDistance < -maxPlayerMoveSpeed) {
		moveDistance = -maxPlayerMoveSpeed;
	}
	leftPlayerY += moveDistance;
	if (leftPlayerY-playerLength/2 < 0) {
		leftPlayerY = playerLength/2;
	}
	if (leftPlayerY + playerLength/2 > screenHeight) {
		leftPlayerY = screenHeight-playerLength/2;
	}

	// Update right player
	moveDistance = rightPlayerDestinationY - rightPlayerY;
	if (moveDistance > maxPlayerMoveSpeed) {
		moveDistance = maxPlayerMoveSpeed;
	}
	if (moveDistance < -maxPlayerMoveSpeed) {
		moveDistance = -maxPlayerMoveSpeed;
	}
	rightPlayerY += moveDistance;
	if (rightPlayerY-playerLength/2 < 0) {
		rightPlayerY = playerLength/2;
	}
	if (rightPlayerY + playerLength/2 > screenHeight) {
		rightPlayerY = screenHeight-playerLength/2;
	}
}

void Model::updateBallPosition() {
	ballX += ballSpeed * ballHorizontalDirection;
	ballY += ballSpeed * ballVerticalDirection;
}

void Model::checkCollision() {
	// Top collision
	if (ballY <= 0 + ballRadius) {
		ballY = ballRadius + (ballRadius - ballY);
		ballVerticalDirection = 1;
	}
	// Bottom collision
	if (ballY >= screenHeight - ballRadius) {
		ballY -= 2*( ballY - (screenHeight-ballRadius) );
		ballVerticalDirection = -1;
	}

	// Left paddle collision - Check if ball left enough and moving left
	if (ballHorizontalDirection == -1 && ballX <= 0 + playerWidth + ballRadius) {
		// Check vertical collision - Check if bottom of ball is below top of player and top of ball is above bottom of player
		if ( (ballY + ballRadius >= leftPlayerY - playerLength/2) && (ballY - ballRadius <= leftPlayerY + playerLength/2) ) {
			increaseBallSpeed();
			ballHorizontalDirection = 1;
			bounces++;
			redrawBounces();
			return;
		}
	}

	// Right player collision
	if (ballHorizontalDirection == 1 && ballX >= screenWidth - playerWidth - ballRadius) {
		// Check vertical collision - Check if bottom of ball is below top of player and top of ball is above bottom of player
		if ( (ballY + ballRadius >= rightPlayerY - playerLength/2) && (ballY - ballRadius <= rightPlayerY + playerLength/2) ) {
			lastHitY = ballY; // For hard AI
			lastBallYDirection = ballVerticalDirection;

			increaseBallSpeed();
			ballHorizontalDirection = -1;
			bounces++;
			redrawBounces();
			return;
		}
	}

	// Game over collision
	// Left
	if (ballX <= 0 + ballRadius) {
		endPongGame();
		return;
	}
	// Right
	if (ballX >= screenWidth - ballRadius) {
		endPongGame();
		return;
	}
}

void Model::increaseBallSpeed() {
	ballSpeedAddCounter += ballSpeedAdder;
	ballSpeed += ballSpeedAddCounter/100;
	ballSpeedAddCounter %= 100;
}

void Model::redrawPong() {
	modelListener->redrawPong(leftPlayerY, rightPlayerY, ballX, ballY, playerWidth, playerLength, ballRadius);
}

void Model::redrawBounces() {
	modelListener->redrawBounces(bounces);
}

void Model::endPongGame() {
	gameRunning = false;

	modelListener->endPongGame();
}
