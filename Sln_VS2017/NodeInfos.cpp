#include "NodeInfos.h"
#include "EDNode.h"

CreateNodeFunc createParentNodeFunc = NULL;
CreateNodeFunc createChildNodeFunc = NULL;

void SetCreateParentNodeFunc(CreateNodeFunc func)
{
	createParentNodeFunc = func;
}

void SetCreateChildNodeFunc(CreateNodeFunc func)
{
	createChildNodeFunc = func;
}

void InitNodeTypeNames()
{
	nodeTypeNames[NodeType::Entry] = u8"��ʼ";

	nodeTypeNames[NodeType::Selector] = u8"ѡ��ڵ�";
	nodeTypeNames[NodeType::ActiveSelector] = u8"����ѡ��ڵ�";
	nodeTypeNames[NodeType::Sequence] = u8"˳��ڵ�";
	nodeTypeNames[NodeType::Parallel] = u8"���нڵ�";
	nodeTypeNames[NodeType::RandomSelector] = u8"���ѡ��ڵ�";
	nodeTypeNames[NodeType::RandomSequence] = u8"���˳��ڵ�";

	nodeTypeNames[NodeType::Repeat] = u8"�ظ��ڵ�";
	nodeTypeNames[NodeType::Success] = u8"�ɹ��ڵ�";
	nodeTypeNames[NodeType::Inverter] = u8"���ڵ�";

	nodeTypeNames[NodeType::PatrolRange] = u8"��ΧѲ��";
	nodeTypeNames[NodeType::PatrolPath] = u8"·��Ѳ��";
	nodeTypeNames[NodeType::SearchTarget] = u8"��ѰĿ��";
}

EDNode* CreateNode(NodeType nodeType, const char* name)
{
	EDNode* node = NULL;
	switch (nodeType)
	{
	case NodeType::Selector:
	{
		node = createParentNodeFunc(name);
		node->nodeInfo = new NodeInfoSelector();
	}
	break;
	case NodeType::Sequence:
	{
		node = createParentNodeFunc(name);
		node->nodeInfo = new NodeInfoSequence();
	}
	break;
	case NodeType::Parallel:
	{
		node = createParentNodeFunc(name);
		node->nodeInfo = new NodeInfoParallel();
	}
	break;
	case NodeType::PatrolRange:
	{
		node = createChildNodeFunc(name);
		node->nodeInfo = new NodeInfoPatrolRange();
	}
	break;
	case NodeType::PatrolPath:
	{
		node = createChildNodeFunc(name);
		node->nodeInfo = new NodeInfoPatrolPath();
	}
	break;
	case NodeType::SearchTarget:
	{
		node = createChildNodeFunc(name);
		node->nodeInfo = new NodeInfoSearchTarget();
	}
	break;
	case NodeType::ActiveSelector:
	{
		node = createParentNodeFunc(name);
		node->nodeInfo = new NodeInfoActiveSelector();
	}
	break;
	}
	if (node->nodeInfo)
	{
		node->nodeInfo->mNode = node;
	}
	return node;
}