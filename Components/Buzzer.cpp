#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	//int xlabel = m_pGfxInfo->PointsList[0].x;
	//int ylabel = m_pGfxInfo->PointsList[0].y + 50;
	//pUI->labelMsg("Buzzer", xlabel, ylabel);
	pUI->DrawBuzzer(*m_pGfxInfo,selected); //update to draw resistor

}

void Buzzer::Operate()
{

}
ALLCOMPS Buzzer::whichComponent() {
	return BUZZER;
}