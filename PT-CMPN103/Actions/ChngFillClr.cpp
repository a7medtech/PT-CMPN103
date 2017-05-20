#include "ChngFillClr.h"
#include "BackAction.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"

ChngFillClr::ChngFillClr(ApplicationManager* pApp):Action(pApp)
{}

void ChngFillClr::ReadActionParameters()
{}

void ChngFillClr::Execute()
{
	pManager->GetOutput()->PrintMessage("Choose the fill color from the palette on the right");
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
					SelFig[i]->ChngFillClr(clr);
			}
			else
			{
				CFigure::isFill = true;  //to change default status of isFilled to true
				pManager->GetOutput()->CHNG_FILL_CLR(clr);
			}
			BackAction ba(pManager);
			ba.Execute();
			pManager->GetOutput()->ClearStatusBar();
			break;
		}
		else 
			pManager->GetOutput()->PrintMessage("Please choose the fill color from the palette on the right");
	}
}

ChngFillClr::~ChngFillClr()
{}