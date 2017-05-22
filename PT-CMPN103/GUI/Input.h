#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
	Output* pOut;   //Pointer to output function in order to communicate with it directly to draw toolbars.
	bool saved; //check before exit if the current file saved or not 
public:
	Input(window *pW, Output*pO);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map to an action
	ActionType GetItemAction(ActionType Selected) const;
	void setsaved();

	~Input();
};

#endif