#pragma once
#include"Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class ExitAction :public Action
{
string yesno;
public:
	ExitAction(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();



};