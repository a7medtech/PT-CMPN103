#include "Action.h"
#include "../ApplicationManager.h"

class Move
	:public Action {
		Point p;
		CFigure** selected;
		int selectedCount;
public:
	Move(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Move();
};