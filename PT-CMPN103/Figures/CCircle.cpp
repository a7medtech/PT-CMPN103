#include "CCircle.h"
#include <math.h>
CCircle::CCircle(Point P1, double P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Distance = P2;
}
void CCircle::GetFigureParameters(Point&P1, double&P2, Point&P3, GfxInfo&Gfx)
{
	P3.x = 0; 
	P3.y = 0;
	P1.x = Center.x;
	P1.y = Center.y;
	P2 = Distance;
	Gfx = FigGfxInfo;
}
void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pOut->DrawCircle(Center, Distance, FigGfxInfo, Selected);
}
bool CCircle::Select(Point p){
	Point p1,p2,p3;
	p1 = p2 = p3 = p;
	double rad = sqrt(pow((p.x - Center.x), 2) + pow((p.y - Center.y),2));
	bool temp = false;
	if (getArea(rad, p1, p2, p3) <= getArea(Distance, p1, p2, p3)){
		SetSelected(!Selected);
		temp = true;
	}
	return temp;
}
void CCircle::Drag(Point P2, Point P3)
{
	Distance = sqrt(pow((Center.x - P2.x), 2) + pow((Center.y - P2.y), 2));
	if ((Center.y- Distance/2) < UI.ToolBarHeight)
	{
		Distance  = 2*(Center.y + UI.ToolBarHeight);
	}
	else if ((Center.y - Distance / 2) >(UI.height - UI.StatusBarHeight))
	{
		Distance = 2*(Center.y + UI.height - UI.StatusBarHeight);
	}
}


FigReference CCircle::ReferFigure(Point P)
{
	if (P.x < Center.x + 3 && P.x > Center.x - 3)
		if (P.y < Center.y + 3 && P.y > Center.y - 3)
			return CENTER;
	if (P.x < (Center.x - Distance) + 3 && P.x > (Center.x - Distance) - 3)
		if (P.y < Center.y + 3 && P.y > Center.y - 3)
			return CORNER1;
	if (P.x < Center.x + 3 && P.x > Center.x - 3)
		if (P.y < (Center.y-Distance) + 3 && P.y > (Center.y-Distance) - 3)
			return CORNER2;
	if (P.x < (Center.x + Distance) + 3 && P.x > (Center.x + Distance) - 3)
		if (P.y < Center.y + 3 && P.y > Center.y - 3)
			return CORNER4;
	if (P.x < Center.x + 3 && P.x > Center.x - 3)
		if (P.y <(Center.y + Distance) + 3 && P.y > (Center.y + Distance) - 3)
			return CORNER2;

	return NONEREF;
}

void CCircle::ResizePoint(Point P, FigReference FigRef)
{
	Point P2;
	P2.x = P2.y = 0;
	Drag(P, P2);
}

string CCircle::printInfo(){
	Point p1,p2,p3;
	p1.x = p2.x = p3.x = 0;
	p1.y = p2.y = p3.y = 0;
	string info = string("The Center is ")+to_string(Center.x)+to_string(Center.y)+string(" and its radius is ")+to_string(Distance)+string(" and its area is ")+to_string(getArea(Distance,p1,p2,p3));
	return info;
}

CFigure* CCircle::Copy()
{
	CFigure* CopyCircle = new CCircle(Center, Distance, FigGfxInfo);
	return CopyCircle;
}
double CCircle::getArea(double rad,Point,Point,Point){
	return 4*atan(1)*pow(rad,2);
}
void CCircle::GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx){
	
}

 

void CCircle::Move(Point p)
{
	Center = p;
}
void CCircle::getCenter(Point& c){
	c = Center;
}
void  CCircle::Save(ofstream &OutFile)
{

	OutFile << "CIRCLE" << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << Distance << "\t" << FigGfxInfo.BorderWdth << "\t" <<
		(int)FigGfxInfo.DrawClr.ucBlue << "\t" << (int)FigGfxInfo.DrawClr.ucGreen << "\t" << (int)FigGfxInfo.DrawClr.ucRed << "\t";
	if (FigGfxInfo.isFilled) {
		OutFile << (int)FigGfxInfo.FillClr.ucBlue << "\t" << (int)FigGfxInfo.FillClr.ucGreen
			<< "\t" << (int)FigGfxInfo.FillClr.ucRed << endl;
	}
	else {
		OutFile << (int)UI.BkGrndColor.ucBlue << "\t" << (int)UI.BkGrndColor.ucGreen
			<< "\t" << (int)UI.BkGrndColor.ucRed << endl;
	}

}
void CCircle::Load(ifstream &Infile)
{
	int db, dg, dr, fb, fg, fr; char space[5];

	Infile >> ID >> Center.x >> Center.y >> Distance >> FigGfxInfo.BorderWdth >> db >> dg >> dr >> fb >> fg >> fr;
	FigGfxInfo.DrawClr.ucBlue = (char)db;
	FigGfxInfo.DrawClr.ucGreen = (char)dg;
	FigGfxInfo.DrawClr.ucRed = (char)dr;
	FigGfxInfo.FillClr.ucBlue = (char)fb;
	FigGfxInfo.FillClr.ucGreen = (char)fg;
	FigGfxInfo.FillClr.ucRed = (char)fr;
	if (FigGfxInfo.FillClr == UI.BkGrndColor)
	{
		FigGfxInfo.isFilled = false;
	}
	else { FigGfxInfo.isFilled = true; }
	Infile.getline(space, 5, '\n');
}
void CCircle::Resize(int prec)
{

	if (prec == 25)
	{
		Distance = Distance / 2;
	}
	if (prec == 50)
	{
		Distance = Distance / (sqrt(2));
	}
	if (prec == 200)
	{
		if (((Center.x + Distance*(sqrt(2)))>0) && ((Center.x + Distance*(sqrt(2)))<1440) && ((Center.y - Distance*(sqrt(2)))>85) && ((Center.y + Distance*(sqrt(2)))<670))
		{
			Distance = Distance*(sqrt(2));
		}
	}
	if (prec == 400)
	{
		if (((Center.x + Distance * 2)>0) && ((Center.x + Distance * 2)<1440) && ((Center.y - Distance * 2)>85) && ((Center.y + Distance * 2)<670))
		{
			Distance = Distance * 2;
		}
	}
	if (prec == 15)  //to be used in zoom without validations to draw it clipped
	{
		Distance = Distance*(sqrt(2));
	}
}

void CCircle::SetBorder(int n)
{
	if (this->FigGfxInfo.BorderWdth < 30 && n>0)
		this->FigGfxInfo.BorderWdth += n;
	if (this->FigGfxInfo.BorderWdth>0 && n<0)
		this->FigGfxInfo.BorderWdth += n;
}

	 