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
	int zoomcontrol;

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
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
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
	void zoomcontrolsave(int); // to save the original data
	void zoomcontrolinterface() const; // to hide the actions which i don't want it in zoom mode 
	/***************************************************************************/
	//Scramble and find operating functions
	void StartNewScrambleGame();
	void AdjustOriginalList();
	void RandomizeFigures();
	//Pick and Hide operating functions
	void countFigs(int,int,int,int);

	// -- interface management functions

	Input *GetInput() const; //return pointer to the input
	Output *GetOutput() const; //return pointer to the output

	void UpdateDrawing() const; //only redraw fidures no update for toolbars
	void UpdateInterface() const;	//redraws all the drawing window	
};

#endif