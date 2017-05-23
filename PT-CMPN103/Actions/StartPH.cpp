#include "StartPH.h"
#include "../Figures/CCircle.h"
#include "../Figures/CLine.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include <ctime>
#include <stdlib.h>     /* srand, rand */


StartPH::StartPH(ApplicationManager* pApp)
	:Action(pApp)
{
}

void StartPH::ReadActionParameters(){
	original = pManager->getFigList(originalSize);
	for (int i=0;i<originalSize;i++){
		if(dynamic_cast<CRectangle*>(original[i])){
			recC++;
		}else if(dynamic_cast<CCircle*>(original[i])){
			cirC++;
		}else if(dynamic_cast<CLine*>(original[i])){
			linC++;
		}else {
			triC++;
		}
		displayable[i] = original[i];
	}
}

void StartPH::Execute(){
	ReadActionParameters();
	srand(time(0));
	int randomFig = rand() % originalSize + 1;
}

StartPH::~StartPH()
{
}
