#include "NodeInfoWait.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoWait::NodeInfoWait()
	: NodeInfo(NodeType::Wait)
{

}

void NodeInfoWait::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoPatrolPath");
	mRandomWaitTime.OnInspectorGUI(u8"�Ƿ�����ȴ�ʱ��", NULL);
	if (mRandomWaitTime.value)
	{
		mMinWaitTime.OnInspectorGUI(u8"��С�ȴ�ʱ��", NULL);
		mMaxWaitTime.OnInspectorGUI(u8"���ȴ�ʱ��", NULL);
	}
	else
	{
		mWaitTime.OnInspectorGUI(u8"�ȴ�ʱ��", NULL);
	}
	FormUtility::FormEnd();
}

cJSON* NodeInfoWait::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	cJSON_AddItemToObject(self, "Random", mRandomWaitTime.ToJson());
	if (mRandomWaitTime.value)
	{
		cJSON_AddItemToObject(self, "Min", mMinWaitTime.ToJson());
		cJSON_AddItemToObject(self, "Max", mMaxWaitTime.ToJson());
	}
	else
	{
		cJSON_AddItemToObject(self, "Time", mWaitTime.ToJson());
	}

	return self;
}

void NodeInfoWait::Load(cJSON* self)
{
	NodeInfo::Load(self);

	mRandomWaitTime.Load(cJSON_GetObjectItem(self, "Random"));
	if (mRandomWaitTime.value)
	{
		mMinWaitTime.Load(cJSON_GetObjectItem(self, "Min"));
		mMaxWaitTime.Load(cJSON_GetObjectItem(self, "Max"));
	}
	else
	{
		mWaitTime.Load(cJSON_GetObjectItem(self, "Time"));
	}
}