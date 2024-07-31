#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void shouldDoHardDifficulty(bool selectedHard);
    void shouldDoMultiplayer(bool selectedMultiplayer);

    void pongSetup(int ballRadius1, int playerWidth1, int playerHeight1, int screenWidth1, int screenHeight1);
    void pongStart();
    void receiveTouchDestination(int y);
protected:
    ModelListener* modelListener;

    void updateButtonPlayerDestination();
    void changePlayerDestination(int y, int player);
    void updateAIpos();
    void updateAIposHard();
    void updateAIposNormal();
    void updatePlayerPosition();
    void updateBallPosition();
    void checkCollision();
    void increaseBallSpeed();
    void redrawPong();
    void redrawBounces();
    void endPongGame();
};

#endif // MODEL_HPP
