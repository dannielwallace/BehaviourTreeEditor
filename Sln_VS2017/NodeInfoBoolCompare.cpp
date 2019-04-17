#include "NodeInfoBoolCompare.h"

NodeInfoBoolCompare::NodeInfoBoolCompare()
	: NodeInfoCompare(NodeType::BoolCompare, u8"����ֵ1", u8"����ֵ2")
{
	v1 = new VariableBool();
	v2 = new VariableBool();
}

const char* NodeInfoBoolCompare::OpComboText() const
{
	return u8"����\0������\0";
}