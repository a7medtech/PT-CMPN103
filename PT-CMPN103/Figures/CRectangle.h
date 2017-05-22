#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool Select(Point);
	virtual void Drag(Point, Point);
	virtual double getArea(double,Point,Point,Point); //no need for area
	virtual void Move(Point);
	virtual CFigure*Copy();
	virtual string printInfo();
	virtual void getCenter(Point&);
	virtual void GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx);
    virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void Resize(int);
	void SetBorder(int n);
};

#endif