#include "NodeInfoCharacterCompare.h"

NodeInfoCharacterCompare::NodeInfoCharacterCompare()
	: NodeInfoCompare(NodeType::CharacterCompare, u8"��ɫ1", u8"��ɫ2")
{
	v1 = new VariableCharacter();
	v2 = new VariableCharacter();
}

const char* NodeInfoCharacterCompare::OpComboText() const
{
	return u8"����\0������\0";
}