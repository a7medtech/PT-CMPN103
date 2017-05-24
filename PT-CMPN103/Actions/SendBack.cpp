#include "SendBack.h"

SendBack::SendBack(ApplicationManager* pApp) :Action(pApp)
{
}

void SendBack::ReadActionParameters()
{
}

void SendBack::Execute()
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
		pManager->SendToBack();
		pManager->UpdateInterface();
	}
}

SendBack::~SendBack()
{
}