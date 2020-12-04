#include "Connection.h"

Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Comp1 = cmp1;
	Comp2 = cmp2;
	selected = false;
}
void Connection::Draw(UI* pUI)
{
	
	pUI->DrawConnection(*pGfxInfo,selected);
}
double Connection::lineslope() {
	double x1 = pGfxInfo->PointsList[0].x;
	double x2 = pGfxInfo->PointsList[1].x;
	double y1 = pGfxInfo->PointsList[0].y;
	double y2 = pGfxInfo->PointsList[1].y;
	
		return ((y2 - y1) / (x2 - x1));
}
Component* Connection::getComp(int n) {
	switch (n) {
	case 1:
		return Comp1;
		break;
	case 2:
		return Comp2;
		break;
	default:
		return nullptr;
	}
	
}
bool Connection::isSelected() {

	return selected;
}
void Connection::Selection() {
	if (selected == false)
		selected = true;
	else
		selected = false;
}
void Connection::unSelect() {
	selected = false;
}
GraphicsInfo* Connection::getgraphics() const {
	return pGfxInfo;
}