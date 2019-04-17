#include "NodeInfoFloatCompare.h"

NodeInfoFloatCompare::NodeInfoFloatCompare()
	: NodeInfoCompare(NodeType::IntCompare, u8"������1", u8"������2")
{
	v1 = new VariableFloat();
	v2 = new VariableFloat();
}

const char* NodeInfoFloatCompare::OpComboText() const
{
	return u8"����\0������\0С��\0С�ڵ���\0����\0���ڵ���\0";
}