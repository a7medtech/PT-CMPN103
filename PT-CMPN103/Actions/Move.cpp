#include "Move.h"


Move::Move(ApplicationManager* pApp)
	:Action(pApp){
}

void Move::ReadActionParameters(){
	pManager->GetSelectedFigCount(selectedCount);
	pManager->GetOutput()->PrintMessage("Click anywhere in the Drawing Area to move the figures to");
	pManager->GetInput()->GetPointClicked(p.x,p.y);
	pManager->GetOutput()->ClearStatusBar();
}

void Move::Execute(){
	ReadActionParameters();
	Point c0,c1,temp;
	//int dist;
	pManager->FindSelFigList(selected);
	pManager->GetSelectedFigCount(selectedCount);
	if (selectedCount > 1){
		selected[0]->getCenter(c0);
		selected[0]->Move(p);
		for (int i=1;i<selectedCount;i++){
			selected[i]->getCenter(c1);
			temp.x = abs(c0.x-c1.x);
			temp.y = abs(c0.y-c1.y);
			
			temp.x = p.x + temp.x;
			temp.y = p.y - temp.y;
			
			selected[i]->Move(temp);
		}
	}else {
			selected[0]->Move(p);
	}
}

Move::~Move(){	
}