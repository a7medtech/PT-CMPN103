#pragma once
#include"Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class Zoomout :public Action
{
	static int zoomoutcounter;
public:
	Zoomout(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	static int getzoomoutcounter();
	static void minuszoomoutcounter();
	static void pluszoomoutcounter();
	static void resetzoomoutcounter(); // to set counter=0 when i load a new graph
};