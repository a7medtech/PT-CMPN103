#pragma once

#include "..\Actions\Action.h"
class AddCircleAction :
	public Action
{
private:
	Point P1, P2; //Circle Center and  Corners
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager *pApp);
    //Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
};

