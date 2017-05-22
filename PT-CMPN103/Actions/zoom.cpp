#include"zoom.h"
#include"Zoomout.h"
#include "..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"..\GUI\UI_Info.h"
 Zoom::Zoom(ApplicationManager*pApp):Action(pApp)
 {
	 
 }
 void Zoom::ReadActionParameters()
 {}

 void Zoom::Execute()
 {   
	 pManager->zoomin();
 }

 int Zoom::getzoomcounter()
 {return zoomcounter;}

 void Zoom::minuszoomcounter()
 { zoomcounter--;}
 void Zoom::pluszoomcounter()
 {
	 zoomcounter++;
 }

 int Zoom::zoomcounter=0;