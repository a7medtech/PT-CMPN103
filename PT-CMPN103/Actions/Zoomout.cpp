#include"Zoomout.h"
#include"zoom.h"
#include "../GUI\Input.h"
#include"../GUI\Output.h"
#include"../GUI\UI_Info.h"
Zoomout::Zoomout(ApplicationManager*pApp):Action(pApp)
 {
	
 }
 void Zoomout::ReadActionParameters()
 {}
 void Zoomout::Execute()
 {
	
	 pManager->zoomout();
 }

 int Zoomout::getzoomoutcounter()
 { 
	return zoomoutcounter;
 }
 void Zoomout::minuszoomoutcounter()
 
 {zoomoutcounter--;}
 
 void Zoomout::pluszoomoutcounter()
 {
	 zoomoutcounter++;
 }
 void Zoomout::resetzoomoutcounter()
 {
	 zoomoutcounter = 0;
 }
  int Zoomout::zoomoutcounter=0;
