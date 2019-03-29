#include "NodeInfoSelector.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoSelector::NodeInfoSelector()
	: NodeInfo(NodeType::Selector),
	mAbortType(AbortType::None)
{
	mAbortTxt = u8"��\0�Դ��\0��ϵ����ȼ�";
}

void NodeInfoSelector::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoSelector");
	FormUtility::FormCombo(u8"�������", (int*)&mAbortType, mAbortTxt);
	FormUtility::FormEnd();
}