#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class PickHide:
	public Action
{
public:
	PickHide(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PickHide();
};


