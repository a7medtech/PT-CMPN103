#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\DEFS.h"
#include "..\GUI\Output.h"
#include <fstream>
#include "../Actions/SaveAction.h"
#include "../ApplicationManager.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.
	
public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void setID(int id);
	int getID();
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx) = 0;
	virtual void SetBorder(int) = 0;
	static bool isFill; //to change the default status of isFilled to true
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual bool Select(Point) = 0;
	virtual void Move(Point) = 0;
	virtual double getArea(double,Point,Point,Point) = 0;
	virtual void getCenter(Point&) = 0;
	virtual string printInfo() = 0;
	virtual void Drag(Point, Point) = 0;            //Changes the second point in a figure to apply draging.
	virtual CFigure*Copy() = 0; //creates a copy from the current figure and returns it.
	
	//virtual void Rotate() = 0;	//Rotate the figure
	virtual void Resize(int ) = 0;	//Resize the figure
	virtual FigReference ReferFigure(Point P) = 0;
	virtual void ResizePoint(Point P, FigReference FigRef) = 0;

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	//virtual void PrintInfo(Output* pOut) = 0;	print all figure info on the status bar
};
#endif