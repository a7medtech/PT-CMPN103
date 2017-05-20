#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../ApplicationManager.h"


class Copy :
	public Action
{
	
public:
	Copy(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy();
};

