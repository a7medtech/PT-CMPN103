#pragma once
#include "Action.h"
class ScrambleAndFind :
	public Action
{
public:
	ScrambleAndFind(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ScrambleAndFind();
};

