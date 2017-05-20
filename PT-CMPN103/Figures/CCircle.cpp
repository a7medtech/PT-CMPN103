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

 
	 void  CCircle::Save(ofstream &OutFile)
 {

	 OutFile <<"CIRCLE"<<"\t"<<ID<<"\t"<<Center.x<<"\t"<<Center.y<<"\t"<<Distance<<Save::tostringg(FigGfxInfo.DrawClr)<<"\t";
     if(FigGfxInfo.isFilled){ OutFile <<Save::tostringg(FigGfxInfo.FillClr) <<endl;}
     else{OutFile << "NO_FILL" <<endl;}

}
	 void CCircle::Load(ifstream &Infile)
	 {
			 char Dr[40]; char fill[40];
			 Infile>>ID>>Center.x>>Center.y>>Distance;
			 Infile.getline(Dr,40,'\t');
			 Infile.getline(fill,40,'\n');
						 string Drs=Dr;string fills=fill;
						 FigGfxInfo.DrawClr=Save::tocolor(Drs);

						 if(fills.compare("NO_FILL")==NULL)
						 { 
						 FigGfxInfo.isFilled=false;
						 FigGfxInfo.FillClr=UI.BkGrndColor;
						 }
						 else 
							 {
								 FigGfxInfo.FillClr=Save::tocolor(fills);
								 FigGfxInfo.isFilled=true;
						 }
  }

void CCircle::Move(Point p)
{
	Center = p;
}
void CCircle::getCenter(Point& c){
	c = Center;
}
void CCircle::Resize(int prec)
{
		if(prec==25)
		{ Distance=Distance/2; }

	if(prec==50)
	{ Distance=Distance/(sqrt(2));  }
	if(prec==200)
	{  Distance=Distance*(sqrt(2)); }
	if(prec==400)
	{ Distance=Distance*2; }
}



	 