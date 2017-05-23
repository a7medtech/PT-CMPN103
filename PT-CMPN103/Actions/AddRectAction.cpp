#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	RectGfxInfo.isFilled = false;

	pOut->PrintMessage("New Rectangle: Click the first corner then drag to the target corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	

}


//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	

	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	button tempB = LEFT_BUTTON;
	buttonstate tempState = BUTTON_UP;
	Point p;
	p.x = 0;
	p.y = 0;
	while (tempState == BUTTON_UP)
	{
		tempState = pManager->GetOutput()->getWindow()->GetButtonState(tempB, P2.x, P2.y);
		pManager->Drag(P2, p);
		pManager->UpdateDrawing();
		Sleep(30);
	}

	pManager->GetOutput()->ClearStatusBar();
	Point temp;
	pManager->GetOutput()->getWindow()->WaitMouseClick(temp.x, temp.y);
}
