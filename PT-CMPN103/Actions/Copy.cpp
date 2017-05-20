#include "Copy.h"



Copy::Copy(ApplicationManager *pApp): Action(pApp)
{
}


void Copy::ReadActionParameters()
{
}


void Copy::Execute() 
{
	pManager->CopySelFigToCP();
	
}

Copy::~Copy()
{
}
