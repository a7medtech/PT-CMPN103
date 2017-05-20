#include "Cut.h"
#include "Copy.h"


Cut::Cut(ApplicationManager *pApp) : Action(pApp)
{
}


void Cut::ReadActionParameters()
{
}

void Cut::Execute()
{
	pManager->CutSelFigToCP();
}

Cut::~Cut()
{
}
