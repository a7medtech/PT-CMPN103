#include "FigureInteractiveControl.h"
#include "../ApplicationManager.h"
#include "Select.h"


bool FigureInteractiveControl::SelORInt = false;

FigureInteractiveControl::FigureInteractiveControl(ApplicationManager*pApp, Point s):Action(pApp)
{
	P= s;
}

void FigureInteractiveControl::ReadActionParameters()
{

}


void FigureInteractiveControl::Execute()
{
			pManager->ReferenceActionToClick(P);
}

FigureInteractiveControl::~FigureInteractiveControl()
{
}
