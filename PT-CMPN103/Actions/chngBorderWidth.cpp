#include"chngBorderWidth.h"
#include "../GUI\Input.h"
#include"../GUI\Output.h"
#include"../GUI\UI_Info.h"
chngBorderWidth::chngBorderWidth(ApplicationManager *pApp):Action(pApp)
{
}
void chngBorderWidth::ReadActionParameters()
{
	Point p;
	 Output* pOut = pManager->GetOutput();
	 string BorderItems[Border_item_count];
	 BorderItems[Item_plus] = "images\\Border\\plus.jpg";
	 BorderItems[Item_minus] = "images\\Border\\minus.jpg";
	for(int i=0;i<Border_item_count;i++)
	{pOut->getWindow()->DrawImage(BorderItems[i], (1440-100),(i+1)*UI.ToolBarHeight,UI.MenuItemWidth, UI.ToolBarHeight);}
	pManager->GetInput()->GetPointClicked(p.x,p.y);
	if(p.x>=(1440-100)&&(p.x)<=(1440))
	{
		if(p.y>=UI.ToolBarHeight&&p.y<=2*UI.ToolBarHeight)            //clicked on  plus
			this->changeprec=2;
		if(p.y>=2*UI.ToolBarHeight&&p.y<=3*UI.ToolBarHeight)         // clicked on minus
			this->changeprec=-2;

	}
	pManager->GetOutput()->ClearDrawArea();
}
void chngBorderWidth::Execute()
{   
	ReadActionParameters();
	pManager->chngeborder(this->changeprec);
}


