#include "Copy.h"



Copy::Copy(ApplicationManager *pApp): Action(pApp)
{
}


void Copy::ReadActionParameters()
{
}


void Copy::Execute() 
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
		pManager->CopySelFigToCP();
	}
}

Copy::~Copy()
{
}
