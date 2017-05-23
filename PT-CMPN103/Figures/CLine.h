#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure 
{
private:
	Point start;
	Point end;
	double slope;
public:
	CLine(Point, Point, GfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Select(Point);
	virtual void Drag(Point, Point);
	virtual double getArea(double,Point,Point,Point);
	virtual void Move(Point);
	virtual CFigure* Copy();
	virtual string printInfo();
	virtual void getCenter(Point&);
	virtual void GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void Resize(int);
	virtual FigReference ReferFigure(Point P);
	void SetBorder(int n);
	virtual void ResizePoint(Point P, FigReference FigRef);
};

#endif