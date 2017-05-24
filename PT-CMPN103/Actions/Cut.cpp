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
	int size;
	Output* pOut = pManager->GetOutput();
	pManager->GetSelectedFigCount(size);
	if (size == 0)
	{
		pOut->PrintMessage("ERROR !!! the chosen operation will make no change ");
		Sleep(800);
	}
	else
	{
		pManager->CutSelFigToCP();
	}
}

Cut::~Cut()
{
}
