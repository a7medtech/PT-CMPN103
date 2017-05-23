#include "CLine.h"
#include <math.h>
CLine::CLine(Point P1, Point P2,GfxInfo FigureGFXInfo):CFigure(FigureGFXInfo)
{
	start = P1;
	end = P2;
}

void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(start, end, FigGfxInfo, Selected);
}

void CLine::GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&GFX)
{
	P1.x = start.x;
	P1.y = start.y;
	P2.x = end.x;
	P2.y = end.y;
	P3.x = 0;
	P3.y = 0;  //As line consists of only 2 points
	GFX = FigGfxInfo;
}
double CLine::getArea(double,Point,Point,Point){
	return sqrt(pow(end.y - start.y,2)+pow(end.x - start.x,2));
}
bool CLine::Select(Point p){
	this->slope = ((double)(start.y - end.y)/ (double)(start.x - end.x));
	double slope2 = ((double)(start.y - p.y)/ (double)(start.x - p.x));
	bool temp = false;
	if (start.x == end.x && p.x == start.x){
		SetSelected(!Selected);
		temp = true;
	}else if(start.y == end.y && p.y == start.y){
		SetSelected(!Selected);
		temp = true;
	}else if(((slope<=slope2) && (slope>(slope2-0.05))) || (slope2 <= slope && (slope2>(slope - 0.05)))){
		SetSelected(!Selected);
		temp = true;
	}
	return temp;
}

void CLine::Drag(Point P2, Point P3)
{
		end = P2;
}

FigReference CLine::ReferFigure(Point P)
{
	Point temp;
	getCenter(temp);
	if (P.x < temp.x + 3 && P.x > temp.x - 3)
		if (P.y < temp.y + 3 && P.y > temp.y - 3)
			return CENTER;
	if (P.x < start.x + 3 && P.x > start.x - 3)
		if (P.y < start.y + 3 && P.y > start.y - 3)
			return CORNER1;
	if (P.x < end.x + 3 && P.x > end.x - 3)
		if (P.y < end.y + 3 && P.y > end.y - 3)
			return CORNER2;
	return NONEREF;


}

void CLine::ResizePoint(Point P, FigReference FigRef)
{
	switch (FigRef)
	{
	case CORNER1: start = P;
		break;
	case CORNER2: end = P;
		break;
	}
}

void CLine::Save(ofstream &OutFile)
{

	OutFile << "LINE" << "\t" << ID << "\t" << start.x << "\t" << start.y << "\t" << end.x << "\t" << end.y << "\t" << FigGfxInfo.BorderWdth
		<< "\t" << (int)FigGfxInfo.DrawClr.ucBlue << "\t" << (int)FigGfxInfo.DrawClr.ucGreen << "\t" << (int)FigGfxInfo.DrawClr.ucRed << endl;

}

void CLine::Load(ifstream &Infile)
{
	int db, dg, dr; char space[5];
	Infile >> ID >> start.x >> start.y >> end.x >> end.y >> FigGfxInfo.BorderWdth >> db >> dg >> dr;
	FigGfxInfo.DrawClr.ucBlue = (char)db;
	FigGfxInfo.DrawClr.ucGreen = (char)dg;
	FigGfxInfo.DrawClr.ucRed = (char)dr;
	Infile.getline(space, 5, '\n');
	FigGfxInfo.isFilled = false;
}

string CLine::printInfo()
{
	Point p1,p2,p3;
	p1.x = p2.x = p3.x = 0;
	p1.y = p2.y = p3.y = 0;
	double r = 0;
	string info = string("The start point coordinates are (")+to_string(start.x)+string(",")+to_string(start.y)+string(") and the end point coordinates are (")+to_string(end.x)+string(",")+to_string(end.y)+string(")")+string(" and its length is ")+to_string(getArea(r,p1,p2,p3));
	return info;
}

CFigure* CLine::Copy()
{
	CFigure*LineCopy = new CLine(start, end, FigGfxInfo);
	return LineCopy;
}
void CLine::getCenter(Point& mid){
	mid.x = abs(start.x + end.x) /2;
	mid.y = abs(start.y + end.y) /2;
}
void CLine::Move(Point p){
	Point mid;
	mid.x = abs(start.x - end.x) /2;
	mid.y = abs(start.y - end.y) /2;
	if (start.x <= end.x && start.y <= end.y){
		end.x = p.x + mid.x;
		end.y = p.y + mid.y;
		start.x = p.x - mid.x;
		start.y = p.y - mid.y;
	}else if(start.x >= end.x && start.y <= end.y){
		end.x = p.x - mid.x;
		end.y = p.y + mid.y;
		start.x = p.x + mid.x;
		start.y = p.y - mid.y;
	}else if(start.x <= end.x && start.y >= end.y){
		end.x = p.x + mid.x;
		end.y = p.y - mid.y;
		start.x = p.x - mid.x;
		start.y = p.y + mid.y;
	}else {
		end.x = p.x - mid.x;
		end.y = p.y - mid.y;
		start.x = p.x + mid.x;
		start.y = p.y + mid.y;
	}
}

void CLine::Resize(int prec)
{
	int startx = start.x; int starty = start.y; int endx = end.x; int endy = end.y;
	if (prec == 50)
	{
		end.x = (0.25*(startx)+0.75*endx);
		end.y = (0.25*(starty)+0.75*endy);
		start.x = (0.75*(startx)+0.25*endx);
		start.y = (0.75*(starty)+0.25*endy);
	}
	if (prec == 25)
	{
		end.x = (0.25*(startx)+0.75*endx);
		end.y = (0.25*(starty)+0.75*endy);
		start.x = (0.75*(startx)+0.25*endx);
		start.y = (0.75*(starty)+0.25*endy);
		int startx = start.x; int starty = start.y; int endx = end.x; int endy = end.y;
		end.x = (0.25*(startx)+0.75*endx);
		end.y = (0.25*(starty)+0.75*endy);
		start.x = (0.75*(startx)+0.25*endx);
		start.y = (0.75*(starty)+0.25*endy);
	}
	if (prec == 200)
	{

		if ((((-0.5)*(startx)+(1.5)*endx) >= 0) && (((-0.5)*(startx)+(1.5)*endx) <= 1440) && (((-0.5)*(starty)+(1.5)*endy) >= 85) && (((-0.5)*(starty)+(1.5)*endy) <= 670))
		{
			end.x = ((-0.5)*(startx)+(1.5)*endx);
			end.y = ((-0.5)*(starty)+(1.5)*endy);
			start.x = ((1.5)*(startx)-0.5*endx);
			start.y = ((1.5)*(starty)-0.5*endy);
		}

	}
	if (prec == 400)
	{
		if ((((-0.5)*(startx)+(1.5)*endx) >= 0) && (((-0.5)*(startx)+(1.5)*endx) <= 1440) && (((-0.5)*(starty)+(1.5)*endy) >= 85) && (((-0.5)*(starty)+(1.5)*endy) <= 670))
		{
			endx = ((-0.5)*(startx)+(1.5)*endx);
			endy = ((-0.5)*(starty)+(1.5)*endy);
			startx = ((1.5)*(startx)-0.5*endx);
			starty = ((1.5)*(starty)-0.5*endy);
		}
		if ((((-0.5)*(startx)+(1.5)*endx) >= 0) && (((-0.5)*(startx)+(1.5)*endx) <= 1440) && (((-0.5)*(starty)+(1.5)*endy) >= 85) && (((-0.5)*(starty)+(1.5)*endy) <= 670))
		{
			end.x = ((-0.5)*(startx)+(1.5)*endx);
			end.y = ((-0.5)*(starty)+(1.5)*endy);
			start.x = ((1.5)*(startx)-0.5*endx);
			start.y = ((1.5)*(starty)-0.5*endy);
		}
	}
}

void CLine::SetBorder(int n)
{
	if (this->FigGfxInfo.BorderWdth < 30 && this->FigGfxInfo.BorderWdth>0)
	this->FigGfxInfo.BorderWdth += n;
}
