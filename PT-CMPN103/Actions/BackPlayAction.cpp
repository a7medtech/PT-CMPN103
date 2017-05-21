#include "BackPlayAction.h"
#include "../ApplicationManager.h"


BackPlayAction::BackPlayAction(ApplicationManager*pApp):Action(pApp)
{
}

void BackPlayAction::Execute()
{
	pManager->GetOutput()->CreatePlayToolBar();
	UI.BkGrndColor = GREY;
}
void BackPlayAction::ReadActionParameters()
{

}

BackPlayAction::~BackPlayAction()
{
}
