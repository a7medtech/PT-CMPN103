#pragma once
#include "Action.h"
class FigureInteractiveControl :
	public Action
{
	Point P;
	
public:
	FigureInteractiveControl(ApplicationManager *pApp, Point s);
	static bool SelORInt;

	virtual void ReadActionParameters();

	//process the action to the ApplicationManager
	virtual void Execute();

	~FigureInteractiveControl();
};

