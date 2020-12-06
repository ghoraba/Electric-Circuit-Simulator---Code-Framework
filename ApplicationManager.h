#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include<fstream>
#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { 
		MaxCompCount = 200,
		MaxConnCount = 1000	};	//Max no of components and connectors


private:
	GraphicsInfo* G;
	bool IsSimulation; // true when in simulation mode
	bool IsSeries;
	int CompCount;		//Actual number of Components
	int ConnCount;		//Actual number of Connections
	int drawningpenwidth;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount];	//List of all Connections (Array of pointers)
	window* pW;
	UI* pUI; //pointer to the UI


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void AddConnection(Connection* pConn);
	void DelSelected();
	void DelComponent(Component* pComp);
	void DelConn(Connection* pConn);
	void DelAll();
	void UnselectAll(Component* pComp);
	void UnselectAll(Connection* pConn);
	void reArrange();
	Component* GetComponentByCordinates(int x, int y); //returns pointer to the component if (x,y) is in the component region
	Connection* GetConnByCordinates(int x, int y);
	// Simulation Mode Functions
	bool ValidateCircuit();
	void ToSimulation(); // Switches to simulation mode
	double CalculateCurrent();
	void CalculateVoltages(double current);
	void Save(fstream& file, string name);
	int ApplicationManager::getCompOrder(Component* comp);
	void Load(fstream& file, string name);	
	//destructor
	~ApplicationManager();
};

#endif