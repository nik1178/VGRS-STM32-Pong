/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/pongplayerselectionscreen_screen/PongPlayerSelectionScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

PongPlayerSelectionScreenViewBase::PongPlayerSelectionScreenViewBase() :
    buttonCallback(this, &PongPlayerSelectionScreenViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    onePlayerButton.setXY(120, 68);
    onePlayerButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_PRESSED_ID));
    onePlayerButton.setAction(buttonCallback);
    add(onePlayerButton);

    twoPlayerButton.setXY(120, 184);
    twoPlayerButton.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_MEDIUM_ROUNDED_PRESSED_ID));
    twoPlayerButton.setAction(buttonCallback);
    add(twoPlayerButton);

    onePlayerTextArea.setXY(158, 20);
    onePlayerTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    onePlayerTextArea.setLinespacing(0);
    onePlayerTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FREN));
    add(onePlayerTextArea);

    twoPlayerTextArea.setXY(158, 136);
    twoPlayerTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    twoPlayerTextArea.setLinespacing(0);
    twoPlayerTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3MOU));
    add(twoPlayerTextArea);
}

PongPlayerSelectionScreenViewBase::~PongPlayerSelectionScreenViewBase()
{

}

void PongPlayerSelectionScreenViewBase::setupScreen()
{

}

void PongPlayerSelectionScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &twoPlayerButton)
    {
        //twoPlayerButtonInteraction
        //When twoPlayerButton clicked change screen to pongGameScreen
        //Go to pongGameScreen with no screen transition
        application().gotopongGameScreenScreenNoTransition();
        //multiplayerChosenInteraction
        //When twoPlayerButton clicked call virtual function
        //Call multiplayerButtonPressed
        multiplayerButtonPressed();
    }
    if (&src == &onePlayerButton)
    {
        //onePlayerButtonInteraction
        //When onePlayerButton clicked change screen to difficultySelectionScreen
        //Go to difficultySelectionScreen with no screen transition
        application().gotodifficultySelectionScreenScreenNoTransition();
        //singleplayerChosenInteraction
        //When onePlayerButton clicked call virtual function
        //Call singleplayerButtonPressed
        singleplayerButtonPressed();
    }
}
