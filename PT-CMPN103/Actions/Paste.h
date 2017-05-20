#pragma once
#include "Action.h"
class Paste :
	public Action
{

public:
	Paste(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Paste();
};

