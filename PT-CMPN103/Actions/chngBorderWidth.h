#pragma once
#include"Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class chngBorderWidth :public Action
{
	int changeprec;
public:
	chngBorderWidth(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};