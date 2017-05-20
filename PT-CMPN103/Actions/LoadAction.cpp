#include"../Actions/LoadAction.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures\CFigure.h"
#include"../Figures\CCircle.h"
#include"../Figures\CLine.h"
#include"../Figures\CRectangle.h"
#include"../Figures\CTriangle.h"

LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{

}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
   	pOut->PrintMessage("Now Enter the name of the file which you want to LOAD ");
    filename=pManager->GetInput()->GetSrting(pOut);
}

void LoadAction::Execute()
{
	
	int n=0;pManager->GetFigCount(n);
	if(n!=0)
	{
		pManager->GetOutput()->PrintMessage("Do you want to save the current figures (y/n) ? "	);
		string s= filename=pManager->GetInput()->GetSrting(pManager->GetOutput());
		if(s.compare("y")==NULL)
		{
			pManager->ExecuteAction(SAVE);
		}
	}
	ReadActionParameters();
	pManager->deleteforload();
	In=new ifstream(filename,ios::in);
   if((*In).is_open()) 
   { 
		char s[40];char f[40];char d[40];int nom;char space[5];
		(*In).getline(s,40,'\t');
		(*In).getline(d,40,'\t');
		(*In).getline(f,40,'\n');
		(*In)>>nom;
		(*In).getline(space,5,'\n');
		UI.DrawColor=Save::tocolor(s);
		UI.FillColor=Save::tocolor(d);
		UI.BkGrndColor=Save::tocolor(f);

		while(!(*In).eof())
		{
		char* i=new char[40];
		(*In).getline(i,40,'\t');
		string j=i;
		if(j.compare("LINE")==NULL)
		 {
			 Point P1;Point P2;
			 P1.x=100;P1.y=100;P2.x=100,P2.y=100;
		 LoadInfo.BorderWdth=pManager->GetOutput()->getCrntPenWidth();
			 CLine *n=new CLine(P1,P2,LoadInfo);
			 n->Load(*In);
			 pManager->AddFigure(n);
		 }
		
		else if(j.compare("CIRCLE")==NULL)
		{
		Point P1;double d;
		P1.x=100;P1.y=100;d=0.0;
	    LoadInfo.BorderWdth=pManager->GetOutput()->getCrntPenWidth();
		CCircle *n=new CCircle(P1,d,LoadInfo);
		n->Load(*In);
		pManager->AddFigure(n);
		}
		else if(j.compare("RECTANGLE")==NULL)

		{

		    Point P1;Point P2;
			P1.x=100;P1.y=100;P2.x=100,P2.y=100;
		    LoadInfo.BorderWdth=pManager->GetOutput()->getCrntPenWidth();
			CRectangle *n=new CRectangle(P1,P2,LoadInfo);
			
			n->Load(*In);
		   pManager->AddFigure(n);
		}
		else if(j.compare("TRIANGLE")==NULL)

		{
			  Point P1;Point P2;Point P3;
		P1.x=100;P1.y=100;P2.x=100,P2.y=100;P3.x=100,P3.y=100;
		CTriangle*n=new CTriangle(P1,P2,P3,LoadInfo);
		n->Load(*In);
		pManager->AddFigure(n);
		
	   }
		delete [] i;
	}
		(*In).close();
}
}
