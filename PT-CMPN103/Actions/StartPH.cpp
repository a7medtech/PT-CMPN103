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
	right = wrong = recC = triC = linC = cirC = 0;
	CFigure** copy;
	copy = pManager->getFigList(originalSize);
	for(int i=0;i<originalSize;i++){
		original[i] = copy[i];
		original[i]->SetSelected(false);
		if(dynamic_cast<CRectangle*>(copy[i]))
			recC++;
		else if(dynamic_cast<CCircle*>(copy[i]))
			cirC++;
		else if(dynamic_cast<CTriangle*>(copy[i]))
			triC++;
		else 
			linC++;
	}
}

void StartPH::Execute(){
	ReadActionParameters();
	p.x = 700;
	p.y = 700;
while (originalSize != 0 && (p.x / UI.MenuItemWidth != 1 || p.y > UI.ToolBarHeight)){
	pManager->GetOutput()->StartPickHideGame();
	pManager->UpdateInterfacePH(original,originalSize,right,wrong);
	srand(unsigned int(time(0)));
	int mode = 2;//rand()%4; //0 area, 1 type, 2 colors, 3 types+colors
	if (mode == 1){ // type
		string arr[4] = {"Rectangle","Triangle","Line","Circle"};
		int i;
		do{
			i = rand()%4;
			if(i == 0 && recC !=0)
				break;
			else if(i == 1 && triC !=0)
				break;
			else if(i == 2 && linC !=0)
				break;
			else if(i == 3 && cirC !=0)
				break;
		}while(true);
		pManager->GetOutput()->PrintMessage("Click on a "+arr[i]);
		do{
			pManager->GetInput()->GetPointClicked(p.x,p.y);
			if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 1)
				goto endofPH;
			else if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 0)
				goto restartofPH;
			selected = pManager->GetFigure(original,originalSize,p);
			if(selected != nullptr){
				bool checkRight = false;
				switch(i){
				case 0:
					if(dynamic_cast<CRectangle*>(selected)){
						checkRight = true;
						recC--;
					}
					break;
				case 1:
					if(dynamic_cast<CTriangle*>(selected)){
						checkRight = true;
						triC--;
					}
					break;
				case 2:
					if(dynamic_cast<CLine*>(selected)){
						checkRight = true;
						linC--;
					}
					break;
				case 3:
					if(dynamic_cast<CCircle*>(selected)){
						checkRight = true;
						cirC--;
					}
					break;
				}
				if(checkRight){
					right++;
					if (originalSize == 1){
						*original = nullptr;
						originalSize--;
						break;
					}
					for(int j=0;j<originalSize;j++){
						if (selected->getID() == original[j]->getID()){
							original[j] = original[originalSize-- -1];
							break;
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
		for(int i = 0;i<originalSize;i++){
				original[i]->GetFigureParameters(p1,p2,p3,gfx);
				if(dynamic_cast<CCircle*>(original[i])){
					d1 = static_cast<CCircle*>(original[i])->getRadius();
					area = original[i]->getArea(d1,p1,p2,p3);
				}else {
					area = original[i]->getArea(d1,p1,p2,p3);
				}
				if (i == 0){
					maxArea = area;
					toBeSelected = original[i];
				}else {
					if(smallOrLarge){
						if(maxArea > area){
							maxArea = area;
							toBeSelected = original[i];
						}
					}
					else{
						if(maxArea < area){
							maxArea = area;
							toBeSelected = original[i];
						}
					}
				}
			}
		if(smallOrLarge)
			pManager->GetOutput()->PrintMessage("Pick the biggest figure");
		else 
			pManager->GetOutput()->PrintMessage("Pick the smallest figure");
		do{
			pManager->GetInput()->GetPointClicked(p.x,p.y);
			if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 1)
					goto endofPH;
			else if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 0)
				goto restartofPH;
			selected = pManager->GetFigure(original,originalSize,p);
			if(selected != nullptr){
				if(selected->getID() == toBeSelected->getID()){
					right++;
					if (originalSize == 1){
						*original = nullptr;
						originalSize--;
						break;
					}
					for(int i = 0;i<originalSize;i++){
						if (original[i]->getID() == selected->getID())
							if(dynamic_cast<CRectangle*>(original[i]))
								recC--;
							else if(dynamic_cast<CTriangle*>(original[i]))
								triC--;
							else if(dynamic_cast<CLine*>(original[i]))
								linC--;
							else 
								cirC--;
							original[i] = original[originalSize-- -1];
							break;
					}	
					break;
				}else {
					wrong++;
				}
			}
		}while(selected == nullptr);
		
	}else if(mode == 2){ // color
		Point p1,p2,p3;GfxInfo gfx;
		bool filled = false;
		for(int i =0;i<originalSize;i++){
			original[i]->GetFigureParameters(p1,p2,p3,gfx);
			if(gfx.isFilled){
				filled = true;
				break;
			}
		}
		if (filled){
			pManager->GetOutput()->PrintMessage("Pick a filled figure");
		}else {
			pManager->GetOutput()->PrintMessage("Pick a non-filled figure");
		}
		do{
			pManager->GetInput()->GetPointClicked(p.x,p.y);
			if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 1)
					goto endofPH;
			else if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 0)
				goto restartofPH;
			selected = pManager->GetFigure(original,originalSize,p);
			if (selected != nullptr){
			selected->GetFigureParameters(p1,p2,p3,gfx);
				if (gfx.isFilled == filled){
					right++;
					if (originalSize == 1){
						*original = nullptr;
						originalSize--;
						break;
					}
					for(int i = 0;i<originalSize;i++){
						if (original[i]->getID() == selected->getID())
							if(dynamic_cast<CRectangle*>(original[i]))
								recC--;
							else if(dynamic_cast<CTriangle*>(original[i]))
								triC--;
							else if(dynamic_cast<CLine*>(original[i]))
								linC--;
							else 
								cirC--;
							original[i] = original[originalSize-- -1];
							break;
					}	
				}else {
					wrong++;
					break;
				}
			}
		}while(selected == nullptr);
		
	}else { // type + color
		Point p1,p2,p3;GfxInfo gfx;
		string type;
		int i;
		do{
			i = rand()%originalSize;
			toBeSelected = original[i];
			if(dynamic_cast<CRectangle*>(original[i]) && recC !=0){
				type = "Rectangle";
				i = 0;
				toBeSelected->GetFigureParameters(p1,p2,p3,gfx);
				break;
			}
			else if(dynamic_cast<CTriangle*>(original[i]) && triC !=0){
				type = "Triangle";
				i = 1;
				toBeSelected->GetFigureParameters(p1,p2,p3,gfx);
				break;
			}
			else if(dynamic_cast<CLine*>(original[i]) && linC !=0){
				type = "Line";
				 i = 2;
				toBeSelected->GetFigureParameters(p1,p2,p3,gfx);
				break;
			}
			else if(dynamic_cast<CCircle*>(original[i]) && cirC !=0){
				type = "Circle";
				i = 3;
				toBeSelected->GetFigureParameters(p1,p2,p3,gfx);
				break;
			}
		}while(true);
		if(gfx.isFilled == true){
			pManager->GetOutput()->ClearStatusBar();
			pManager->GetOutput()->PrintMessage("Pick a filled "+type+" with this color");
			Point p11,p22;
			p11.x=400;p11.y=675;
			p22.x=425;p22.y=700;
			GfxInfo gfxx;
			gfxx.FillClr = gfxx.DrawClr = gfx.FillClr;
			gfxx.isFilled = true;
			pManager->GetOutput()->DrawRect(p11,p22,gfxx);
			color c(0,0,0);
			pManager->GetOutput()->getWindow()->SetPen(c);
		}
		else{
			pManager->GetOutput()->PrintMessage("Pick a non-filled "+type);
		}
		do{
			pManager->GetInput()->GetPointClicked(p.x,p.y);
			if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 1)
				goto endofPH;
			else if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 0)
				goto restartofPH;
			selected = pManager->GetFigure(original,originalSize,p);
			if(selected != nullptr){
				bool checkRight = false;
				switch(i){
				case 0:
					if(dynamic_cast<CRectangle*>(selected)){
						checkRight = true;
						recC--;
					}
					break;
				case 1:
					if(dynamic_cast<CTriangle*>(selected)){
						checkRight = true;
						triC--;
					}
					break;
				case 2:
					if(dynamic_cast<CLine*>(selected)){
						checkRight = true;
						linC--;
					}
					break;
				case 3:
					if(dynamic_cast<CCircle*>(selected)){
						checkRight = true;
						cirC--;
					}
					break;
				}
				if(checkRight){
					right++;
					if (originalSize == 1){
						*original = nullptr;
						originalSize--;
						break;
					}
					for(int j=0;j<originalSize;j++){
						if (selected->getID() == original[j]->getID()){
							original[j] = original[originalSize-- -1];
							break;
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
	pManager->GetOutput()->ClearStatusBar();
	pManager->GetOutput()->StartPickHideGame();
	pManager->GetOutput()->getWindow()->SetFont(80, NONE, ROMAN, PLAIN);
	pManager->GetOutput()->getWindow()->SetPen(BLACK, 2);
	pManager->GetOutput()->getWindow()->DrawInteger(2 * UI.MenuItemWidth + 100, 10, right);
	pManager->GetOutput()->getWindow()->DrawInteger(4 * UI.MenuItemWidth + 100, 10, wrong);
	pManager->GetOutput()->ClearDrawArea();
	/////////////////////////////////////////////////////////////////////
	pManager->GetOutput()->getWindow()->SetPen(BLACK, 2);
	pManager->GetOutput()->getWindow()->DrawString(100, 360, "Final Grade: ");
	pManager->GetOutput()->getWindow()->DrawInteger(360 + 100, 360, right);
	pManager->GetOutput()->getWindow()->DrawString(100, 440, "From: ");
	pManager->GetOutput()->getWindow()->DrawInteger(270, 440, right + wrong);
	pManager->GetOutput()->getWindow()->DrawString(350, 440, "Clicks");
	double cond = (double)right/((double)right + (double)wrong);
	if(cond > 0.5)
		pManager->GetOutput()->getWindow()->DrawString(100, 520, "You Have WON");
	else 
		pManager->GetOutput()->getWindow()->DrawString(100, 520, "Lost!!, what a shame");
	while (UI.InterfaceMode != MODE_PLAY)
		 {
		pManager->GetInput()->GetPointClicked(p.x, p.y);
		if((p.y < UI.ToolBarHeight) && ((p.x / UI.MenuItemWidth) == 0)){
				 restartofPH:pManager->startPickHide();
				 this->Execute();
		}else if(p.y < UI.ToolBarHeight && p.x / UI.MenuItemWidth == 1){
			endofPH:UI.InterfaceMode = MODE_PLAY;
			UI.BkGrndColor = GREY;
			}
		}

 }

StartPH::~StartPH()
{
}
