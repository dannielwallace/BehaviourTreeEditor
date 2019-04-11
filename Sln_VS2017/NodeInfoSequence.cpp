#include "NodeInfoSequence.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoSequence::NodeInfoSequence()
	: NodeInfo(NodeType::Sequence)
{
}

void NodeInfoSequence::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoSequence");
	FormUtility::FormEnd();
}

const char* NodeInfoSequence::GetDescription() const
{
	return u8"����ִ�����нڵ㣬ֱ������һ��ʧ����ʧ�ܡ�\n>>���ȫ��ִ�гɹ���ɹ���\n>>���ȫ��ִ��ʧ����ʧ�ܡ�";
}

cJSON* NodeInfoSequence::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	SaveChildren(self);

	return self;
}