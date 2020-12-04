#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDelete::~ActionDelete(void)
{
}
void ActionDelete::Execute()
{
	//UI* pUI = pManager->GetUI();
	pManager->DelSelected();
	
	/*pUI->PrintMsg("Select the component/connection you want to delete");
	int x, y;
	pUI->GetPointClicked(x, y);
	Component* comp1 = pManager->GetComponentByCordinates(x,y);
	Connection* conn1 = pManager->GetConnByCordinates(x, y);
	while (comp1 == nullptr&& conn1==nullptr) {
		pUI->GetPointClicked(x, y);
		comp1 = pManager->GetComponentByCordinates(x, y);
		conn1 = pManager->GetConnByCordinates(x, y);
	}
	pUI->ClearStatusBar();
	if (comp1 != nullptr) {
		Connection** one = comp1->getTerm1_conns();
		Connection** two = comp1->getTerm2_conns();
		for (int j = 0; j < 20; j++) {
			pManager->DelConn(one[j]);
			pManager->DelConn(two[j]);
		}
		pManager->DelComponent(comp1);
		comp1 = nullptr;
	}
	else if (conn1 != nullptr) {
		
		Component* comp2 = conn1->getComp(1);
		Component* comp3 = conn1->getComp(2);
		comp2->deletecon(conn1);
		comp3->deletecon(conn1);
		pManager->DelConn(conn1);*/

	//}
	
}
void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}