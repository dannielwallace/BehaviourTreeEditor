#include "NodeInfoSearchTarget.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoSearchTarget::NodeInfoSearchTarget()
	: NodeInfo(NodeType::SearchTarget)
{

}

void NodeInfoSearchTarget::OnGUI()
{
	NodeInfo::OnGUI();

	const char* searchTargetType = u8"����\0������Ѱ�ж�\0������Ѱ�ѷ�";
	const char* searchTargetCondition = u8"���\0��Զ\0��߳��\0��ͳ��\0����ֵС��\0����ֵ����\0���";

	FormUtility::FormBegin("##NodeInfoSearchTarget");
	FormUtility::FormCombo(u8"��Ѱ����", (int*)&mSearchTargetType, searchTargetType);
	FormUtility::FormCombo(u8"��Ѱ����", (int*)&mSearchTargetCondition, searchTargetCondition);
	mSearchDist.OnInspectorGUI(u8"��Ѱ��Χ");
	FormUtility::FormEnd();
}

cJSON* NodeInfoSearchTarget::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	cJSON_AddNumberToObject(self, "SearchTargetType", (int)mSearchTargetType);
	cJSON_AddNumberToObject(self, "SearchTargetCondition", (int)mSearchTargetCondition);
	cJSON* jsonSearchDist = mSearchDist.ToJson();
	cJSON_AddItemToObject(self, "SearchDist", jsonSearchDist);

	return self;
}

void NodeInfoSearchTarget::Load(cJSON* self)
{
	NodeInfo::Load(self);

	mSearchTargetType = (SearchTargetType)cJSON_GetObjectItem(self, "SearchTargetType")->valueint;
	mSearchTargetCondition = (SearchTargetCondition)cJSON_GetObjectItem(self, "SearchTargetCondition")->valueint;
	cJSON* jsonSearchDist = cJSON_GetObjectItem(self, "SearchDist");
	mSearchDist.Load(jsonSearchDist);
}