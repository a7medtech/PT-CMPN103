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
	pManager->AddCPToFigList();
	Action*MoveToLoc = new Move(pManager);
	MoveToLoc->Execute();
	delete MoveToLoc;
	MoveToLoc = nullptr;
 }

Paste::~Paste()
{
}
