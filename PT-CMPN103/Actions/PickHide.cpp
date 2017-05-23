#include "PickHide.h"


PickHide::PickHide(ApplicationManager* pApp)
	:Action(pApp){
}

void PickHide::ReadActionParameters(){
}

void PickHide::Execute(){
	pManager->startPickHide();
}

PickHide::~PickHide(){

}