#pragma once
#include "Component.h"

class Bulb :public Component {
public:
	Bulb(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the Bulb
	virtual void Operate();
	virtual ALLCOMPS Bulb::whichComponent();
};