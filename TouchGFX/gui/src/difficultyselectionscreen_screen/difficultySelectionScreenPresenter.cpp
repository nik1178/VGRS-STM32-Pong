#include <gui/difficultyselectionscreen_screen/difficultySelectionScreenView.hpp>
#include <gui/difficultyselectionscreen_screen/difficultySelectionScreenPresenter.hpp>

difficultySelectionScreenPresenter::difficultySelectionScreenPresenter(difficultySelectionScreenView& v)
    : view(v)
{

}

void difficultySelectionScreenPresenter::activate()
{

}

void difficultySelectionScreenPresenter::deactivate()
{

}

void difficultySelectionScreenPresenter::changeToNormalDifficulty() {
	model->shouldDoHardDifficulty(false);
}

void difficultySelectionScreenPresenter::changeToHardDifficulty() {
	model->shouldDoHardDifficulty(true);
}
