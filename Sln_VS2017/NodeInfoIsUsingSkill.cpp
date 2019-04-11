#include "NodeInfoIsUsingSkill.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoIsUsingSkill::NodeInfoIsUsingSkill()
	: NodeInfoCondition(NodeType::IsUsingSkill), skillID(0)
{

}

void NodeInfoIsUsingSkill::OnGUI()
{
	NodeInfoCondition::OnGUI();

	bool specifySkill = skillID > 0;

	FormUtility::FormBegin("##NodeInfoCondition");
	FormUtility::FormCheckBox(u8"�Ƿ��ڷ�ָ������", &specifySkill);
	if (specifySkill)
	{
		FormUtility::FormInt(u8"����ID", &skillID);
	}
	FormUtility::FormEnd();

	if (skillID <= 0 && specifySkill)
	{
		skillID = 1;
	}
	if (skillID > 0 && !specifySkill)
	{
		skillID = 0;
	}

	ImGui::Separator();
}

const char* NodeInfoIsUsingSkill::GetDescription() const
{
	return u8"��ɫ�Ƿ���ִ�м��ܻ���ĳ���ض����ܡ�";
}

cJSON* NodeInfoIsUsingSkill::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfoCondition::Save(parentArray);

	cJSON_AddNumberToObject(self, "SkillID", skillID);

	return self;
}

void NodeInfoIsUsingSkill::Load(cJSON* self)
{
	NodeInfoCondition::Load(self);

	skillID = cJSON_GetObjectItem(self, "SkillID")->valueint;
}