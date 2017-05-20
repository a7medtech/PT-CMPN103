#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ChngFillClr :
	public Action
{
public:
	ChngFillClr(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChngFillClr();
};