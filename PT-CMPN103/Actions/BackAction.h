#ifndef BACKACTION_H
#define BACKACTION_H
#include "../ApplicationManager.h"
#include "../Actions/Action.h"



class BackAction :
	public Action
{
public:
	BackAction(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~BackAction();
};











#endif