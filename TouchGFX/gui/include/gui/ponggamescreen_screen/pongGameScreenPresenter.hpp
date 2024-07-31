#ifndef PONGGAMESCREENPRESENTER_HPP
#define PONGGAMESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class pongGameScreenView;

class pongGameScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    pongGameScreenPresenter(pongGameScreenView& v);

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

    virtual ~pongGameScreenPresenter() {}

	void pongSetup(int ballRadius, int playerWidth, int playerHeight, int screenWidth, int screenHeight);
	void pongStart();

    void receiveDragEvent(const DragEvent& evt);
    void receiveClickEvent(const ClickEvent& evt);
    void redrawPong(int leftPlayerY, int rightPlayerY, int ballX, int ballY, int playerWidth, int playerLength, int ballRadius);
    void redrawBounces(int bounces);
    void endPongGame();

private:
    pongGameScreenPresenter();

    pongGameScreenView& view;
};

#endif // PONGGAMESCREENPRESENTER_HPP
