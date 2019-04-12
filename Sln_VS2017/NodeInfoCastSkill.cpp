#include "NodeInfoCastSkill.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoCastSkill::NodeInfoCastSkill()
	: NodeInfo(NodeType::CastSkill), mSkillID(0)
{

}

void NodeInfoCastSkill::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoPatrolPath");
	FormUtility::FormInt(u8"����ID", &mSkillID);
	FormUtility::FormCheckBox(u8"�Ƿ�ָ��Ŀ��", &mSpecifyTarget);
	if (mSpecifyTarget)
	{
		mSkillTarget.OnInspectorGUI(u8"����Ŀ��", NULL);
	}
	FormUtility::FormCheckBox(u8"�Ƿ��ƶ�Ŀ��λ��", &mSpecifyTargetPos);
	if (mSpecifyTargetPos)
	{
		mSkillTargetPos.OnInspectorGUI(u8"Ŀ��λ��", NULL);
	}
	FormUtility::FormEnd();
}

cJSON* NodeInfoCastSkill::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfo::Save(parentArray);

	cJSON_AddNumberToObject(self, "SkillID", mSkillID);
	cJSON_AddBoolToObject(self, "STarget", mSpecifyTarget);
	cJSON_AddBoolToObject(self, "SPos", mSpecifyTargetPos);
	if (mSpecifyTarget)
	{
		cJSON* targetJson = mSkillTarget.ToJson();
		cJSON_AddItemToObject(self, "Target", targetJson);
	}
	if (mSpecifyTargetPos)
	{
		cJSON* posJson = mSkillTargetPos.ToJson();
		cJSON_AddItemToObject(self, "Pos", posJson);
	}

	return self;
}

void NodeInfoCastSkill::Load(cJSON* self)
{
	NodeInfo::Load(self);

	mSkillID = cJSON_GetObjectItem(self, "SkillID")->valueint;

	mSpecifyTarget = (bool)cJSON_GetObjectItem(self, "STarget")->valueint;
	mSpecifyTargetPos = (bool)cJSON_GetObjectItem(self, "SPos")->valueint;
	if (mSpecifyTarget)
	{
		cJSON* targetJson = cJSON_GetObjectItem(self, "Target");
		mSkillTarget.Load(targetJson);
	}
	if (mSpecifyTargetPos)
	{
		cJSON* posJson = cJSON_GetObjectItem(self, "Pos");
		mSkillTargetPos.Load(posJson);
	}
}