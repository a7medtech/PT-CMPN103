#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class SendBack :
	public Action
{
public:
	SendBack(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
	~SendBack();
};