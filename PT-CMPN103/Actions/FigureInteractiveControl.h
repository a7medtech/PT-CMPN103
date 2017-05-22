#pragma once
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\project\PT-CMPN103\PT-CMPN103\Actions\Action.h"
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

