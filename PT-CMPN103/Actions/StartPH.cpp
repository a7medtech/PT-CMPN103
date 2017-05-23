#include "StartPH.h"
#include "../CMUgraphicsLib/colors.h"
#include "../Figures/CCircle.h"
#include "../Figures/CLine.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include <ctime>        /* time */
#include <stdlib.h>     /* srand, rand */


StartPH::StartPH(ApplicationManager* pApp)
	:Action(pApp)
{
	right = wrong = recC = triC = linC = cirC = 0;
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
		int randomFig = rand() % originalSize;
		toBeSelected = original[randomFig];
		string arr[4] = {"Rectangle","Triangle","Line","Circle"};
		int i = rand()%4;
		pManager->GetOutput()->PrintMessage("Click on a "+arr[i]);
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
							original[j] = original[originalSize-- -1];
						}
					}
					break;
				}else{
					wrong++;
					break;
				}
			}
		}while(selected == nullptr);
		
	}else if (mode == 0){ // area
		double d1;
		double maxArea,area;
		Point p1,p2,p3;GfxInfo gfx;
		int smallOrLarge = rand()%2; // 0 for small , 1 for large
			for(int i = 1;i<originalSize;i++){
				original[i]->GetFigureParameters(p1,p2,p3,gfx);
				if(dynamic_cast<CCircle*>(original[i])){
					d1 = static_cast<CCircle*>(original[i])->getRadius();
					area = original[i]->getArea(d1,p1,p2,p3);
				}else {
					area = original[i]->getArea(d1,p1,p2,p3);
				}
				if (i == 0){
					maxArea = area;
				}else {
					if(smallOrLarge)
						if(maxArea < area)
							maxArea = area;
					else 
						if(maxArea > area)
							maxArea = area;
				}
			}
		
	}else if(mode == 2){ // color
		Point p1,p2,p3;GfxInfo gfx;
		bool filled;
		for(int i =0;i<originalSize;i++){
			original[i]->GetFigureParameters(p1,p2,p3,gfx);
			if(!gfx.isFilled){
				filled = true;
			}
		}
		if (filled){
			pManager->GetOutput()->PrintMessage("Pick a filled figure");
		}else {
			pManager->GetOutput()->PrintMessage("Pick a non-filled figure");
		}
		do{
			pManager->GetInput()->GetPointClicked(p.x,p.y);
			selected = pManager->GetFigure(original,originalSize,p);
			selected->GetFigureParameters(p1,p2,p3,gfx);
			if (selected == nullptr){
				wrong++;
				continue;
			}
			if (gfx.isFilled == filled){
				right++;
				if (originalSize == 1){
						original = nullptr;
						originalSize--;
				}
				for(int i = 0;i<originalSize;i++){
					if (original[i]->getID() == selected->getID())
						original[i] = original[originalSize-- -1];
				}
			}else {
				wrong++;
				break;
			}
		}while(selected == nullptr);
	}else { // type + color
		Point p1,p2,p3;GfxInfo gfx;
		int randomFig = rand() % originalSize + 1;
		toBeSelected = original[randomFig];
		string arr[4] = {"Rectangle","Triangle","Line","Circle"};
		int i = rand()%4;
		toBeSelected->GetFigureParameters(p1,p2,p3,gfx);
		if(gfx.isFilled){
			pManager->GetOutput()->getWindow()->SetPen(gfx.FillClr);
			pManager->GetOutput()->PrintMessage("Pick a filled "+arr[i]+" with this color");
			color c(0,0,0);
			pManager->GetOutput()->getWindow()->SetPen(c);
		}
		else{
			pManager->GetOutput()->PrintMessage("Pick a non-filled "+arr[i]);
		}
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
	}
}
}

StartPH::~StartPH()
{
}
