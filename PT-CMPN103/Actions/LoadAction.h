#pragma once
#include "../Actions\Action.h"
class LoadAction :
     public Action
{
private:
    ifstream *In;
    string filename;
	GfxInfo LoadInfo;
public:
	LoadAction(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute() ;
};