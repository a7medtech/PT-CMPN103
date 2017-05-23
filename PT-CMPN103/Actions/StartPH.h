#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class StartPH :
	public Action
{
	int originalSize; // figure list size
	int recC,triC,linC,cirC; // counts for each figure type
	int right,wrong; // counts for right and wrong clicks
	Point p; // the point the user clicks
	CFigure* toBeSelected;
	CFigure* selected; // actual figure the user selected
	CFigure** original; //figure list
	CFigure** displayable; // faked list to play on it
public:
	StartPH(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~StartPH();
};

