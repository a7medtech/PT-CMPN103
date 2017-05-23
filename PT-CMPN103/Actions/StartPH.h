#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class StartPH :
	public Action
{
	int originalSize; // figure list size
	int recC,triC,linC,cirC; // counts for each figure type
	CFigure** original; //figure list
	CFigure** displayable; // faked list to play on it
public:
	StartPH(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~StartPH();
};

