#include "NodeInfoPatrolRange.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoPatrolRange::NodeInfoPatrolRange()
	: NodeInfo(NodeType::PatrolRange)
{
	range.value = 0.0f;
}

void NodeInfoPatrolRange::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoPatrolRange");
	range.OnInspectorGUI(u8"Ѳ�߷�Χ");
	mCenter.OnInspectorGUI(u8"����λ��");
	FormUtility::FormFloat(u8"��С���ʱ��", &patrolMinInterval);
	FormUtility::FormFloat(u8"�����ʱ��", &patrolMaxInterval);
	FormUtility::FormEnd();
}

cJSON* NodeInfoPatrolRange::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	cJSON* jsonRange = range.ToJson();
	cJSON* jsonCenter = mCenter.ToJson();
	cJSON_AddItemToObject(self, "Range", jsonRange);
	cJSON_AddItemToObject(self, "Center", jsonCenter);
	cJSON_AddDoubleToObject(self, "MinItv", patrolMinInterval);
	cJSON_AddDoubleToObject(self, "MaxItv", patrolMaxInterval);

	return self;
}

void NodeInfoPatrolRange::Load(cJSON* self)
{
	NodeInfo::Load(self);

	cJSON* jsonRange = cJSON_GetObjectItem(self, "Range");
	cJSON* jsonCenter = cJSON_GetObjectItem(self, "Center");
	range.Load(jsonRange);
	mCenter.Load(jsonCenter);
	patrolMinInterval = (float)cJSON_GetObjectItem(self, "MinItv")->valuedouble;
	patrolMaxInterval = (float)cJSON_GetObjectItem(self, "MaxItv")->valuedouble;
}