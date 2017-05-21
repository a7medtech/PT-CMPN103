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
	pManager->AdjustOriginalList();
	 pManager->RandomizeFigures();
	 pManager->StartNewScrambleGame();
	 

}
StartScrumble::~StartScrumble()
{
}
