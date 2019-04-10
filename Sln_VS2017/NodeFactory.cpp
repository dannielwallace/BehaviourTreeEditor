#include "NodeFactory.h"
#include "NodeInfos.h"
#include "EDNode.h"

#define DefCreateNodeFunc(className) EDNode* Create##className(const char* name, int childCount)\
	{\
		EDNode* node = NULL;\
		if (childCount == 0)\
		{\
			node = createLeafNodeFunc(name);\
		}\
		else if (childCount < 0)\
		{\
			node = createRootNodeFunc(name);\
		}\
		else\
		{\
			node = createParentNodeFunc(name);\
		}\
		node->nodeInfo = new className();\
		node->maxOutput = abs(childCount);\
		return node;\
	}

#define AddCreateNodeFunc(nodeType, className, name, childCount) createEDNodeFunc[nodeType] = Create##className;\
	nodeTypeNames[nodeType] = u8###name;\
	nodeChildCounts[nodeType] = childCount;

std::map<NodeType, std::string> nodeTypeNames;
std::map<NodeType, CreateEDNodeFunc> createEDNodeFunc;
std::map<NodeType, int> nodeChildCounts;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ���Ͻڵ�;
DefCreateNodeFunc(NodeInfoSelector)
DefCreateNodeFunc(NodeInfoActiveSelector)
DefCreateNodeFunc(NodeInfoSequence)
DefCreateNodeFunc(NodeInfoParallel)
// ���νڵ�;
// �����ڵ�;
// ��Ϊ�ڵ�;
DefCreateNodeFunc(NodeInfoPatrolRange)
DefCreateNodeFunc(NodeInfoPatrolPath)
DefCreateNodeFunc(NodeInfoSearchTarget)

void InitCreateNodeInfo()
{
	AddCreateNodeFunc(NodeType::Entry,				NodeInfoSelector,			��ʼ,						-1);

	AddCreateNodeFunc(NodeType::Selector,			NodeInfoSelector,			ѡ��ڵ�,					INT_MAX);
	AddCreateNodeFunc(NodeType::ActiveSelector,		NodeInfoActiveSelector,		����ѡ��ڵ�,				INT_MAX);
	AddCreateNodeFunc(NodeType::Sequence,			NodeInfoSequence,			˳��ڵ�,					INT_MAX);
	AddCreateNodeFunc(NodeType::Parallel,			NodeInfoParallel,			���нڵ�,					INT_MAX);

	AddCreateNodeFunc(NodeType::PatrolRange,		NodeInfoPatrolRange,		��ΧѲ��,					0);
	AddCreateNodeFunc(NodeType::PatrolPath,			NodeInfoPatrolPath,			·��Ѳ��,					0);
	AddCreateNodeFunc(NodeType::SearchTarget,		NodeInfoSearchTarget,		��ѰĿ��,					0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////