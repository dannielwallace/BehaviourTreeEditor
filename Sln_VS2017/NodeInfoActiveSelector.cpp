#include "NodeInfoActiveSelector.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoActiveSelector::NodeInfoActiveSelector()
	: NodeInfo(NodeType::ActiveSelector)
{
}

void NodeInfoActiveSelector::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoSequence");
	FormUtility::FormEnd();
}

const char* NodeInfoActiveSelector::GetDescription() const
{
	return u8"����ִ�����нڵ㣬ֱ������һ��ʧ����ʧ�ܡ�\n>>���ȫ��ִ�гɹ���ɹ���\n>>���ȫ��ִ��ʧ����ʧ�ܡ�\n���[���ȼ����ߵĽڵ�]ִ�гɹ�����[��ǰִ�еĽڵ�]ִ��ʧ�ܣ�����ִֹ��[��ǰִ�еĽڵ�]��";
}

cJSON* NodeInfoActiveSelector::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	SaveChildren(self);

	return self;
}