#include "../Actions/BackAction.h"

BackAction::BackAction(ApplicationManager*pApp) :Action(pApp)
{
}
void BackAction::Execute()
{
	pManager->GetOutput()->CreateMainToolBar();
}
void BackAction::ReadActionParameters()
{
}

BackAction::~BackAction()
{
}