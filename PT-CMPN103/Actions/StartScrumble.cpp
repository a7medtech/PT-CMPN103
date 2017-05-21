#include "StartScrumble.h"
#include "../ApplicationManager.h"


StartScrumble::StartScrumble(ApplicationManager*pApp):Action(pApp)
{
}

void StartScrumble::ReadActionParameters()
{

}
void StartScrumble::Execute()
{
	int c;
	pManager->GetFigCount(c);
	if (c == 0)
	{
		pManager->GetOutput()->PrintMessage("Draw some figures in the draw mode first ;)!");
		Sleep(1200);
	}
	else
	{
		pManager->AdjustOriginalList();
		pManager->RandomizeFigures();
		pManager->StartNewScrambleGame();
	}
	 

}
StartScrumble::~StartScrumble()
{
}
