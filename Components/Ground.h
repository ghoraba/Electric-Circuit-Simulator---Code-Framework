#pragma once
#include "Component.h"

class Ground :public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual ALLCOMPS whichComponent();
};
#pragma once
