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

void CRectangle :: Save(ofstream &OutFile)
{
	OutFile <<"RECTANGLE"<<"\t"<<ID<<"\t"<<Corner1.x<<"\t"<<Corner1.y<<"\t"<<Corner2.x<<"\t"<<Corner2.y <<Save::tostringg(FigGfxInfo.DrawClr)<<"\t";
	if(FigGfxInfo.isFilled){ OutFile << Save::tostringg(FigGfxInfo.FillClr) <<endl;}
     else{OutFile << "NO_FILL" <<endl;}
}
void CRectangle::Load(ifstream &Infile)
  {
			 char Dr[40]; char fill[40];
			 Infile>>ID>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y;
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
	int startx=Corner1.x;int starty=Corner1.y;int endx=Corner2.x;int endy=Corner2.y;
    if(prec==50)
	{  
	 Corner2.x=int (0.14645*startx+0.8535*endx);
	 Corner2.y=int (0.14645*starty+0.8535*endy);
	 Corner1.x=int (0.8535*startx+0.14645*endx);
	 Corner1.y=int (0.8535*starty+0.14645*endy);
	}
	if(prec==25)
	{
		 Corner2.x=int (0.14645*startx+0.8535*endx);
	     Corner2.y=int (0.14645*starty+0.8535*endy);
	     Corner1.x=int (0.8535*startx+0.14645*endx);
	     Corner1.y=int (0.8535*starty+0.14645*endy);
		 int startx=Corner1.x;
		 int starty=Corner1.y;
		 int endx=Corner2.x;
		 int endy=Corner2.y;
		 Corner2.x=int (0.14645*startx+0.8535*endx);
	     Corner2.y=int (0.14645*starty+0.8535*endy);
	     Corner1.x=int (0.8535*startx+0.14645*endx);
	     Corner1.y=int (0.8535*starty+0.14645*endy);
	}
	if(prec==200)
	{
		 if((-0.2071*startx+1.2071067*endx)>=0&&(-0.2071*startx+1.2071067*endx)<=1440)
	     { Corner2.x=int (-0.2071*startx+1.2071067*endx); Corner2.y=int (-0.2071*starty+1.2071067*endy);}
		 else if((-0.2071*startx+1.2071067*endx)<0){Corner2.x=0;}
		 else if((-0.2071*startx+1.2071067*endx)>1440){Corner2.x=1440;}
	     if ((1.2071067*startx+-0.2071*endx)>=0&&(1.2071067*startx+-0.2071*endx)<=1440)
		 { Corner1.x=int (1.2071067*startx+-0.2071*endx);Corner1.y=int (1.2071067*starty+-0.2071*endy);}
		 else if((1.2071067*startx+-0.2071*endx)<0){Corner1.x=0;}
		 else if((1.2071067*startx+-0.2071*endx)){Corner1.x=1440;}

	}
	if(prec==400)
	{
	     if((-0.2071*startx+1.2071067*endx)>=0&&(-0.2071*startx+1.2071067*endx)<=1440)
	     { Corner2.x=int (-0.2071*startx+1.2071067*endx); Corner2.y=int (-0.2071*starty+1.2071067*endy);}
		 else if((-0.2071*startx+1.2071067*endx)<0){Corner2.x=0;}
		 else if((-0.2071*startx+1.2071067*endx)>1440){Corner2.x=1440;}
	     if ((1.2071067*startx+-0.2071*endx)>=0&&(1.2071067*startx+-0.2071*endx)<=1440)
		 { Corner1.x=int (1.2071067*startx+-0.2071*endx);Corner1.y=int (1.2071067*starty+-0.2071*endy);}
		 else if((1.2071067*startx+-0.2071*endx)<0){Corner1.x=0;}
		 else if((1.2071067*startx+-0.2071*endx)){Corner1.x=1440;}
		 int startx=Corner1.x;int starty=Corner1.y;int endx=Corner2.x;int endy=Corner2.y;
		 if((-0.2071*startx+1.2071067*endx)>=0&&(-0.2071*startx+1.2071067*endx)<=1440)
	     { Corner2.x=int (-0.2071*startx+1.2071067*endx); Corner2.y=int (-0.2071*starty+1.2071067*endy);}
		 else if((-0.2071*startx+1.2071067*endx)<0){Corner2.x=0;}
		 else if((-0.2071*startx+1.2071067*endx)>1440){Corner2.x=1440;}
	     if ((1.2071067*startx+-0.2071*endx)>=0&&(1.2071067*startx+-0.2071*endx)<=1440)
		 { Corner1.x=int (1.2071067*startx+-0.2071*endx);Corner1.y=int (1.2071067*starty+-0.2071*endy);}
		 else if((1.2071067*startx+-0.2071*endx)<0){Corner1.x=0;}
		 else if((1.2071067*startx+-0.2071*endx)){Corner1.x=1440;}

	}

	
}
 