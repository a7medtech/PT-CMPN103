#include "BringFront.h"

BringFront::BringFront(ApplicationManager* pApp):Action(pApp)
{
}

void BringFront::ReadActionParameters()
{
}

void BringFront::Execute()
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
		pManager->BringtoFront();
		pManager->UpdateInterface();
	}
}

BringFront::~BringFront()
{
}
