#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ChngDrawClr :
	public Action
{
public:
	ChngDrawClr(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChngDrawClr();
};