#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../ApplicationManager.h"


class CRectangle;
class CFigure;

class Cut :
	public Action
{
public:
	Cut(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Cut();
};

