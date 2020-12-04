#include "ActionSelect.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}
void ActionSelect::Execute() {
	UI* pUI = pManager->GetUI();
	x = pUI->getXtemp();
	y = pUI->getYtemp();
	Component* comp1 = pManager->GetComponentByCordinates(x, y);
	Connection* conn1 = pManager->GetConnByCordinates(x, y);
	if (comp1 != nullptr){
		
		//pManager->UnselectAll(comp1);
		comp1->Selection();
	}
	else if (conn1 != nullptr) {
		
		//pManager->UnselectAll(conn1);
		conn1->Selection();
	}

}
void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}