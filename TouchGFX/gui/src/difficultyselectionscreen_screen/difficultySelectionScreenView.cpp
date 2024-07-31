#include <gui/difficultyselectionscreen_screen/difficultySelectionScreenView.hpp>

difficultySelectionScreenView::difficultySelectionScreenView()
{

}

void difficultySelectionScreenView::setupScreen()
{
    difficultySelectionScreenViewBase::setupScreen();
}

void difficultySelectionScreenView::tearDownScreen()
{
    difficultySelectionScreenViewBase::tearDownScreen();
}

void difficultySelectionScreenView::normalDifficultyButtonPressed()
{
	presenter->changeToNormalDifficulty();
}
void difficultySelectionScreenView::hardDifficultyButtonPressed()
{
	// Override and implement this function in difficultySelectionScreen
	presenter->changeToHardDifficulty();
}
