#include "SendBack.h"

SendBack::SendBack(ApplicationManager* pApp) :Action(pApp)
{
}

void SendBack::ReadActionParameters()
{
}

void SendBack::Execute()
{
	pManager->SendToBack();
	pManager->UpdateInterface();
}

SendBack::~SendBack()
{
}