#pragma once
#include "Action.h"


class StartScrumble :
	public Action
{
public:
	StartScrumble(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~StartScrumble();
};

