#include "NodeInfoSequence.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoSequence::NodeInfoSequence()
	: NodeInfo(NodeType::Sequence),
	mAbortType(AbortType::None)
{
	mAbortTxt = u8"��\0�Դ��\0��ϵ����ȼ�";
}

void NodeInfoSequence::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoSequence");
	FormUtility::FormCombo(u8"�������", (int*)&mAbortType, mAbortTxt);
	FormUtility::FormEnd();
}