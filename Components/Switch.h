#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual ALLCOMPS whichComponent();
};
