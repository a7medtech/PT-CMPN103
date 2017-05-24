#include "Delete.h"



Delete::Delete(ApplicationManager* pApp)
	:Action(pApp) {
}

void Delete::ReadActionParameters(){
}
void Delete::Execute(){
	pManager->deleteSelected();
}
Delete::~Delete()
{
}
