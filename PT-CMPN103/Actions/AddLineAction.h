#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Action.h"

//Add Line Action Class
class AddLineAction : public Action
{
private:
	Point P1, P2; //Line start and end points
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager* pApp);

	//Reads Line Parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};

#endif
