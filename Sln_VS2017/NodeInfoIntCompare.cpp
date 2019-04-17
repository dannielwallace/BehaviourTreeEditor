#include "NodeInfoIntCompare.h"

NodeInfoIntCompare::NodeInfoIntCompare()
	: NodeInfoCompare(NodeType::IntCompare, u8"����1", u8"����2")
{
	v1 = new VariableInt();
	v2 = new VariableInt();
}

const char* NodeInfoIntCompare::OpComboText() const
{
	return u8"����\0������\0С��\0С�ڵ���\0����\0���ڵ���\0";
}