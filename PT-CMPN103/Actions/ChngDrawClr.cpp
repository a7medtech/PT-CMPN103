#include "ChngDrawClr.h"
#include "../Actions/BackAction.h"
#include "../GUI/Output.h"

ChngDrawClr::ChngDrawClr(ApplicationManager* pApp):Action(pApp)
{}

void ChngDrawClr::ReadActionParameters()
{}

void ChngDrawClr::Execute()
{
	pManager->GetOutput()->PrintMessage("Choose the drawing color from the palette on the right");
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
			
			int no;
			pManager->GetSelectedFigCount(no);
			CFigure** SelFig;
			pManager->FindSelFigList(SelFig);
			if (no != 0)
			{
				for (int i = 0; i < no; i++)
					SelFig[i]->ChngDrawClr(clr);
			}
			else
			{
				pManager->GetOutput()->CHNG_DRAW_CLR(clr);
			}
			BackAction ba(pManager);
			ba.Execute();
			pManager->GetOutput()->ClearStatusBar();
			break;
		}
		else
			pManager->GetOutput()->PrintMessage("Please choose the draw color from the palette on the right");
	}
}

ChngDrawClr::~ChngDrawClr()
{}