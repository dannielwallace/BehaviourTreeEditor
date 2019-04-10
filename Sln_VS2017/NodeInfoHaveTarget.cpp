#include "NodeInfoHaveTarget.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoHaveTarget::NodeInfoHaveTarget()
	: NodeInfoCondition(NodeType::HaveTarget), targetType(BTTargetType::All)
{

}

void NodeInfoHaveTarget::OnGUI()
{
	NodeInfoCondition::OnGUI();

	const char* targetTypeDesc = u8"���н�ɫ\0�ѷ�\0�з�";

	FormUtility::FormBegin("##NodeInfoCondition");
	FormUtility::FormCombo(u8"Ŀ������", (int*)&targetType, targetTypeDesc);
	FormUtility::FormEnd();

	ImGui::Separator();
}

cJSON* NodeInfoHaveTarget::Save(cJSON* parentArray)
{
	cJSON* self = NodeInfoCondition::Save(parentArray);

	cJSON_AddNumberToObject(self, "TargetType", targetType);

	return self;
}

void NodeInfoHaveTarget::Load(cJSON* self)
{
	NodeInfoCondition::Load(self);

	targetType = (BTTargetType)cJSON_GetObjectItem(self, "TargetType")->valueint;
}