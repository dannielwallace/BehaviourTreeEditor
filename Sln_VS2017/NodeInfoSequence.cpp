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
	FormUtility::FormCheckBox(u8"ѭ��˳��ִ��", &loop);
	FormUtility::FormEnd();
}

const char* NodeInfoSequence::GetDescription() const
{
	return u8"����ִ�����нڵ㣬ֱ������һ��ʧ����ʧ�ܡ�\n>>���ȫ��ִ�гɹ���ɹ���\n>>���ȫ��ִ��ʧ����ʧ�ܡ�";
}

cJSON* NodeInfoSequence::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	cJSON_AddBoolToObject(self, "Loop", loop);

	SaveChildren(self);

	return self;
}

void NodeInfoSequence::Load(cJSON* self)
{
	NodeInfo::Load(self);

	cJSON* item = cJSON_GetObjectItem(self, "Loop");
	if (item)
	{
		loop = (bool)item->valueint;
	}
}