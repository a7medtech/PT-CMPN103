#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface


enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW_MAIN,	//Drawing mode (startup mode) Main Menu
	MODE_DRAW_DRAW, //Drawing mode Draw Menu
	MODE_DRAW_EDIT, //Drawing mode Edit Menu
	MODE_PLAY,	//Playing mode
	MODE_PLAY_PICK_HIDE,	
	MODE_PLAY_SCRAMBLE_FIND
};


enum MainMenuItem
{
	ITM_ADD,
	ITM_EDIT,
	ITM_CHNG_DRAW_CLR,	//Change the drawing color
	ITM_CHNG_FILL_CLR,	//Change the filling color
	ITM_CHNG_BK_CLR,	//Change background color

	ITM_ZOOM_IN,        //Zoom in to the figures
	ITM_ZOOM_OUT,       //Zoom out from the figures
	ITM_SAVE,			//Save the whole graph to a file
	ITM_LOAD,			//Load a graph from a file
	ITM_EXIT,			//Exit the application
	ITM_TO_PLAY,			//Switch interface to Play mode
	
	MAIN_ITM_COUNT




	
	
};

enum FigReference   //specify where the user clicked on the figure.
{
	CENTER,
	CORNER1,
	CORNER2,
	CORNER3,
	CORNER4,
	NONEREF
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
					

					/*DRAW MODE*/
			
					ITM_LINE,		//Line Item
					ITM_RECT,		//Recangle item in menu
					ITM_TRI,		//Triangle Item
					ITM_CIRC,		//Circle item in menu
					ITM_BACKDRAW,
					DRAW_ITM_COUNT
				
					//ITM_SEL_FIG,        //Select figure from the drawing area
};


enum EditMenuItrem
{
	ITM_DEL,			//Delete a figure(s)
	ITM_MOVE,			//Move a figure(s)
	ITM_RESIZE,			//Resize a figure(s)
	ITM_ROTATE,			//Rotate a figure(s)
	ITM_SEND_BACK,		//Send a figure to the back of all figures
	ITM_BRNG_FRNT,		//Bring a figure to the front of all figures
	ITM_COPY,           //Copy the figure
	ITM_CUT,            //Cut the figure
	ITM_PASTE,          //Paste figure from clipboard
	ITM_BORDER, //changer border width
	ITM_BACKEDIT,
	EDIT_ITM_COUNT


};
enum EditMenuItemZoom
{
	ITM_DELZOOM,
	ITM_MOVEZOOM,
	ITM_RESIZEZOOM,
	ITM_ROTATEZOOM,
	ITM_SEND_BACKZOOM,
	ITM_BRNG_FRNTZOOM,
	ITM_COPYZOOM,
	ITM_CUTZOOM,
	ITM_PASTEZOOM,
	ITM_BORDERZOOM,
	ITM_BACKEDITZOOM,
	EDIT_ITM_COUNTZOOM

};


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	/*PLAY MODE*/

	ITM_PICK_HIDE_MODE,      //Start pick and hide game
	ITM_SCRAMBLE_FIND_MODE,  //Start scramble and fing mode
	ITM_TO_DRAW,       //Switch interface to Draw mode
	ITM_EXITPLAY,
					   //TODO: Add more items names here
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};



enum ScrambleAndFindMenu
{
	ITM_START,     //Start the game
	ITM_BACKSCRAMBLE,
	ITM_RIGHT,     //Counter Icon for right choices
	ITM_WRONG,     //Counter icon for wrong choices
	SCRAMBLE_ITM_COUNT
};
enum PickHideMenu {
	ITM_STARTPH, // start the game
	ITM_BACKPH,
	ITM_RIGHTC, //counter Icon for right choices
	ITM_WRONGC //counter Icon for right choices
};
enum BorderItems
{
	Item_plus,
	Item_minus,
	Border_item_count
};

enum ExitItems
{
	Item_Yes,
	Item_No,
	Exit_item_count
};

enum ResizeItems //items for resize sub menu items

{
	Item_quarter,
	Item_half,
	Item_double,
	Item_forth,
	Resize_item_count
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color ToolBarColor;
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif