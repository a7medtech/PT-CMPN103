#pragma once
#include "CFigure.h"
#include "../DEFS.h"
#include "../ApplicationManager.h"
class CCircle :
	public CFigure
{

private:
	Point Center;
	double Distance;
public:
	CCircle(Point , double, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx);
	virtual void GetFigureParameters(Point&P1, double&P2, Point&P3, GfxInfo&Gfx);
	double getRadius();
	virtual bool Select(Point);
	virtual void Drag(Point, Point);
	virtual CFigure*Copy();
	virtual string printInfo();
	virtual void getCenter(Point&);
	virtual double getArea(double,Point,Point,Point);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile) ;
	virtual void Resize(int);
	virtual void Move(Point);
	virtual FigReference ReferFigure(Point P);
	void SetBorder(int n);
	virtual void ResizePoint(Point P, FigReference FigRef);
};

