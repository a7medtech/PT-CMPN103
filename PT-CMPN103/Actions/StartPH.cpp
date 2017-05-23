#include "StartPH.h"
#include "../Figures/CCircle.h"
#include "../Figures/CLine.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include <ctime>        /* time */
#include <stdlib.h>     /* srand, rand */


StartPH::StartPH(ApplicationManager* pApp)
	:Action(pApp)
{
}

void StartPH::ReadActionParameters(){
	original = pManager->getFigList(originalSize);
	for(int i=0;i<originalSize;i++){
		
	}
}

void StartPH::Execute(){
	ReadActionParameters();
while (original != nullptr){
	pManager->UpdateInterfacePH(original,originalSize);
	srand(time(0));
	int mode = rand()%4; //0 area, 1 type, 2 colors, 3 types+colors
	if (mode == 1){ // type
		int randomFig = rand() % originalSize + 1;
		toBeSelected = original[randomFig];
		string arr[4] = {"Rectangles","Triangles","Lines","Circles"};
		int i = rand()%4;
		pManager->GetOutput()->PrintMessage("Click on all "+arr[i]);
		do{
			pManager->GetInput()->GetPointClicked(p.x,p.y);
			selected = pManager->GetFigure(original,originalSize,p);
			if(selected == nullptr){
				wrong++;	
			}else{
				bool checkRight = false;
				switch(i){
				case 0:
					if(dynamic_cast<CRectangle*>(selected)){
						checkRight = true;
					}
					break;
				case 1:
					if(dynamic_cast<CTriangle*>(selected)){
						checkRight = true;
					}
					break;
				case 2:
					if(dynamic_cast<CLine*>(selected)){
						checkRight = true;
					}
					break;
				case 3:
					if(dynamic_cast<CCircle*>(selected)){
						checkRight = true;
					}
					break;
				}
				if(checkRight){
					right++;
					if (originalSize == 1){
						original = nullptr;
						originalSize--;
					}
					for(int j=0;j<originalSize;j++){
						if (selected->getID() == original[j]->getID()){
							original[j] = original[originalSize--];
						}
					}
					break;
				}else{
					wrong++;
					continue;
				}
			}
		}while(selected == nullptr);
		
	}else if (mode == 0){ // area
		int smallOrLarge = rand()%2; // 0 for small , 1 for large
		//int area = original[0]->getArea();
		if(smallOrLarge){
			for(int i = 1;i<originalSize;i++){
				
			}
		}else{
			
		}
	}else if(mode == 2){ // color
		int i = rand() % originalSize;
		Point p1,p2,p3;GfxInfo gfx;
		
	}else { // type + color
		
	}
}
}

StartPH::~StartPH()
{
}
