#pragma once
#include "..\Actions\Action.h"
class Save :
     public Action
{
private:
    ofstream *Out;
    string filename;

public:
    Save(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};