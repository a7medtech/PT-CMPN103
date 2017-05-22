#include "Input.h"
#include "Output.h"


Input::Input(window* pW, Output*pO) 
{
	pWind = pW; //point to the passed window
	pOut = pO;
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}


void Input::setsaved()
{
	saved = true;
}


string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}


ActionType Input::GetItemAction(ActionType Selected) const
{
	int x, y;
	switch (Selected)
	{
	case ADD_FIGURE:
		pOut->CreateDrawMenuToolBar();
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that ADD menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_LINE: return DRAW_LINE;
			case ITM_RECT: return DRAW_RECT;
			case ITM_TRI:  return DRAW_TRI;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_BACKDRAW: return BACK;
			default: return EMPTY;
			}
		}
		
	case EDIT_FIGURE:
		pOut->CreateEditToolBar();
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that EDIT menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_DEL:		return DEL;			    //DEL figure(s)
			case ITM_MOVE:		return MOVE;			//MOVE figure(s)
			case ITM_RESIZE:	return RESIZE;			//Resize a figure(s)
			case ITM_ROTATE:	return ROTATE;			//Rotate a figure(s)
			case ITM_SEND_BACK: return SEND_BACK;		//Send a figure to the back of all figures
			case ITM_BRNG_FRNT: return BRNG_FRNT;		//Bring a figure to the front of all figures
			case ITM_COPY:      return COPY;			//Copy the figure
			case ITM_CUT:       return CUT;				//Cut the figure
			case ITM_PASTE:     return PASTE;
			case ITM_BORDER:    return BORDER;
			case ITM_BACKEDIT:		return BACK;
			default:			return EMPTY;
			}
		}
		break;

	case CHNG_DRAW_CLR:
		return CHNG_DRAW_CLR;
	case CHNG_FILL_CLR:
		return CHNG_FILL_CLR;
	case CHNG_BK_CLR:
		return CHNG_BK_CLR;
	case ZOOM_IN:
		return ZOOM_IN;
	case ZOOM_OUT:
		return ZOOM_OUT;
	case SAVE:
		return SAVE;
	case LOAD:
		return LOAD;
	case EXIT:
		if (saved == false)
		{
			return EXITSAVE;
		}
		else { return EXIT; }

	case TO_PLAY:
		pOut->CreatePlayToolBar();	
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that EDIT menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_PICK_HIDE_MODE: return PICK_HIDE_MODE;     //Start pick and hide game
			case ITM_SCRAMBLE_FIND_MODE: return SCRAMBLE_FIND_MODE;  //Start scramble and fing mode
			case ITM_TO_DRAW: return TO_DRAW;
			case ITM_EXITPLAY: return EXIT;
			default:
				return EMPTY;
			}
		}
	}
	return EMPTY;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	//ActionType Selected;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	switch (UI.InterfaceMode)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
	case MODE_DRAW_MAIN:
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			
			switch (ClickedItemOrder)
			{
			case ITM_ADD: return GetItemAction(ADD_FIGURE);
			case ITM_EDIT:return GetItemAction(EDIT_FIGURE);
			case ITM_CHNG_DRAW_CLR: return GetItemAction(CHNG_DRAW_CLR);	//Change the drawing color
			case ITM_CHNG_FILL_CLR: return GetItemAction(CHNG_FILL_CLR);	//Change the filling color
			case ITM_CHNG_BK_CLR: return GetItemAction(CHNG_BK_CLR);	//Change background color
			case ITM_ZOOM_IN: return GetItemAction(ZOOM_IN);        //Zoom in to the figures
			case ITM_ZOOM_OUT: return GetItemAction(ZOOM_OUT);       //Zoom out from the figures
			case ITM_SAVE: return GetItemAction(SAVE);			//Save the whole graph to a file
			case ITM_LOAD: return GetItemAction(LOAD);			//Load a graph from a file
			case ITM_EXIT: return GetItemAction(EXIT);
			case ITM_TO_PLAY: return GetItemAction(TO_PLAY);

				//////////////////////////////////////
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		break;

	case MODE_DRAW_DRAW:     //if interfacemode is draw / add figure mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that ADD menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_LINE: return DRAW_LINE;
			case ITM_RECT: return DRAW_RECT;
			case ITM_TRI:  return DRAW_TRI;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_BACKDRAW: return BACK;
			default: return EMPTY;

			}

		}
		break;
	case MODE_DRAW_EDIT:        //if interface mode is edit
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that EDIT menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_DEL:		return DEL;			    //DEL figure(s)
			case ITM_MOVE:		return MOVE;			//MOVE figure(s)
			case ITM_RESIZE:	return RESIZE;			//Resize a figure(s)
			case ITM_ROTATE:	return ROTATE;			//Rotate a figure(s)
			case ITM_SEND_BACK: return SEND_BACK;		//Send a figure to the back of all figures
			case ITM_BRNG_FRNT: return BRNG_FRNT;		//Bring a figure to the front of all figures
			case ITM_COPY:      return COPY;			//Copy the figure
			case ITM_CUT:       return CUT;				//Cut the figure
			case ITM_PASTE:     return PASTE;
			case ITM_BACKEDIT:		return BACK;
			default:			return EMPTY;
			}
		}
		break;

	case MODE_PLAY: // if interface mode is play

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that EDIT menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_PICK_HIDE_MODE: return PICK_HIDE_MODE;     //Start pick and hide game
			case ITM_SCRAMBLE_FIND_MODE: return SCRAMBLE_FIND_MODE;  //Start scramble and fing mode
			case ITM_TO_DRAW: return TO_DRAW;
			case ITM_EXITPLAY: return EXIT;
			default:
				return EMPTY;
			}
		}
		break;
	case MODE_PLAY_SCRAMBLE_FIND:
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_START: return START_SCRAMBLE;
		case ITM_BACKSCRAMBLE: return BACKPLAY;
		default:
			return EMPTY;
			break;
		}

		break;
	}


		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
/////////////////////////////////
	
Input::~Input()
{
}
