#include "Paste.h"
#include "../ApplicationManager.h"
#include "Move.h"



Paste::Paste(ApplicationManager*pApp):Action(pApp)
{
}


void Paste::ReadActionParameters()
{
}
void Paste::Execute()
{
	int size;
	pManager->GetCPIndex(size);
	if (size != 0)
	{
		pManager->AddCPToFigList();
		Action*MoveToLoc = new Move(pManager);
		MoveToLoc->Execute();
		delete MoveToLoc;
		MoveToLoc = nullptr;
	}
	else
	{
		pManager->GetOutput()->PrintMessage("There Is No Figures In The Clip Board!");
		Sleep(500);
	}
 }

Paste::~Paste()
{
}
