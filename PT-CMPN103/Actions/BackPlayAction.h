#pragma once
#include "Action.h"
class BackPlayAction :
	public Action
{
public:
	BackPlayAction(ApplicationManager*pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	~BackPlayAction();
};

