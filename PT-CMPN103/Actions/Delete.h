#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class Delete :
	public Action
{
public:
	Delete(ApplicationManager*App);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Delete();
};

