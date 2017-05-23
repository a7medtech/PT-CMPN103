#include "Move.h"


Move::Move(ApplicationManager* pApp)
	:Action(pApp){
}

void Move::ReadActionParameters(){
	pManager->FindSelFigList(selected);
	pManager->GetSelectedFigCount(selectedCount);
	pManager->GetOutput()->PrintMessage("Click anywhere in the Drawing Area to move the figures to");
	pManager->GetInput()->GetPointClicked(p.x,p.y);
	pManager->GetOutput()->ClearStatusBar();
}

void Move::Execute(){
	ReadActionParameters();
	Point c0,c00,c1,temp;
	
	pManager->GetSelectedFigCount(selectedCount);
	if (selectedCount > 1){
		selected[0]->getCenter(c0);
		selected[0]->Move(p);
		selected[0]->getCenter(c00);
		for (int i=1;i<selectedCount;i++){
			selected[i]->getCenter(c1);
			temp.x = abs(c0.x-c1.x);
			temp.y = abs(c0.y-c1.y);
			if (c0.x >= c1.x && c0.y >= c1.y){
				temp.x = c00.x - temp.x;
				temp.y = c00.y - temp.y;
			}else if(c0.x <= c1.x && c0.y >= c1.y){
				temp.x = c00.x + temp.x;
				temp.y = c00.y - temp.y;
			}else if(c0.x <= c1.x && c0.y <= c1.y ){
				temp.x = c00.x + temp.x;
				temp.y = c00.y + temp.y;
			}else {
				temp.x = c00.x - temp.x;
				temp.y = c00.y + temp.y;
			}
			
			selected[i]->Move(temp);
		}
	}else if(selectedCount == 1){
			selected[0]->Move(p);
	}
}

Move::~Move(){	
}