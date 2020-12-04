#pragma once
#include "Component.h"

class Buzzer:public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual ALLCOMPS whichComponent();

};
