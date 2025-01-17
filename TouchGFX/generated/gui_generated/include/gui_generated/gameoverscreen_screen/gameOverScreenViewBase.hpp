/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef GAMEOVERSCREENVIEWBASE_HPP
#define GAMEOVERSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/gameoverscreen_screen/gameOverScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class gameOverScreenViewBase : public touchgfx::View<gameOverScreenPresenter>
{
public:
    gameOverScreenViewBase();
    virtual ~gameOverScreenViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::TextArea textArea1;
    touchgfx::ButtonWithLabel returnButton;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<gameOverScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // GAMEOVERSCREENVIEWBASE_HPP
