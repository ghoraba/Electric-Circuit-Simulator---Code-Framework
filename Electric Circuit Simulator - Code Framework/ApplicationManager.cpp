#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddBuzzer.h"
#include"Actions/ActionAddConnection.h"
#include <iostream>
#include<cmath>
using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	IsSimulation = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
void ApplicationManager::AddConnection(Connection* pConn) {
	ConnList[ConnCount++] = pConn;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
	case ADD_RESISTOR:
		pAct = new ActionAddRes(this);
		break;
	case ADD_BULB:
		pAct = new ActionAddBulb(this);
		break;
	case ADD_BUZZER:
		pAct = new ActionAddBuzzer(this);
		break;
	case ADD_CONNECTION:
		pAct = new ActionAddConnection(this);
		break;
	/*case SELECT:
		pAct=*/
		// TODO: Add remaining actions
		/*case ADD_BULB:
			pAct = new ActionAddRes(this);
			break;*/

	case EXIT:
		///TODO: create ExitAction here
		break;
	}
	if (pAct)
	{
		pAct->Execute();

		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(pUI);
	for (int i = 0; i < ConnCount; i++)
		ConnList[i]->Draw(pUI);
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
////////////////////////////////////////////////////////////////////
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit() {
	return true;
}
Component* ApplicationManager::GetComponentByCordinates(int x, int y) {
	UI* pUI = GetUI();
	int  isExist = 0;
	int ydifference, xdifference;
	int compheight = pUI->getCompHeight();
	int compwidth = pUI->getCompWidth();
	for (int i = 0; i < CompCount; i++) {
		
		ydifference =abs( y - CompList[i]->getCompCenterY(pUI));
		xdifference = abs(x - CompList[i]->getCompCenterX(pUI));
		if ((ydifference<= compheight / 2) && (xdifference <= compwidth / 2)){
			isExist = 1;
		return CompList[i];
		
		break;
		}

		
	}
	if (isExist == 0)
		return nullptr;
}
		

////////////////////////////////////////////////////////////////////
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		// TODO
	}
	else {
		this->IsSimulation = true;
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		CalculateVoltages(current);
	}
}
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	// TODO
	return 0;
}

// Calculates voltage at each component terminal
void ApplicationManager::CalculateVoltages(double current) {
	// TODO
}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	// TODO
}