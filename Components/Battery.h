#pragma once
#include "Component.h"

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load(int Value,string Label);
	virtual ALLCOMPS whichComponent();
};
