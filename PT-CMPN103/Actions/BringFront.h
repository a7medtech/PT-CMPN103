#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class BringFront :
	public Action
{
public:
	BringFront(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
	~BringFront();
};

