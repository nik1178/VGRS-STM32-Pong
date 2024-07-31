/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/ponggamescreen_screen/pongGameScreenViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

pongGameScreenViewBase::pongGameScreenViewBase()
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    backgroundBox.setPosition(0, 0, 480, 272);
    backgroundBox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(backgroundBox);

    bouncesTextArea.setXY(103, 112);
    bouncesTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bouncesTextArea.setLinespacing(0);
    Unicode::snprintf(bouncesTextAreaBuffer, BOUNCESTEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_QM8E).getText());
    bouncesTextArea.setWildcard(bouncesTextAreaBuffer);
    bouncesTextArea.resizeToCurrentText();
    bouncesTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DGFA));
    bouncesTextArea.setAlpha(97);
    add(bouncesTextArea);

    playerLeftBox.setPosition(0, 0, 20, 80);
    playerLeftBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    add(playerLeftBox);

    playerRightBox.setPosition(460, 192, 20, 80);
    playerRightBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    add(playerRightBox);

    pongBall.setPosition(230, 126, 20, 20);
    pongBall.setCenter(10, 10);
    pongBall.setRadius(10);
    pongBall.setLineWidth(0);
    pongBall.setArc(0, 360);
    pongBallPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    pongBall.setPainter(pongBallPainter);
    add(pongBall);
}

pongGameScreenViewBase::~pongGameScreenViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void pongGameScreenViewBase::setupScreen()
{

}

void pongGameScreenViewBase::afterTransition()
{
    //pongScreenOpenedInteraction
    //When screen transition ends call virtual function
    //Call pongScreenOpened
    pongScreenOpened();
}

void pongGameScreenViewBase::handleKeyEvent(uint8_t key)
{
    if(0 == key)
    {
        //goToGameOverInteraction
        //When hardware button 0 clicked change screen to gameOverScreen
        //Go to gameOverScreen with no screen transition
        application().gotogameOverScreenScreenNoTransition();
    
    }
}