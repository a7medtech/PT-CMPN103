 #include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


	
void CTriangle::GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx)
{
	P3.x = Corner3.x; 
	P3.y = Corner3.y;
	P1.x = Corner1.x;
	P1.y = Corner1.y;
	P2.x = Corner2.x;
	P2.y = Corner2.y;
	Gfx = FigGfxInfo;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a triangle on the screen	
	pOut->DrawTRI(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTriangle::Select(Point p){
	double s = 0;
	double area1 = getArea(s,p,Corner1,Corner2);
	double area2 = getArea(s,p,Corner1,Corner3);
	double area3 = getArea(s,p,Corner3,Corner2);
	double area = getArea(s,Corner1,Corner2,Corner3);
	bool temp = false;
	if(area == (area1+area2+area3)){
		temp = true;
		SetSelected(!Selected);
	}
	return temp;
}

void CTriangle::Drag(Point p2, Point p3)
{

	if (Corner1 == p3)
	{
		Corner2 = p2;
		Corner3 = p3;
	}
	else
	{
		Corner2 = p2;
		Corner3 = p3;
	}
}

FigReference CTriangle::ReferFigure(Point P)
{
	Point temp;
	getCenter(temp);
	if (P.x < temp.x + 5 && P.x > temp.x - 5)
		if (P.y < temp.y + 5 && P.y > temp.y - 5)
			return CENTER;
	if (P.x < Corner1.x + 5 && P.x > Corner1.x - 5)
		if (P.y < Corner1.y + 5 && P.y >  Corner1.y - 5)
			return CORNER1;
	if (P.x < Corner2.x + 5 && P.x > Corner2.x - 5)
		if (P.y < Corner2.y + 5 && P.y > Corner2.y - 5)
			return CORNER2;
	if (P.x < Corner3.x + 5 && P.x > Corner3.x - 5)
		if (P.y < Corner3.y + 5 && P.y > Corner3.y - 5)
			return CORNER3;

	return NONEREF;
}

void CTriangle::ResizePoint(Point P, FigReference FigRef)
{
	switch (FigRef)
	{
	case CORNER1:
		Corner1 = P;
		break;
	case CORNER2:
		Corner2 = P;
		break;
	case CORNER3:
		Corner3 = P;
		break;
	case NONEREF:
		break;
	}
}

CFigure* CTriangle::Copy()
{
	CFigure* CopyTriangle = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
	return CopyTriangle;
}

string CTriangle::printInfo(){
	double r = 0;
	string info = string("The First Point is (")+to_string(Corner1.x)+string(",")+to_string(Corner1.y)+string(") and the Second Point is (")+to_string(Corner2.x)+string(",")+to_string(Corner2.y)+string(") and the Third Point is (")+to_string(Corner3.x)+string(",")+to_string(Corner3.y)+string(")")+string(" and its area is ")+to_string(getArea(r,Corner1,Corner2,Corner3));
	return info;
}

double CTriangle::getArea(double,Point p1,Point p2,Point p3){
	return abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y))/2.0);
}

void CTriangle::Save(ofstream &OutFile)
{
	OutFile << "TRIANGLE" << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t"
		<< Corner3.x << "\t" << Corner3.y << "\t" << FigGfxInfo.BorderWdth << "\t" <<
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
void CTriangle::Load(ifstream &Infile)
{
	int db, dg, dr, fb, fg, fr; char space[5];

	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> FigGfxInfo.BorderWdth >> db >> dg >> dr >> fb >> fg >> fr;
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


void CTriangle::getCenter(Point& c){
	c.x = (Corner1.x + Corner2.x + Corner3.x)/3;
	c.y = (Corner1.y + Corner2.y + Corner3.y)/3;
}

void CTriangle::Move(Point p){

			Point mid;
			getCenter(mid);
			Corner1.x = p.x + (Corner1.x - mid.x);
			Corner2.x = p.x + (Corner2.x - mid.x);
			Corner3.x = p.x + (Corner3.x - mid.x);
			Corner1.y = p.y + (Corner1.y - mid.y);
			Corner2.y = p.y + (Corner2.y - mid.y);
			Corner3.y = p.y + (Corner3.y - mid.y);
}

void CTriangle::Resize(int prec)
{
	//New = (1-t)*(Moved) + t*(Reference)
	Point center;
	this->getCenter(center);
	if (prec == 50)
	{
		Corner1.x = (0.7071067812)*Corner1.x + (0.2928932188)*center.x;
		Corner1.y = (0.7071067812)*Corner1.y + (0.2928932188)*center.y;
		Corner2.x = (0.7071067812)*Corner2.x + (0.2928932188)*center.x;
		Corner2.y = (0.7071067812)*Corner2.y + (0.2928932188)*center.y;
		Corner3.x = (0.7071067812)*Corner3.x + (0.2928932188)*center.x;
		Corner3.y = (0.7071067812)*Corner3.y + (0.2928932188)*center.y;

	}
	if (prec == 25)
	{
		Corner1.x = (0.7071067812)*Corner1.x + (0.2928932188)*center.x;
		Corner1.y = (0.7071067812)*Corner1.y + (0.2928932188)*center.y;
		Corner2.x = (0.7071067812)*Corner2.x + (0.2928932188)*center.x;
		Corner2.y = (0.7071067812)*Corner2.y + (0.2928932188)*center.y;
		Corner3.x = (0.7071067812)*Corner3.x + (0.2928932188)*center.x;
		Corner3.y = (0.7071067812)*Corner3.y + (0.2928932188)*center.y;
		Corner1.x = (0.7071067812)*Corner1.x + (0.2928932188)*center.x;
		Corner1.y = (0.7071067812)*Corner1.y + (0.2928932188)*center.y;
		Corner2.x = (0.7071067812)*Corner2.x + (0.2928932188)*center.x;
		Corner2.y = (0.7071067812)*Corner2.y + (0.2928932188)*center.y;
		Corner3.x = (0.7071067812)*Corner3.x + (0.2928932188)*center.x;
		Corner3.y = (0.7071067812)*Corner3.y + (0.2928932188)*center.y;
	}
	if (prec == 200)
	{
		if (((1.4142135624)*Corner1.x + (-0.4142135624)*center.x)>0 && ((1.4142135624)*Corner1.y + (-0.4142135624)*center.y)>85 && ((1.4142135624)*Corner2.x + (-0.4142135624)*center.x)>0 && ((2)*Corner2.y + (-0.4142135624)*center.y)>85 && ((1.4142135624)*Corner3.x + (-0.4142135624)*center.x)>0 && ((1.4142135624)*Corner3.y + (-0.4142135624)*center.y)>85)
		{
			if (((1.4142135624)*Corner1.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*Corner1.y + (-0.4142135624)*center.y)<670 && ((1.4142135624)*Corner2.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*Corner2.y + (-0.4142135624)*center.y)<670 && ((1.4142135624)*Corner3.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*Corner3.y + (-0.4142135624)*center.y)<670)
			{
				Corner1.x = (1.4142135624)*Corner1.x + (-0.4142135624)*center.x;
				Corner1.y = (1.4142135624)*Corner1.y + (-0.4142135624)*center.y;
				Corner2.x = (1.4142135624)*Corner2.x + (-0.4142135624)*center.x;
				Corner2.y = (1.4142135624)*Corner2.y + (-0.4142135624)*center.y;
				Corner3.x = (1.4142135624)*Corner3.x + (-0.4142135624)*center.x;
				Corner3.y = (1.4142135624)*Corner3.y + (-0.4142135624)*center.y;
			}
		}
	}
	if (prec == 400)
	{
		Point c1 = Corner1; Point c2 = Corner2; Point c3 = Corner3;
		if (((1.4142135624)*Corner1.x + (-0.4142135624)*center.x)>0 && ((1.4142135624)*Corner1.y + (-0.4142135624)*center.y)>85 && ((1.4142135624)*Corner2.x + (-0.4142135624)*center.x)>0 && ((2)*Corner2.y + (-0.4142135624)*center.y)>85 && ((1.4142135624)*Corner3.x + (-0.4142135624)*center.x)>0 && ((1.4142135624)*Corner3.y + (-0.4142135624)*center.y)>85)
		{
			if (((1.4142135624)*Corner1.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*Corner1.y + (-0.4142135624)*center.y)<670 && ((1.4142135624)*Corner2.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*Corner2.y + (-0.4142135624)*center.y)<670 && ((1.4142135624)*Corner3.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*Corner3.y + (-0.4142135624)*center.y)<670)
			{
				c1.x = (1.4142135624)*Corner1.x + (-0.4142135624)*center.x;
				c1.y = (1.4142135624)*Corner1.y + (-0.4142135624)*center.y;
				c2.x = (1.4142135624)*Corner2.x + (-0.4142135624)*center.x;
				c2.y = (1.4142135624)*Corner2.y + (-0.4142135624)*center.y;
				c3.x = (1.4142135624)*Corner3.x + (-0.4142135624)*center.x;
				c3.y = (1.4142135624)*Corner3.y + (-0.4142135624)*center.y;
			}
		}
		if (((1.4142135624)*c1.x + (-0.4142135624)*center.x)>0 && ((1.4142135624)*c1.y + (-0.4142135624)*center.y)>85 && ((1.4142135624)*c2.x + (-0.4142135624)*center.x)>0 && ((2)*c2.y + (-0.4142135624)*center.y)>85 && ((1.4142135624)*c3.x + (-0.4142135624)*center.x)>0 && ((1.4142135624)*c3.y + (-0.4142135624)*center.y)>85)
		{
			if (((1.4142135624)*c1.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*c1.y + (-0.4142135624)*center.y)<670 && ((1.4142135624)*c2.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*c2.y + (-0.4142135624)*center.y)<670 && ((1.4142135624)*c3.x + (-0.4142135624)*center.x)<1440 && ((1.4142135624)*c3.y + (-0.4142135624)*center.y)<670)
			{
				Corner1.x = (1.4142135624)*c1.x + (-0.4142135624)*center.x;
				Corner1.y = (1.4142135624)*c1.y + (-0.4142135624)*center.y;
				Corner2.x = (1.4142135624)*c2.x + (-0.4142135624)*center.x;
				Corner2.y = (1.4142135624)*c2.y + (-0.4142135624)*center.y;
				Corner3.x = (1.4142135624)*c3.x + (-0.4142135624)*center.x;
				Corner3.y = (1.4142135624)*c3.y + (-0.4142135624)*center.y;
			}
		}
	}
	if (prec == 15) //to be used in zoom without validations to draw it clipped
	{
		Corner1.x = (1.4142135624)*Corner1.x + (-0.4142135624)*center.x;
		Corner1.y = (1.4142135624)*Corner1.y + (-0.4142135624)*center.y;
		Corner2.x = (1.4142135624)*Corner2.x + (-0.4142135624)*center.x;
		Corner2.y = (1.4142135624)*Corner2.y + (-0.4142135624)*center.y;
		Corner3.x = (1.4142135624)*Corner3.x + (-0.4142135624)*center.x;
		Corner3.y = (1.4142135624)*Corner3.y + (-0.4142135624)*center.y;

	}
}

void CTriangle::SetBorder(int n)
{
	if (this->FigGfxInfo.BorderWdth < 30 && n>0)
	this->FigGfxInfo.BorderWdth += n;
	if (this->FigGfxInfo.BorderWdth>0 && n<0)
		this->FigGfxInfo.BorderWdth += n;
}




