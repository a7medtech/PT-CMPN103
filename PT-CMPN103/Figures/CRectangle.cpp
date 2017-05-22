#include "CRectangle.h"
#include<math.h>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
void CRectangle::GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx)
{
	P3.x = 0; 
	P3.y = 0;
	P1.x = Corner1.x;
	P1.y = Corner1.y;
	P2.x = Corner2.x;
	P2.y = Corner2.y;
	Gfx = FigGfxInfo;
}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::Select(Point p){
	bool x = (p.x > Corner1.x && p.x < Corner2.x) || (p.x < Corner1.x && p.x > Corner2.x);
	bool y = (p.y > Corner1.y && p.y < Corner2.y) || (p.y < Corner1.y && p.y > Corner2.y);
	bool temp = false;
	if(x && y){
		SetSelected(!Selected);
		temp = true;
	}
	return temp;
}
void CRectangle::Drag(Point p, Point f)
{
		Corner2 = p;
}

CFigure* CRectangle::Copy()
{
	CFigure*CopyRect = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return CopyRect;
}

string CRectangle::printInfo(){
	Point p1;
	p1.x = 0;
	p1.y = 0;
	double r = 0;
	string info = string("The First Corner is (")+to_string(Corner1.x)+string(",")+to_string(Corner1.y)+string(") and the second point is (")+to_string(Corner2.x)+string(",")+to_string(Corner2.y)+string(")")+string(" and its area is ")+to_string(getArea(r,Corner1,Corner2,p1));
	return info;
}

double CRectangle::getArea(double,Point,Point,Point){
	return abs(Corner1.x - Corner2.x)*abs(Corner2.y - Corner2.y);
}
void CRectangle::Save(ofstream &OutFile)
{
	OutFile << "RECTANGLE" << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << FigGfxInfo.BorderWdth << "\t" <<
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
void CRectangle::Load(ifstream &Infile)
{
	int db, dg, dr, fb, fg, fr; char space[5];

	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> FigGfxInfo.BorderWdth >> db >> dg >> dr >> fb >> fg >> fr;
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

void CRectangle::getCenter(Point& c){
	c.x = (Corner1.x + Corner2.x)/2;
	c.y = (Corner1.y + Corner2.y)/2;
}

void CRectangle::Move(Point p){
	const int halfHeight = abs(Corner1.y - Corner2.y)/2;
	const int halfWidth = abs(Corner1.x - Corner2.x)/2;
	Corner1.x = p.x -halfWidth;
	Corner1.y = p.y - halfHeight;
	Corner2.x = p.x + halfWidth;
	Corner2.y = p.y + halfHeight;
}


void CRectangle::Resize(int prec)
{
	int startx = Corner1.x; int starty = Corner1.y; int endx = Corner2.x; int endy = Corner2.y;
	if (prec == 50)
	{
		Corner2.x = (0.14645*startx + 0.8535*endx);
		Corner2.y = (0.14645*starty + 0.8535*endy);
		Corner1.x = (0.8535*startx + 0.14645*endx);
		Corner1.y = (0.8535*starty + 0.14645*endy);
	}
	if (prec == 25)
	{
		Corner2.x = (0.14645*startx + 0.8535*endx);
		Corner2.y = (0.14645*starty + 0.8535*endy);
		Corner1.x = (0.8535*startx + 0.14645*endx);
		Corner1.y = (0.8535*starty + 0.14645*endy);
		int startx = Corner1.x; int starty = Corner1.y; int endx = Corner2.x; int endy = Corner2.y;
		Corner2.x = (0.14645*startx + 0.8535*endx);
		Corner2.y = (0.14645*starty + 0.8535*endy);
		Corner1.x = (0.8535*startx + 0.14645*endx);
		Corner1.y = (0.8535*starty + 0.14645*endy);
	}
	if (prec == 200)
	{
		if (((-0.2071*startx + 1.2071067*endx) >= 0) && ((-0.2071*startx + 1.2071067*endx) <= 1440) && ((1.2071067*startx + -0.2071*endx) >= 0) && ((1.2071067*startx + -0.2071*endx) <= 1440))
		{
			if (((-0.2071*starty + 1.2071067*endy) >= 85) && ((-0.2071*starty + 1.2071067*endy) <= 670) && ((1.2071067*starty + -0.2071*endy) >= 85) && ((1.2071067*starty + -0.2071*endy) <= 670))
			{
				Corner2.x = (-0.2071*startx + 1.2071067*endx); Corner2.y = (-0.2071*starty + 1.2071067*endy);
				Corner1.x = (1.2071067*startx + -0.2071*endx); Corner1.y = (1.2071067*starty + -0.2071*endy);
			}
		}
	}
	if (prec == 400)
	{
		if (((-0.2071*startx + 1.2071067*endx) >= 0) && ((-0.2071*startx + 1.2071067*endx) <= 1440) && ((1.2071067*startx + -0.2071*endx) >= 0) && ((1.2071067*startx + -0.2071*endx) <= 1440))
		{
			if (((-0.2071*starty + 1.2071067*endy) >= 85) && ((-0.2071*starty + 1.2071067*endy) <= 670) && ((1.2071067*starty + -0.2071*endy) >= 85) && ((1.2071067*starty + -0.2071*endy) <= 670))
			{
				endx = (-0.2071*startx + 1.2071067*endx); endy = (-0.2071*starty + 1.2071067*endy);
				startx = (1.2071067*startx + -0.2071*endx); starty = (1.2071067*starty + -0.2071*endy);
			}
		}

		if (((-0.2071*startx + 1.2071067*endx) >= 0) && ((-0.2071*startx + 1.2071067*endx) <= 1440) && ((1.2071067*startx + -0.2071*endx) >= 0) && ((1.2071067*startx + -0.2071*endx) <= 1440))
		{
			if (((-0.2071*starty + 1.2071067*endy) >= 85) && ((-0.2071*starty + 1.2071067*endy) <= 670) && ((1.2071067*starty + -0.2071*endy) >= 85) && ((1.2071067*starty + -0.2071*endy) <= 670))
			{
				Corner2.x = (-0.2071*startx + 1.2071067*endx); Corner2.y = (-0.2071*starty + 1.2071067*endy);
				Corner1.x = (1.2071067*startx + -0.2071*endx); Corner1.y = (1.2071067*starty + -0.2071*endy);
			}
		}
	}
}
void CRectangle::SetBorder(int n)
{
	if (this->FigGfxInfo.BorderWdth < 30 && this->FigGfxInfo.BorderWdth>0)
	this->FigGfxInfo.BorderWdth += n;

}