#include "NodeInfoSelector.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoSelector::NodeInfoSelector()
	: NodeInfo(NodeType::Selector)
{
}

void NodeInfoSelector::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoSelector");
	FormUtility::FormEnd();
}

const char* NodeInfoSelector::GetDescription() const
{
	return u8"����ִ��ÿ���ӽڵ㣬ֱ������һ��ִ�гɹ�\n���ȫ��ִ��ʧ����ʧ��";
}

cJSON* NodeInfoSelector::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	SaveChildren(self);

	return self;
}