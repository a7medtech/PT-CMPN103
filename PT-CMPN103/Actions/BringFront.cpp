#include "BringFront.h"

BringFront::BringFront(ApplicationManager* pApp):Action(pApp)
{
}

void BringFront::ReadActionParameters()
{
}

void BringFront::Execute()
{
	pManager->BringtoFront();
	pManager->UpdateInterface();
}

BringFront::~BringFront()
{
}
