#include "CFigure.h"

bool CFigure::isFill = false;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	isFill = FigGfxInfo.isFilled;
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }


void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
	isFill = true;
}
void CFigure::setID(int id)
{ 
	ID=id;
}
int CFigure::getID(){
	if (this == nullptr)
		return 0;
	return ID;
}

