#ifndef _APPLICATION_MANAGER_H
#define _APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures/CFigure.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

class CFigure;
//Main class that manages everything in the application.
class ApplicationManager
{
public:
	enum { MaxFigCount = 200 };	//Max no of figures
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	mqueue MouseClicks;
	CFigure* selectedFigs[MaxFigCount]; //List of selected figures only.     {4EGYZOMBIE} 
	CFigure* Clipboard[MaxFigCount];
	int SelFigCount;
	//deque<Action*> ClipBoard[MaxFigCount];  //Program ClipBoard memory.
	int CPIndex;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void Drag(Point, Point); //Changes the second point of a figure
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void deleteforload();
	void GetFigCount(int&size);
	void GetSelectedFigCount(int&size);
	CFigure** FindSelFigList();
	void SelectFig(Point);
	void SaveAction(ofstream&Outfile);
	void minusfigcount();
	void FindSelFigList(CFigure**&);
	void CopySelFigToCP();
	void CutSelFigToCP();
	void AddCPToFigList();
	void displayFigParam(CFigure*);
	void deleteSelected();
	CFigure* getFigureById(int,int&);
	void SelectFigs(Point);
	void cleanFigList();
	void BringtoFront();
	void Resizefigures(int);
	void SendToBack();
	//void AddSelFiguresToCP();


	// -- interface management functions

	Input *GetInput() const; //return pointer to the input
	Output *GetOutput() const; //return pointer to the output
	void UpdateInterface() const;	//redraws all the drawing window	
};

#endif