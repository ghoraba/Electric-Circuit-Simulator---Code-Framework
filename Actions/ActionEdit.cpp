#include "ActionEdit.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include<string>  
ActionEdit::ActionEdit(ApplicationManager* pApp) :Action(pApp)
{
}

ActionEdit::~ActionEdit(void)
{
}
void ActionEdit::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select the component/connection you wish to Edit");
	int x, y;


	/// ///////////
	pUI->GetPointClicked(x, y);
	Component* comp1 = pManager->GetComponentByCordinates(x,y);
	Connection* conn1 = pManager->GetConnByCordinates(x, y);
	while (comp1 == nullptr && conn1 == nullptr) {
		pUI-> GetPointClicked(x, y);
		pUI->PrintMsg("Select the compnent/Connection you want to edit");
	}
	// // // // // // / //
		pUI->ClearStatusBar();
		comp1 = pManager->GetComponentByCordinates(x, y);
		conn1 = pManager->GetConnByCordinates(x, y);
		if (comp1 != nullptr) {
			ALLCOMPS CompNumber = comp1->whichComponent();
			switch (CompNumber) {
			case RESISTOR:
			case BULB:
			case BUZZER:
			{
				//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit resistace value or 3 to cancel ");
				string value;
				int intValue;
					do {
						value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit resistace value or 3 to cancel ", "");
					} while (value != "1" && value != "2" && value != "3");
					intValue = stod(value);
					switch (intValue) {
					case 1:
					{
						
						value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
						comp1->setlabel(value);
						break;
					}
					case 2:
					{
						value = pUI->GetSrting(to_string(comp1->getResistance()), to_string(comp1->getResistance()));
						comp1->setresistance(stod(value));
						break;
					}
					case 3:
						break;
					}
					break;
					
			}
			case FUZE:
			{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
				string value;
				int intValue;
				do {
					value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ", "");
				} while (value != "1" && value != "2" && value != "3");
				intValue = stod(value);
				switch (intValue) {
				case 1:
				{

					value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
					comp1->setlabel(value);
					break;
				}
				case 2:
				{
					value = pUI->GetSrting(to_string(comp1->getMaxFuze()), to_string(comp1->getMaxFuze()));
					comp1->setMaxFuze(stod(value));
					break;
				}
				case 3:
					break;
				}
				break;
			}
			case SWITCH:
			{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
				string value;
				int intValue;
				do {
					value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Switch status or 3 to cancel ", "");
				} while (value != "1" && value != "2" && value != "3");
				intValue = stod(value);
				switch (intValue) {
				case 1:
				{

					value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
					comp1->setlabel(value);
					break;
				}
				case 2:
				{
					value = pUI->GetSrting(to_string(comp1->getSwitchState()), to_string(comp1->getSwitchState()));
					comp1->setSwitchState(stod(value));
					break;
				}
				case 3:
					break;
				}
				break;
			}
			case BATTERY:
			{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
				string value;
				int intValue;
				do {
					value = pUI->GetSrting("enter 1 to edit the label, 2 to the edit Battery voltage or 3 to cancel ", "");
				} while (value != "1" && value != "2" && value != "3");
				intValue = stod(value);
				switch (intValue) {
				case 1:
				{

					value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
					comp1->setlabel(value);
					break;
				}
				case 2:
				{
					value = pUI->GetSrting(to_string(comp1->getBatteryVoltage()), to_string(comp1->getBatteryVoltage()));
					comp1->setSourceVoltage(stod(value));
					break;
				}
				case 3:
					break;
				}
				break;
			}
			case GROUND:
			{	//pUI->PrintMsg("enter 1 to edit the label, 2 to the edit Maximum Fuze current value or 3 to cancel ","");
				string value;
				int intValue;
				do {
					value = pUI->GetSrting("enter 1 to edit the label or 2 to cancel ", "");
				} while (value != "1" && value != "2");
				intValue = stod(value);
				switch (intValue) {
				case 1:
				{

					value = pUI->GetSrting(comp1->getLabel(), comp1->getLabel());
					comp1->setlabel(value);
					break;
				}
				
				case 2:
					break;
				}
				break;
			}
			}
		}
		else if (conn1 != nullptr) {
		string value;
		int intValue;
		do {
			value = pUI->GetSrting("enter 1 to edit the label or 2 to cancel ", "");
		} while (value != "1" && value != "2");
		intValue = stod(value);
		switch (intValue) {
		case 1:
		{

			value = pUI->GetSrting(conn1->getLabel(), conn1->getLabel());
			conn1->setLabel(value);
			break;
		}

		case 2:
			break;
		}
		}
	pUI->ClearStatusBar();
}
void ActionEdit::Undo()
{}

void ActionEdit::Redo()
{}