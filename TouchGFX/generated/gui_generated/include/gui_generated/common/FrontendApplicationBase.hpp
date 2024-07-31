/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoScreen1ScreenNoTransition();
    }

    // Screen1
    void gotoScreen1ScreenNoTransition();

    // PongPlayerSelectionScreen
    void gotoPongPlayerSelectionScreenScreenNoTransition();

    // difficultySelectionScreen
    void gotodifficultySelectionScreenScreenNoTransition();

    // pongGameScreen
    void gotopongGameScreenScreenNoTransition();

    // gameOverScreen
    void gotogameOverScreenScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Screen1
    void gotoScreen1ScreenNoTransitionImpl();

    // PongPlayerSelectionScreen
    void gotoPongPlayerSelectionScreenScreenNoTransitionImpl();

    // difficultySelectionScreen
    void gotodifficultySelectionScreenScreenNoTransitionImpl();

    // pongGameScreen
    void gotopongGameScreenScreenNoTransitionImpl();

    // gameOverScreen
    void gotogameOverScreenScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
