#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddBuzzer.h"
#include"Actions/ActionAddConnection.h"
#include"Actions/ActionDelete.h"
#include"Actions/ActionSelect.h"
#include"Actions/ActionEdit.h"
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
void ApplicationManager::DelSelected() {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			if (CompList[i]->isSelected()) {
				Connection** one = CompList[i]->getTermConnections(TERM1);
				Connection** two = CompList[i]->getTermConnections(TERM2);
				for (int j = 0; j < 20; j++) {
					DelConn(one[j]);
					DelConn(two[j]);
				}
				DelComponent(CompList[i]);
			}
		}
	}
	for (int i = 0; i < ConnCount; i++){
		if (ConnList[i] != nullptr)
			if (ConnList[i]->isSelected())
				DelConn(ConnList[i]);
	}
	reArrange();

}
void ApplicationManager::DelComponent(Component* pComp)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] == pComp) {
			
			delete CompList[i];
			CompList[i] = nullptr;
			
			
		}
	}
	
	
}
void ApplicationManager::DelConn(Connection* pConn)
{
	for (int i = 0; i < ConnCount; i++) {
		 
		if (ConnList[i] == pConn&& pConn!=nullptr) {
			Component* comp2 = ConnList[i]->getComp(1);
			Component* comp3 = ConnList[i]->getComp(2);
			comp2->deletecon(ConnList[i]);
			comp3->deletecon(ConnList[i]);
			delete ConnList[i];
			
			ConnList[i] = nullptr;
			
		}
	}

}
void ApplicationManager::DelAll() {
	for (int i = 0; i < CompCount; i++) {
		delete CompList[i];}
	for (int i = 0; i < ConnCount; i++) {
		delete ConnList[i];
	}
}
void ApplicationManager::AddConnection(Connection* pConn) {
	ConnList[ConnCount++] = pConn;
}
void ApplicationManager::UnselectAll(Component* pComp) {
	for (int i = 0; i < CompCount; i++){
		if(CompList[i]!=pComp&&CompList[i]!=nullptr)
			CompList[i]->unSelect();
}
	for (int i = 0; i < ConnCount; i++)
		if(ConnList[i]!=nullptr)
		ConnList[i]->unSelect();
}
void ApplicationManager::UnselectAll(Connection* pConn) {
	
	for (int i = 0; i < CompCount; i++)
		if(CompList[i]!=nullptr)
			CompList[i]->unSelect();
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr&& ConnList[i] != pConn) 
			ConnList[i]->unSelect();
	
	}
}
void ApplicationManager::reArrange() {
	Component* tempCompList[MaxCompCount];	
	Connection* tempConnList[MaxConnCount];
	int counter = 0;
	for(int i=0;i<CompCount;i++)
		if (CompList[i] != nullptr) {
			tempCompList[counter] = CompList[i];
			counter++;
		}
	for (int i = 0; i < CompCount; i++) {
		CompList[i] = tempCompList[i];
		tempCompList[i] = nullptr;
	}
	CompCount = counter;
	counter = 0;
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			tempConnList[counter] = ConnList[i];
			counter++;
		}
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i] = tempConnList[i];
		tempConnList[i] = nullptr;
	}
	ConnCount = counter;
	////Component* tempComp;
	//Connection* tempConn;
	//int counter = 0;
	////CompCount--;
	//for (int i = 0; i < CompCount; i++) {
	//	counter = 0;
	//	if (CompList[i] == nullptr&&i< (CompCount-1)) {
	//		while (CompList[i + counter] == nullptr&& (i + counter)< CompCount)
	//			counter++;

	//		//tempComp = CompList[i];
	//		CompList[i] = CompList[i + counter];
	//		CompList[i + 1] = nullptr;
	//		
	//	}
	//}
	//
	//counter = 0;
	//ConnCount--;
	//for (int i = 0; i < ConnCount+1; i++) {
	//	if (ConnList[i] == nullptr && i < ConnCount) {
	//		tempConn=ConnList[i];
	//		ConnList[i] = ConnList[i + 1];
	//		ConnList[i + 1] = tempConn;
	//		
	//	}
	//}
	//
		
	
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
	case SELECT:
		pAct = new ActionSelect(this);
		break;
	case EDIT:
		pAct = new ActionEdit(this);
		break;
	case DEL:
		pAct = new ActionDelete(this);
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
	pUI->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr) {
			CompList[i]->Draw(pUI);
		}
	for (int i = 0; i < ConnCount; i++)
		if (ConnList[i] != nullptr) {
			ConnList[i]->Draw(pUI);
		}
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
		if (CompList[i] != nullptr) {
			ydifference = abs(y - CompList[i]->getCompCenterY(pUI));
			xdifference = abs(x - CompList[i]->getCompCenterX(pUI));
			if ((ydifference <= compheight / 2) && (xdifference <= compwidth / 2)) {
				isExist = 1;
				return CompList[i];

				break;
			}

		}
	}
	if (isExist == 0)
		return nullptr;
}
Connection* ApplicationManager::GetConnByCordinates(int x, int y) {
	UI* pUI = GetUI();
	int  isExist = 0;
	int x1;
	int x2;
	int y1;
	int y2;
	double slope;
	int right, left;
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr) {
			x1 = ConnList[i]->getgraphics()->PointsList[0].x;
			x2 = ConnList[i]->getgraphics()->PointsList[1].x;
			y1 = ConnList[i]->getgraphics()->PointsList[0].y;
			y2 = ConnList[i]->getgraphics()->PointsList[1].y;
			slope = ConnList[i]->lineslope();
			
			for(int j=-5;j<=5;j++) {
				if ((x + j >= x2 && x + j <= x1) || (x + j >= x1 && x + j <= x2)) {
					for (int k = -4; k <= 4; k++){
						if(x1!=x2){
						right = slope*(x - (x1+k));
						left = y - (y1 + k);}
						else {
							right = x - (x1 + k);
							left = 0;
						}
						if (left == right) {
							return ConnList[i];
							isExist = 1;
							break;
						}
					}
				}
			}
			/*if (x1 > x2) {
				for (int j = -5; j <= 5; j++) {
				if ((x+j) >= x2 && (x+j) <= x1) {
					for (int k = -5; k <= 5; k++) {
						if (x1 != x2) {
							right = y - (y1 + k);
							left = slope * (x - (x1 + k));
						}
						else {
							left = x - (x1 + k);
							right = 0;
						}
						if (right == left) {
							return ConnList[i];

							isExist = 1;
							break;
						
						}
					}
					}
				}
			}
			if (x2 >= x1) {
				for (int j = -5; j <= 5; j++) {
					if ((x + j) >= x1 && (x + j) <= x2) {
						for (int k = -5; k <= 5; k++) {
							if (x1 != x2) {
								right = y - (y2 + k);
								left = slope * (x - (x2 + k));
							}
							else {
								left = x - (x2 + k);
								right = 0;
							}
							if (right == left) {
								return ConnList[i];
								isExist = 1;
								break;
							}
						}
					}
				}
			}*/
			
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