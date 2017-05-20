#include "AddTrianAction.h"
#include "../Figures/CTriangle.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

AddTrianAction::AddTrianAction(ApplicationManager *pApp):Action(pApp)
{
}
void AddTrianAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner then drag to the second then to the third.");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	



	TrianGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TrianGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TrianGfxInfo.FillClr = pOut->getCrntFillColor();
	TrianGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	

}
//Execute the action
void AddTrianAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	P3 = P2 = P1;
	//Create a rectangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2,P3, TrianGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);

	button tempB = LEFT_BUTTON;
	buttonstate tempState = BUTTON_UP;
	while (tempState == BUTTON_UP)
	{
		tempState = pManager->GetOutput()->getWindow()->GetButtonState(tempB, P2.x, P2.y);
		pManager->Drag(P2 , P3);
		pManager->UpdateInterface();
		Sleep(30);
	}
	pManager->GetOutput()->getWindow()->WaitMouseClick(P2.x, P2.y);
	Sleep(30);
	tempState = BUTTON_UP;
	while (tempState == BUTTON_UP)
	{
		tempState = pManager->GetOutput()->getWindow()->GetButtonState(tempB, P3.x, P3.y);
		pManager->Drag(P2, P3);
		pManager->UpdateInterface();
		Sleep(30);
	}

	pManager->GetOutput()->ClearStatusBar();
	Point temp;
	pManager->GetOutput()->getWindow()->WaitMouseClick(temp.x, temp.y);


}


