#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"

class Select :
	public Action {
		Point p;
public:
	Select(ApplicationManager*,Point);
	virtual void Execute();
	virtual void ReadActionParameters();
	~Select();
};
