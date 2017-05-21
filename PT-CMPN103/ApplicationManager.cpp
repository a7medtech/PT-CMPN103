#include "ApplicationManager.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddTrianAction.h"
#include "Actions/AddCircleAction.h"
#include "Actions/AddLineAction.h"
#include "Actions/Select.h"
#include"Actions\SaveAction.h"
#include "Actions\Copy.h"
#include"Actions\LoadAction.h"
#include "Actions/Move.h"
#include "Actions/Copy.h"
#include "Actions/BackAction.h"
#include "Actions/BringFront.h"
#include "Actions/Delete.h"
#include "Actions/Paste.h"
#include "Actions/Cut.h"
#include "Actions/ChngBkClr.h"
#include "Actions/ChngDrawClr.h"
#include "Actions/ChngFillClr.h"
#include"Actions\Resize.h"
#include "Actions\SendBack.h"
#include "Actions/ScrambleAndFind.h"
#include "Actions\StartScrumble.h"
#include "Actions\BackPlayAction.h"
#include <time.h>
#include <windows.h>

int ApplicationManager::counter = 0; //Initialize unique IDs

//Constructor
ApplicationManager::ApplicationManager()
{

	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput(pOut);

	FigCount = 0;
	SelFigCount = 0;
	CPIndex = 0;
	OriginalListCount = 0;
	RandFigsCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = nullptr;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
			case DRAW_LINE:
				pAct = new AddLineAction(this);
				break;
			case DRAW_RECT:
				pAct = new AddRectAction(this);
				break;
			case DRAW_TRI:
				pAct=new AddTrianAction(this);
			break;
			case DRAW_CIRC:
				pAct=new AddCircleAction(this);
			break;
			case CHNG_DRAW_CLR:
				pAct = new ChngDrawClr(this);
				break;
			case CHNG_FILL_CLR:
				pAct = new ChngFillClr(this);
				break;
			case CHNG_BK_CLR:
				pAct = new ChngBkClr(this);
				break;
			case ZOOM_IN:
				break;
			case ZOOM_OUT:
				break;
			case SAVE:
				 pAct=new Save(this);
				break;
			case LOAD:
				pAct=new LoadAction(this);
				break;
			case DEL:
				pAct = new Delete(this);
				break;
			case MOVE:
				pAct = new Move(this);
				break;
			case RESIZE:
				pAct=new ResizeAction(this);
				break;
			case ROTATE:
				break;
			case SEND_BACK:
				pAct = new SendBack(this);
				break;
			case BRNG_FRNT:
				pAct = new BringFront(this);
				break;
			case COPY:
				pAct = new Copy(this);
				break;
			case CUT:
				pAct = new Cut(this);
				break;
			case PASTE:
				pAct = new Paste(this);
				break;
			case DRAWING_AREA:
				Point p;
 				button clickT;
 				pOut->getWindow()->GetButtonState(clickT, p.x, p.y);
				pAct = new Select(this,p);
				break;
			case STATUS:
				break;
			case EMPTY:
				break;


				/*PLAY MODE*/

			case PICK_HIDE_MODE:
				break;
			case SCRAMBLE_FIND_MODE:
				pAct = new ScrambleAndFind(this);
				break;
			case START_SCRAMBLE:
				pAct = new StartScrumble(this);
				break;
			case TO_DRAW:
				pAct = new BackAction(this);
				break;
			case BACK:
				pAct = new BackAction(this);
				break;
			case BACKPLAY:
				pAct = new BackPlayAction(this);
				break;
			case EXIT:
				break;
			default:
				break;

	}
	
	//Execute the created action
	if(pAct != nullptr)
	{
		pAct->Execute();	//Execute
		LastAction = ActType;
		delete pAct;		//Action is not needed any more ==> delete it
		pAct = nullptr;
	}
}



//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

void ApplicationManager::Drag(Point P2, Point P3)
{
	if (P2.y < UI.ToolBarHeight + 2)
	{
		P2.y = UI.ToolBarHeight + 2;
	}
	else if (P2.y >(UI.height - UI.StatusBarHeight - 2))
	{
		P2.y = UI.height - UI.StatusBarHeight - 2;
	}
	if (P3.y < UI.ToolBarHeight + 2)
	{
		P3.y = UI.ToolBarHeight + 2;
	}
	else if (P3.y >(UI.height - UI.StatusBarHeight - 2))
	{
		P3.y = UI.height - UI.StatusBarHeight - 2;
	}

	FigList[FigCount-1]->Drag(P2,P3);
}
void ApplicationManager::deleteforload()
{
	int n=0;this->GetFigCount(n);
	for(int i=0;i<n;i++)
	{
		FigList[i]=NULL;
	 this->minusfigcount();
	}
}
void ApplicationManager::minusfigcount()
{ FigCount--; }

void ApplicationManager::SelectFigs(Point p)
{
	bool check;
	for (int i = FigCount-1; i >= 0; i--) {
		check = FigList[i]->Select(p);
		if(check){
			if(FigList[i]->IsSelected())
				displayFigParam(FigList[i]);
			else 
				GetOutput()->ClearStatusBar();
			return;
		}
	}
}

void ApplicationManager:: SaveAction(ofstream&Outfile)
{
    int c;
    GetFigCount(c);
	Outfile<<Save::tostringg(UI.DrawColor)<<"\t"<<Save::tostringg(UI.FillColor)<<"\t"<<Save::tostringg(UI.BkGrndColor)<<endl;
	Outfile<<c<<"\n";
    for(int i=0;i<c;i++)
    {
		FigList[i]->Save(Outfile);
        
    }
	   	pOut->PrintMessage("You Saved to file Succesfully");

}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount++] = pFig;
		pFig->setID(++counter);
	}
}

void ApplicationManager::Resizefigures(int n)
{
	for(int i=0;i<SelFigCount;i++)
	{
		selectedFigs[i]->Resize(n);
	}
}


void ApplicationManager::FindSelFigList(CFigure** &s){
	int i;
	for(i=0; i<MaxFigCount ;i++){
		selectedFigs[i] = nullptr;
	}
	SelFigCount = 0;
	for (i=0; i<FigCount ;i++){
		if (FigList[i]->IsSelected())
			selectedFigs[SelFigCount++] = (FigList[i]);
		
	}
	s = selectedFigs;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	

	return nullptr;
}

void ApplicationManager::displayFigParam(CFigure* s){
	string b = string("you have selected ")+to_string(SelFigCount+1)+string(" figures");
	if(SelFigCount+1 > 1){
		GetOutput()->PrintMessage(b);
	}else{
		GetOutput()->PrintMessage(s->printInfo());
	}
}

CFigure* ApplicationManager::getFigureById(int id,int& index){
	int size;
	GetFigCount(size);
	for (int i=0;i<size;i++){
		if (FigList[i]->getID() == id ){
			index = i;
			return FigList[i];
		}
	}
	return nullptr;
}

void ApplicationManager::GetFigCount(int&size)
{
	size = FigCount;
}

void ApplicationManager::GetSelectedFigCount(int&size){
	size = SelFigCount;
}

void ApplicationManager::GetCPIndex(int&size)
{

	size = CPIndex;
}

//Remember to remove get figure list!!!

void ApplicationManager::CopySelFigToCP()
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->SetSelected(false);
	for (int i = 0; i < MaxFigCount; i++)
		Clipboard[i] = nullptr;
	CPIndex = 0;
	for (int i = 0; i < SelFigCount; i++)
	{
		Clipboard[CPIndex] = selectedFigs[i]->Copy();
		Clipboard[CPIndex++]->setID(i);
		
	}
}


void ApplicationManager::AddCPToFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
		if (LastAction == CUT)
		{

			for (int i = 0; i < CPIndex; i++)
			{
				Clipboard[i]->SetSelected(true);
				AddFigure(Clipboard[i]->Copy());
				FigList[FigCount - 1]->setID(++counter);
				FigList[FigCount - 1]->SetSelected(Clipboard[i]->IsSelected());

			}
			for (int i = 0; i < CPIndex; i++)
			{
				delete Clipboard[i];
				Clipboard[i] = nullptr;
			}
			CPIndex = 0;
	}
	else
	{

		for (int i = 0; i < CPIndex; i++)
		{
			Clipboard[i]->SetSelected(true);
			AddFigure(Clipboard[i]->Copy());
			FigList[FigCount - 1]->setID(++counter);
			FigList[FigCount - 1]->SetSelected(Clipboard[i]->IsSelected());
			

		}
	}
}


void ApplicationManager::CutSelFigToCP()
{
	for (int i = 0; i < MaxFigCount; i++)
		Clipboard[i] = nullptr;
	CPIndex = 0;
	for (int i = 0; i < SelFigCount; i++)
	{
		Clipboard[CPIndex] = selectedFigs[i]->Copy();
		Clipboard[CPIndex++]->setID(FigCount - SelFigCount + 1 + i);

	}
	this->deleteSelected();
	SelFigCount = 0;
}

void ApplicationManager::deleteSelected() {
	CFigure** s;
	CFigure* temp;
	int index;
	FindSelFigList(s);

	for (int i = 0; i<SelFigCount; i++) {
		temp = getFigureById(selectedFigs[i]->getID(), index);
		FigList[index] = FigList[(FigCount--) - 1];
	}
	for (int i = 0; i<MaxFigCount; i++) {
		selectedFigs[i] = nullptr;
	}
}

void ApplicationManager::cleanFigList(){
	for(int i=0;i<FigCount;i++){
		if (FigList[i] == nullptr){
			while(FigList[i+1]){
				FigList[i] = FigList[i++]; 
			}
			return;
		}
	}
}

void ApplicationManager::BringtoFront() 
{
	int size, j = 0;
	GetSelectedFigCount(size);
	CFigure** sel;
	FindSelFigList(sel);
	for (int i = 0; i < size; i++)
	{
		j = sel[i]->getID();
		while (j < FigCount)
		{
			FigList[j - 1]->setID(j + 1);
			FigList[j]->setID(j);
			CFigure*temp;
			temp = FigList[j - 1];
			FigList[j - 1] = FigList[j];
			FigList[j] = temp;
			j++;
		}
	}
}

void ApplicationManager::SendToBack()
{
	int size, j = 0;
	GetSelectedFigCount(size);
	CFigure** sel;
	FindSelFigList(sel);
	for (int i = 0; i < size; i++)
	{
		j = sel[i]->getID();
		while (j > 1)
		{
			FigList[j - 1]->setID(j - 1);
			FigList[j - 2]->setID(j);
			CFigure*temp;
			temp = FigList[j - 1];
			FigList[j - 1] = FigList[j - 2];
			FigList[j - 2] = temp;
			j--;
		}
	}
}

//==================================================================================//
//							Play Mode Functions						            	//
//==================================================================================//




//Scramble and find mode

void ApplicationManager::StartNewScrambleGame()
{
	pOut->StartScrambleGame();
	Point P;
	P.x = 700;
	P.y = 700;
	int i = 0;
	while (P.x % UI.MenuItemWidth != 1 && P.y > UI.ToolBarHeight)
	{
		OriginalList[i]->SetSelected(true);
		pOut->ClearDrawArea();
		for (int i = 0; i < OriginalListCount; i++)
		{
			OriginalList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
			RandomizedFigures[i]->Draw(pOut);
		}
		pIn->GetPointClicked(P.x, P.y);
		for (int j = 0; j < RandFigsCount; j++)
		{
			if (RandomizedFigures[j]->Select(P))
			{
				if (RandomizedFigures[i]->getID() == OriginalList[i]->getID())
				{
					CFigure* temp;
					int index1, index2;
					for (int k = 0; k<RandFigsCount; k++) {
						temp = getFigureById(OriginalList[k]->getID(), index1);
						OriginalList[index1] = OriginalList[(FigCount--) - 1];
						/*///////////////////////////////////////////////////*/
						temp = getFigureById(RandomizedFigures[k]->getID(), index2);
						OriginalList[index2] = OriginalList[(FigCount--) - 1];
					}
				}
			}
			i++;
		}

	}

}


void ApplicationManager::AdjustOriginalList()
{
	Point T;
	int x = 0;
	for (int i = 0; i < MaxFigCount; i++)
		OriginalList[i] = nullptr;
	OriginalListCount = 0;

	for (int i = 0; i < FigCount; i++)
	{
		OriginalList[OriginalListCount] = FigList[i]->Copy();
		OriginalList[OriginalListCount++]->setID(++counter);

	}
	for (int i = 0; i < OriginalListCount; i++)
	{
		OriginalList[i]->getCenter(T);
		x += T.x;
	}
	if (FigCount != 0)
		x = (x / FigCount) / 2;
	for (int i = 0; i < FigCount; i++)
	{
		OriginalList[i]->getCenter(T);
		T.x -= x / 2;
		OriginalList[i]->Move(T);
		OriginalList[i]->Resize(50);
	}

}

void random(int&Px, int&Py)
{
	int x = UI.width;
	int y = UI.height;
	Px = (rand() % x + 1);
	if (Px < UI.width / 2)
		Px += UI.width / 2;
	Py = (rand() % y + 1);
	if (Py <= UI.ToolBarHeight)
		Py += UI.ToolBarHeight;
}

void ApplicationManager::RandomizeFigures()
{
	Point P;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < MaxFigCount; i++)
		RandomizedFigures[i] = nullptr;
	RandFigsCount = 0;
	for (int i = 0; i < OriginalListCount; i++)
	{
		RandomizedFigures[RandFigsCount] = OriginalList[i]->Copy();
		RandomizedFigures[RandFigsCount++]->setID(OriginalList[i]->getID());
	}

	for (int i = 0; i < RandFigsCount; i++)
	{
		random(P.x, P.y);
		Sleep(20);
		RandomizedFigures[i]->Move(P);
	}
}







//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//



//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
		pOut->ClearDrawArea();
		for (int i = 0; i < FigCount; i++)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	
	switch (UI.InterfaceMode)
	{
	case MODE_DRAW_MAIN: pOut->CreateMainToolBar();
		break;
	case MODE_DRAW_DRAW: pOut->CreateDrawMenuToolBar();
		break;
	case MODE_DRAW_EDIT: pOut->CreateEditToolBar();
		break;
	case MODE_PLAY: pOut->CreatePlayToolBar();
		break;
	case MODE_PLAY_PICK_HIDE:
		break;
	case MODE_PLAY_SCRAMBLE_FIND: pOut->ScrambleAndFindMain();
		break;
	default:
		break;
	}
	pOut->ClearStatusBar();
}////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
