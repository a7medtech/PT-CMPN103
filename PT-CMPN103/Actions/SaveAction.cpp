#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Actions/SaveAction.h"

Save::Save(ApplicationManager *pApp):Action(pApp)
{

}
 void Save :: ReadActionParameters()
 {

   Output* pOut = pManager->GetOutput();
   	pOut->PrintMessage("Save to File enter the file name: ");
    filename=pManager->GetInput()->GetSrting(pOut);
	filename += ".txt";
   
}
 void Save:: Execute()
 {
     ReadActionParameters();
     Out=new ofstream(filename,ios::out);
     pManager->SaveAction(*Out);


}
