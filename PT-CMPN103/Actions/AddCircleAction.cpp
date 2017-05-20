#include "AddCircleAction.h"
#include "../Figures/CCircle.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"
AddCircleAction::AddCircleAction(ApplicationManager *pApp):
	Action(pApp)
{}
void AddCircleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center then drag to a specific point");

	CircleGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	

}
void AddCircleAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	P2 = P1;
	double rad = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	//Create a Circle with initial parameters and adds it.
	CCircle *R = new CCircle(P1, rad, CircleGfxInfo);
	pManager->AddFigure(R);
	button tempB = LEFT_BUTTON;
	buttonstate tempState = BUTTON_UP;
	Point p;
	p.x = 0;
	p.y = 0;
	while (tempState == BUTTON_UP)
	{
		tempState= pManager->GetOutput()->getWindow()->GetButtonState(tempB, P2.x, P2.y);
		pManager->Drag(P2, p);
		
		pManager->UpdateInterface();
		Sleep(30);
	}
	
	pManager->GetOutput()->ClearStatusBar();
	Point temp;
	pManager->GetOutput()->getWindow()->WaitMouseClick(temp.x, temp.y);
	//Add the rectangle to the list of figures
	
}
