#include "NodeInfoParallel.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoParallel::NodeInfoParallel()
	: NodeInfo(NodeType::Parallel)
{
	mSuccessPolicy = BTPolicy::RequireOne;
	mFailurePolicy = BTPolicy::RequireOne;
}

void NodeInfoParallel::OnGUI()
{
	NodeInfo::OnGUI();

	const char* successPolicy = u8"һ���ɹ��ͳɹ�\0ȫ���ɹ��ųɹ�\0";
	const char* failurePolicy = u8"һ��ʧ�ܾ�ʧ��\0ȫ��ʧ�ܾ�ʧ��\0";

	FormUtility::FormBegin("##NodeInfoSequence");
	FormUtility::FormCombo(u8"�ɹ�����", (int*)&mSuccessPolicy, successPolicy);
	FormUtility::FormCombo(u8"ʧ�ܲ���", (int*)&mFailurePolicy, failurePolicy);
	FormUtility::FormEnd();
}

const char* NodeInfoParallel::GetDescription() const
{
	return u8"����ӽڵ���Ϊ����ִ�С�\n>>��Ҫ�Զ���ɹ�/ʧ�ܹ���";
}

cJSON* NodeInfoParallel::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	cJSON_AddNumberToObject(self, "SuccessPolicy", (int)mSuccessPolicy);
	cJSON_AddNumberToObject(self, "FailurePolicy", (int)mFailurePolicy);

	SaveChildren(self);

	return self;
}

void NodeInfoParallel::Load(cJSON* self)
{
	NodeInfo::Load(self);

	mSuccessPolicy = (BTPolicy)cJSON_GetObjectItem(self, "SuccessPolicy")->valueint;
	mFailurePolicy = (BTPolicy)cJSON_GetObjectItem(self, "FailurePolicy")->valueint;
}