#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void redrawPong(int leftPlayerY, int rightPlayerY, int ballX, int ballY, int playerWidth, int playerLength, int ballRadius) { }
    virtual void redrawBounces(int bounces) { }
    virtual void endPongGame() { }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
