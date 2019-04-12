#include "NodeInfoRandomSelector.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoRandomSelector::NodeInfoRandomSelector()
	: NodeInfoRandom(NodeType::RandomSelector)
{
}

const char* NodeInfoRandomSelector::GetDescription() const
{
	return u8"���ִ��ÿ���ӽڵ㣬ֱ������һ��ִ�гɹ���\n>>���һ��ִ�гɹ���ɹ���\n>>���ȫ��ִ��ʧ����ʧ�ܡ�";
}