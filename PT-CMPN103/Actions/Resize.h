#pragma once
#include "..\Actions\Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class ResizeAction :public Action

{

private:
	int resizeprec;
public:
	ResizeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() ;
	virtual void Execute() ;
};