#pragma once

#include "Component.h"

class Fuze :public Component
{
public:
	Fuze(GraphicsInfo* r_GfxInfo);
	
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual ALLCOMPS whichComponent();
};
