#include "Select.h"


Select::Select(ApplicationManager* pApp,Point p):
	Action(pApp)
{
	this->p = p;
}

void Select::Execute(){
	pManager->SelectFigs(p);
	CFigure** dummy;
	pManager->FindSelFigList(dummy);
}

void Select::ReadActionParameters(){

}

Select::~Select() {
}
