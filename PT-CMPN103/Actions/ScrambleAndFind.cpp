#include "ScrambleAndFind.h"
#include "../ApplicationManager.h"


ScrambleAndFind::ScrambleAndFind(ApplicationManager*pApp):Action(pApp)
{}

void ScrambleAndFind::ReadActionParameters()
{

}

void ScrambleAndFind::Execute()
{
	pManager->GetOutput()->EnterScrambleAndFind();
	
}

ScrambleAndFind::~ScrambleAndFind()
{
}
