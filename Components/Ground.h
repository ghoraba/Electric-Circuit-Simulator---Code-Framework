#ifndef GROUND_H
#define GROUND_H
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

#endif
