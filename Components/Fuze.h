#ifndef FUZE_H
#define FUZE_H
#include "Component.h"

class Fuze :public Component
{
public:
	Fuze(GraphicsInfo* r_GfxInfo);
	
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	virtual void Load(int Value, string);
	virtual ALLCOMPS whichComponent();
};
#endif
