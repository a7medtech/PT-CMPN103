#pragma once
#include"Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
class Zoom :public Action
{
	static int zoomcounter;

public:
	Zoom(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	static int getzoomcounter();
	static void minuszoomcounter();
	static void pluszoomcounter();
	static void resetzoomcounter(); // to use it when i load a new graph
};