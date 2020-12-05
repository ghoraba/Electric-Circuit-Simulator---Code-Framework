#include "ActionAddSwitch.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionAddSwitch::ActionAddSwitch(ApplicationManager * pApp) :Action(pApp)
{
}

ActionAddSwitch::~ActionAddSwitch(void)
{
}

void ActionAddSwitch::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn

	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > UI::getToolBarHeight() + UI::getCompHeight() / 2
		&& Cy < UI::Height() - UI::getStatusBarHeight() - UI::getCompHeight() / 2
		&& Cx > UI::getCompWidth() / 2
		&& Cx < UI::getWidth() - UI::getCompWidth() / 2)) {
		pUI->GetPointClicked(Cx, Cy);

	}

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Switch* pR = new Switch(pGInfo);
	string value = pUI->GetSrting("Enter Switch Value: 1 means closed while 0 means open switch");
	while (value == "")
		value = pUI->GetSrting("Enter Switch Value: 1 means closed while 0 means open switch");
	pR->setSwitchState(stod(value));

	//string s;
	//s = pUI->GetSrting("Enter Label: Resistor","Resistor");
	//pR->setlabel(s);

	pUI->ClearStatusBar();

	/*pR->getCompCenterX(pUI) - 50;
	pR->getCompCenterY(pUI) + 60;*/

	pManager->AddComponent(pR);


}

void ActionAddSwitch::Undo()
{}

void ActionAddSwitch::Redo()
{}
