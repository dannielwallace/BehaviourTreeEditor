#include "Application.h"
#include <Windows.h>

std::map<NodeType, std::string> nodeTypeNames;

void InitNodeTypeNames()
{
	nodeTypeNames[NodeType::Entry] = u8"��ʼ";

	nodeTypeNames[NodeType::Selector] = u8"ѡ��ڵ�";
	nodeTypeNames[NodeType::Sequence] = u8"˳��ڵ�";
	nodeTypeNames[NodeType::Parallel] = u8"���нڵ�";
	nodeTypeNames[NodeType::RandomSelector] = u8"���ѡ��ڵ�";
	nodeTypeNames[NodeType::RandomSequence] = u8"���˳��ڵ�";

	nodeTypeNames[NodeType::Repeat] = u8"�ظ��ڵ�";
	nodeTypeNames[NodeType::Success] = u8"�ɹ��ڵ�";
	nodeTypeNames[NodeType::Inverter] = u8"���ڵ�";
}