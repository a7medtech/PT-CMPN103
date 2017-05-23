#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class StartPH :
	public Action
{
	CFigure* original[ApplicationManager::MaxFigCount];
	CFigure* displayable[ApplicationManager::MaxFigCount];
public:
	StartPH(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~StartPH();
};

