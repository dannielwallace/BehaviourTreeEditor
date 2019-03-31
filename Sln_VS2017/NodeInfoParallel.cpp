#include "NodeInfoParallel.h"
#include "EDNode.h"
#include "FormUtility.h"

namespace ed = ax::NodeEditor;

NodeInfoParallel::NodeInfoParallel()
	: NodeInfo(NodeType::Parallel),
	mAbortType(AbortType::None)
{
	mAbortTxt = u8"��\0�Դ��\0��ϵ����ȼ�";
}

void NodeInfoParallel::OnGUI()
{
	NodeInfo::OnGUI();

	FormUtility::FormBegin("##NodeInfoSequence");
	FormUtility::FormCombo(u8"�������", (int*)&mAbortType, mAbortTxt);
	FormUtility::FormEnd();
}