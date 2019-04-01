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