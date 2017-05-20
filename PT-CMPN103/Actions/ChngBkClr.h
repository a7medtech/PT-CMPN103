#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ChngBkClr :
	public Action
{
public:
	ChngBkClr(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChngBkClr();
};
