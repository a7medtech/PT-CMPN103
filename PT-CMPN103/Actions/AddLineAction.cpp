#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager* pApp):Action(pApp){}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Line: Click at start point then drag to target point");

	//Read start point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
    
	LineGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();
}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Line with the initial parameters.
	CLine*L = new CLine(P1, P2, LineGfxInfo);
	pManager->AddFigure(L);
	button tempB = LEFT_BUTTON;
	buttonstate tempState = BUTTON_UP;
	Sleep(30);
	Point p;
	p.x = 0;
	p.y = 0;
	while (tempState == BUTTON_UP)
	{
		tempState = pManager->GetOutput()->getWindow()->GetButtonState(tempB, P2.x, P2.y);
		pManager->Drag(P2,p);
		pManager->UpdateDrawing();
		Sleep(30);
	}

	pManager->GetOutput()->ClearStatusBar();
	Point temp;
	pManager->GetOutput()->getWindow()->WaitMouseClick(temp.x, temp.y);
	//Add the rectangle to the list of figures
	
}