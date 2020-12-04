#include "Resistor.h"
#include "..\Actions\Action.h"
#include <stdlib.h>
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
Resistor::Resistor(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{
	
	
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}

void Resistor::Draw(UI* pUI)
{
	int xlabel = m_pGfxInfo->PointsList[0].x;
	int ylabel = m_pGfxInfo->PointsList[0].y+50;
	
	pUI->labelMsg(getlabel(), xlabel, ylabel);
	pUI->DrawResistor(*m_pGfxInfo,selected); 
	
	
	
	
}
void Resistor::Operate()
{

}
ALLCOMPS Resistor::whichComponent() {
	return 	RESISTOR;
}