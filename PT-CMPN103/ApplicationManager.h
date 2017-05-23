#ifndef _APPLICATION_MANAGER_H
#define _APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures/CFigure.h"
#include "Figures\CCircle.h"
#include "Figures\CLine.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

class CFigure;
//Main class that manages everything in the application.
class ApplicationManager
{
public:
	enum { MaxFigCount = 200 };	//Max no of figures
private:
	static int counter;    //To give any new figure a unique ID
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	mqueue MouseClicks;
	CFigure* selectedFigs[MaxFigCount]; //List of selected figures only.     {4EGYZOMBIE} 
	CFigure* Clipboard[MaxFigCount];
	int SelFigCount;
	int CPIndex;
	int LastAction;
	Point CenterDrawing;

	/****************************************************************************************/
	//Scramble and find data structure.
	CFigure* OriginalList[MaxFigCount];
	CFigure* RandomizedFigures[MaxFigCount];
	int OriginalListCount;
	int RandFigsCount;


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
	void deleteforload();
	void GetFigCount(int&size);
	void GetSelectedFigCount(int&size);
	void GetCPIndex(int&size);
	void SaveAction(ofstream&Outfile);
	void minusfigcount();
	void FindSelFigList(CFigure**&);
	void ReferenceActionToClick(Point P);
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
	void chngeborder(int);
	void zoomin();
	void zoomout();
	void exit(string);
	/***************************************************************************/
	//Scramble and find operating functions
	void StartNewScrambleGame();
	void AdjustOriginalList();
	void RandomizeFigures();
	//Pick and Hide operating functions
	void startPickHide() ;
	CFigure** getFigList(int) ;
	void UpdateInterfacePH(CFigure**,int) ;
	CFigure* GetFigure(CFigure**,int,Point) const; //Search for a figure given a point inside the figure
	// -- interface management functions

	Input *GetInput() const; //return pointer to the input
	Output *GetOutput() const; //return pointer to the output
	void UpdateInterface() const;	//redraws all the drawing window	
};

#endif