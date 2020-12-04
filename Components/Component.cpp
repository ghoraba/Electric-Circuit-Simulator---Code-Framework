#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
}
void Component::addTerm1Conn(Connection* c) {
	term1_conns[term1_conn_count++] = c;
}
void Component::addTerm2Conn(Connection* c) {
	term2_conns[term2_conn_count++] = c;
}
//Connection** Component::getTerm1_conns() {
//	return term1_conns;
//}
//Connection** Component::getTerm2_conns() {
//	return term2_conns;
//}
Connection** Component::getTermConnections(TerminalNum Term) {
	switch (Term) {
	case TERM1:
		return term1_conns;
		break;
	case TERM2:
		return term2_conns;
		break;
	default:
		return nullptr;
	}
		
}
void Component::setlabel(string s)  {
	m_Label = s;
}
string Component::getlabel()const {
	return m_Label;
}
void Component::setresistance(double R) {
	resistance = R;
}
int Component::getCompCenterX(UI* pUI) {
	return m_pGfxInfo->PointsList[0].x+pUI->getCompWidth()/2;
}
int Component::getCompCenterY(UI* pUI) {
	return m_pGfxInfo->PointsList[0].y+pUI->getCompHeight()/2;
}
void Component::deletecon(Connection* pCon) {
	for (int i = 0; i < term1_conn_count; i++) {
		if (term1_conns[i] == pCon)
			term1_conns[i] = nullptr;
	}
	for (int i = 0; i < term2_conn_count; i++) {
		if (term2_conns[i] == pCon)
			term2_conns[i] = nullptr;
	}
}
bool Component::isSelected() {
	
	return selected;
}
void Component::Selection() {
	if (selected == false)
		selected = true;
	else
		selected = false;
}
void Component::unSelect() {
	selected = false;
}
string Component::getLabel() {
	return m_Label;
}
int Component::getResistance() {
	return resistance;
}
Component::~Component()
{
	/*for (int i = 0; i < term1_conn_count; i++) {
		delete term1_conns[i];
		term1_conns[i] = nullptr;
	}
	for (int i = 0; i < term1_conn_count; i++) {
		delete	term2_conns[i];	
		term1_conns[i] = nullptr;
	}*/

}
