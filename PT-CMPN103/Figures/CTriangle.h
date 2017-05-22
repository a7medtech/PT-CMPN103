#pragma once
#include "CFigure.h"
class CTriangle :
	public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Select(Point);
	virtual void Drag(Point, Point);
	virtual CFigure* Copy();
	virtual double getArea(double,Point,Point,Point);
	virtual string printInfo();
	virtual void Move(Point);
	virtual void getCenter(Point&);
	virtual void GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx);
    virtual void Save(ofstream &OutFile);
    virtual void Load(ifstream &Infile);
    virtual void Resize(int);
	void SetBorder(int n);

};

