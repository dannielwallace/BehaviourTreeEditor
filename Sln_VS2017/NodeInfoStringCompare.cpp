#include "NodeInfoStringCompare.h"

NodeInfoStringCompare::NodeInfoStringCompare()
	: NodeInfoCompare(NodeType::StringCompare, u8"����1", u8"����2")
{
	v1 = new VariableString();
	v2 = new VariableString();
}

const char* NodeInfoStringCompare::OpComboText() const
{
	return u8"����\0������\0";
}