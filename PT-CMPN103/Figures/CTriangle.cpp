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

void CTriangle:: Save(ofstream &OutFile) 
{
    OutFile <<"TRIANGLE"<<"\t"<<ID<<"\t"<<Corner1.x<<"\t"<<Corner1.y<<"\t"<<Corner2.x<<"\t"<<Corner2.y<<"\t" 
        <<Corner3.x<<"\t"<<Corner3.y
		<<Save::tostringg(FigGfxInfo.DrawClr)<<"\t";
	if(FigGfxInfo.isFilled){ OutFile << Save::tostringg(FigGfxInfo.FillClr)<<endl;}
     else{OutFile << "NO_FILL" <<endl;}

}
  void CTriangle ::Load(ifstream &Infile)
  {
			 char Dr[40]; char fill[40];
			 Infile>>ID>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y>>Corner3.x>>Corner3.y;
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
void CTriangle::getCenter(Point& c){
	c.x = (Corner1.x + Corner2.x + Corner3.x)/3;
	c.y = (Corner1.y + Corner2.y + Corner3.y)/3;
}

void CTriangle::Move(Point p){
	Point mid;
	getCenter(mid);
	Corner1.x = p.x + (Corner1.x-mid.x);
	Corner2.x = p.x + (Corner2.x-mid.x);
	Corner3.x = p.x + (Corner3.x-mid.x);
	Corner1.y = p.y + (Corner1.y-mid.y);
	Corner2.y = p.y + (Corner2.y-mid.y);
	Corner3.y = p.y + (Corner3.y-mid.y);
}
void CTriangle::Resize(int prec)
{
	//New = (1-t)*(Moved) + t*(Reference)
 Point center;
 this->getCenter(center);
 if (prec==50)
	{
	 Corner1.x=(int) ((0.5)*Corner1.x+(0.5)*center.x);
     Corner1.y=(int) ((0.5)*Corner1.y+(0.5)*center.y);
	 Corner2.x=(int) ((0.5)*Corner2.x+(0.5)*center.x);
     Corner2.y=(int) ((0.5)*Corner2.y+(0.5)*center.y);
	 Corner3.x=(int) ((0.5)*Corner3.x+(0.5)*center.x);
     Corner3.y=(int) ((0.5)*Corner3.y+(0.5)*center.y);

}
  if (prec==25)
	{
	 Corner1.x=(int) ((0.5)*Corner1.x+(0.5)*center.x);
     Corner1.y=(int) ((0.5)*Corner1.y+(0.5)*center.y);
	 Corner2.x=(int) ((0.5)*Corner2.x+(0.5)*center.x);
     Corner2.y=(int) ((0.5)*Corner2.y+(0.5)*center.y);
	 Corner3.x=(int) ((0.5)*Corner3.x+(0.5)*center.x);
     Corner3.y=(int) ((0.5)*Corner3.y+(0.5)*center.y);
	 Corner1.x=(int) ((0.5)*Corner1.x+(0.5)*center.x);
     Corner1.y=(int) ((0.5)*Corner1.y+(0.5)*center.y);
	 Corner2.x=(int) ((0.5)*Corner2.x+(0.5)*center.x);
     Corner2.y=(int) ((0.5)*Corner2.y+(0.5)*center.y);
	 Corner3.x=(int) ((0.5)*Corner3.x+(0.5)*center.x);
     Corner3.y=(int) ((0.5)*Corner3.y+(0.5)*center.y);
  }
  if(prec==200)
  {
     Corner1.x=(int) ((2)*Corner1.x+(-1)*center.x);
     Corner1.y=(int) ((2)*Corner1.y+(-1)*center.y);
	 Corner2.x=(int) ((2)*Corner2.x+(-1)*center.x);
     Corner2.y=(int) ((2)*Corner2.y+(-1)*center.y);
	 Corner3.x=(int) ((2)*Corner3.x+(-1)*center.x);
     Corner3.y=(int) ((2)*Corner3.y+(-1)*center.y);
  }
  if(prec==400)
  {
  
     Corner1.x=(int) ((2)*Corner1.x+(-1)*center.x);
     Corner1.y=(int) ((2)*Corner1.y+(-1)*center.y);
	 Corner2.x=(int) ((2)*Corner2.x+(-1)*center.x);
     Corner2.y=(int) ((2)*Corner2.y+(-1)*center.y);
	 Corner3.x=(int) ((2)*Corner3.x+(-1)*center.x);
     Corner3.y=(int) ((2)*Corner3.y+(-1)*center.y);
	 Corner1.x=(int) ((2)*Corner1.x+(-1)*center.x);
     Corner1.y=(int) ((2)*Corner1.y+(-1)*center.y);
	 Corner2.x=(int) ((2)*Corner2.x+(-1)*center.x);
     Corner2.y=(int) ((2)*Corner2.y+(-1)*center.y);
	 Corner3.x=(int) ((2)*Corner3.x+(-1)*center.x);
     Corner3.y=(int) ((2)*Corner3.y+(-1)*center.y);
  }
}




