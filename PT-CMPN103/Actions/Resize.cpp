#include "..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"../GUI\UI_Info.h"
#include"../Actions/Resize.h"

ResizeAction::ResizeAction(ApplicationManager* pApp):Action(pApp)
{
}
void ResizeAction::ReadActionParameters()
{
	Point p;
	 Output* pOut = pManager->GetOutput();
	 string ResizeItems[Resize_item_count];
	 ResizeItems[Item_quarter] = "images\\Resize\\quarter.jpg";
	 ResizeItems[Item_half] = "images\\Resize\\half.jpg";
	 ResizeItems[Item_double] = "images\\Resize\\double.jpg";
	 ResizeItems[Item_forth] = "images\\Resize\\forth.jpg";
	for(int i=0;i<Resize_item_count;i++)
	{pOut->getWindow()->DrawImage(ResizeItems[i], (1440-100),(i+1)*UI.ToolBarHeight,UI.MenuItemWidth, UI.ToolBarHeight);}
	pManager->GetInput()->GetPointClicked(p.x,p.y);
	if(p.x>=(1440-100)&&(p.x)<=(1440))
	{
		if(p.y>=UI.ToolBarHeight&&p.y<=2*UI.ToolBarHeight)            //clicked on  quarter
			this->resizeprec=25;
		if(p.y>=2*UI.ToolBarHeight&&p.y<=3*UI.ToolBarHeight)         // clicked on half
			this->resizeprec=50;
	   if(p.y>=3*UI.ToolBarHeight&&p.y<=4*UI.ToolBarHeight)          //clicked on double
		   this->resizeprec=200;
	   if(p.y>=4*UI.ToolBarHeight&&p.y<=5*UI.ToolBarHeight)          //clicked on fourth
		   this->resizeprec=400;
	}
	pManager->GetOutput()->ClearDrawArea();
}
void ResizeAction::Execute()
{
	ReadActionParameters();
	pManager->Resizefigures(this->resizeprec);
	
}

