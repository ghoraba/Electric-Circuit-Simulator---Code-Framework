#include "ActionSave.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSave::~ActionSave(void)
{
}
void ActionSave::Execute()
{
	fstream saveFile;
	UI* pUI = pManager->GetUI();
	string fileName = pUI->GetSrting("Enter File name please ", "");
	if (fileName == "")
		fileName = "test";
		+ ".txt";
	pManager->Save(saveFile, fileName);
}
void ActionSave::Undo()
{}

void ActionSave::Redo()
{}