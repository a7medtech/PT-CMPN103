#ifndef DEFS_H
#define DEFS_H
#include <deque>
#include "./CMUgraphicsLib/CMUgraphics.h"
//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	/*DRAW MODE*/
	ADD_FIGURE,     //Open figures tool.
	EDIT_FIGURE,
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	ZOOM_IN,        //Zoom in to the figures
	ZOOM_OUT,       //Zoom out from the figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXITSAVE,
	EXIT,			//Exit the application
	//////////////////////////////////////////////////
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	BORDER,
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	COPY,           //Copy the figure
	CUT,            //Cut the figure
	PASTE,          //Paste figure from clipboard
	BACK,
	
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

		
	TO_PLAY,			//Switch interface to Play mode

	/*PLAY MODE*/

	PICK_HIDE_MODE,      //Start pick and hide game
	SCRAMBLE_FIND_MODE,  //Start scramble and fing mode
	START_SCRAMBLE,      //Start new game
	BACKPLAY,
	TO_DRAW              //Switch interface to Draw mode
	//SEL_FIG        //Select figure from the drawing area
	///TODO: Add more action types (if needed)
};
	

struct Point	//To be used for figures points
{ int x,y; 
bool operator==(Point p){
	return (x == p.x)&&(y == p.y);
}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif