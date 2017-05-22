#include"Exit.h"
#include "../GUI\Input.h"
#include"../GUI\Output.h"
#include"../GUI\UI_Info.h"
ExitAction::ExitAction(ApplicationManager*pApp):Action(pApp)
{
}
void ExitAction::ReadActionParameters()
{
	Point p;
	 Output* pOut = pManager->GetOutput();
	 pOut->PrintMessage("Do you want to save the current figures before EXIT ?");
	 string ExitItems[Exit_item_count];
	 ExitItems[Item_Yes] = "images\\Exit\\yes.jpg";
	 ExitItems[Item_No] = "images\\Exit\\no.jpg";
	 for(int i=0;i<Exit_item_count;i++)
	{pOut->getWindow()->DrawImage(ExitItems[i], (1440-100),(i+1)*UI.ToolBarHeight,UI.MenuItemWidth, UI.ToolBarHeight);}
	pManager->GetInput()->GetPointClicked(p.x,p.y);
	if(p.x>=(1440-100)&&(p.x)<=(1440))
	{
		if(p.y>=UI.ToolBarHeight&&p.y<=2*UI.ToolBarHeight)            //clicked on  Yes
			this->yesno="YES";
		if(p.y>=2*UI.ToolBarHeight&&p.y<=3*UI.ToolBarHeight)         // clicked on No
			this->yesno="NO";

	}
}
void ExitAction::Execute()
{
	ReadActionParameters();
	pManager->exit(yesno);
		

}