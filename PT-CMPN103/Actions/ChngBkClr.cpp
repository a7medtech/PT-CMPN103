#include "ChngBkClr.h"
#include "../Actions/BackAction.h"
#include "../GUI/Output.h"

ChngBkClr::ChngBkClr(ApplicationManager* pApp) :Action(pApp)
{}

void ChngBkClr::ReadActionParameters()
{}

void ChngBkClr::Execute()
{
	pManager->GetOutput()->PrintMessage("Choose the background color from the palette on the right");
	image im("images\\spectrum_chart.jpg");
	Action::pManager->GetOutput()->getWindow()->DrawImage(im, 990, 391, 450, 279);
	int x, y;
	while (true)
	{
		pManager->GetOutput()->getWindow()->WaitMouseClick(x, y);
		color clr;
		clr = pManager->GetOutput()->getWindow()->GetColor(x, y);
		if (x > 990 && y > 391 && y < 670 && clr!=UI.HighlightColor)
		{
			
			pManager->GetOutput()->CHNG_BK_CLR(clr);
			BackAction ba(pManager);
			ba.Execute();
			pManager->GetOutput()->ClearStatusBar();
			break;
		}
		else
			pManager->GetOutput()->PrintMessage("Please choose the background color from the palette on the right");
	}
}

ChngBkClr::~ChngBkClr()
{}