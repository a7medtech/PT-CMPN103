#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class PickHide:
	public Action
{
	int types[4];
public:
	PickHide(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PickHide();
};


