#include "NodeInfoPatrolPath.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoPatrolPath::NodeInfoPatrolPath()
	: NodeInfo(NodeType::PatrolPath), patrolType(PatrolPathType::Once)
{

}

void NodeInfoPatrolPath::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoPatrolPath");
	const char* comboTxt = u8"����\0ƹ��\0ѭ��";
	FormUtility::FormCombo(u8"Ѳ�߷�ʽ", (int*)&patrolType, comboTxt);
	pathName.OnInspectorGUI(u8"Ѳ��·����", NULL);
	FormUtility::FormEnd();
}

cJSON* NodeInfoPatrolPath::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	cJSON_AddNumberToObject(self, "PatrolPathType", (int)patrolType);
	cJSON* jsonPathName = pathName.ToJson();
	cJSON_AddItemToObject(self, "PathName", jsonPathName);

	return self;
}

void NodeInfoPatrolPath::Load(cJSON* self)
{
	NodeInfo::Load(self);

	patrolType = (PatrolPathType)cJSON_GetObjectItem(self, "PatrolPathType")->valueint;

	cJSON* jsonPathName = cJSON_GetObjectItem(self, "PathName");
	pathName.Load(jsonPathName);
}