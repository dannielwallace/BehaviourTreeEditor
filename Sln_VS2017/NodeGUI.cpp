#include "NodeGUI.h"
#include "EDNode.h"
#include "FormUtility.h"
#include "NodeInfos.h"
#include "Variables.h"

namespace ed = ax::NodeEditor;
FindNodeFunc findNodeFunc = NULL;
CreateNodeFunc createParentNodeFunc = NULL;
CreateNodeFunc createChildNodeFunc = NULL;

void SetCreateParentNodeFunc(CreateNodeFunc func)
{
	createParentNodeFunc = func;
}

void SetCreateChildNodeFunc(CreateNodeFunc func)
{
	createChildNodeFunc = func;
}

void SetNodeFindFunc(FindNodeFunc func)
{
	findNodeFunc = func;
}

EDNode* CreateNode(NodeType nodeType)
{
	auto it = nodeTypeNames.find(nodeType);
	if (it == nodeTypeNames.end())
	{
		return NULL;
	}

	EDNode* node = NULL;
	switch (nodeType)
	{
	case NodeType::Selector:
	{
		node = createParentNodeFunc(it->second.c_str());
		node->nodeInfo = new NodeInfoSelector();
	}
	break;
	case NodeType::Sequence:
	{
		node = createParentNodeFunc(it->second.c_str());
		node->nodeInfo = new NodeInfoSequence();
	}
	break;
	case NodeType::Parallel:
	{
		node = createParentNodeFunc(it->second.c_str());
		node->nodeInfo = new NodeInfoParallel();
	}
	break;
	}
	return node;
}

void OnInspector()
{
	std::vector<ed::NodeId> selectedNodes;
	selectedNodes.resize(ed::GetSelectedObjectCount());
	int nodeCount = ed::GetSelectedNodes(selectedNodes.data(), static_cast<int>(selectedNodes.size()));
	selectedNodes.resize(nodeCount);

	if (nodeCount > 0)
	{
		ed::NodeId curNodeId = selectedNodes[0];
		EDNode* node = findNodeFunc(curNodeId);
		if (node == NULL)
			return;

		if (node->nodeInfo != NULL)
		{
			node->nodeInfo->OnGUI();
		}
	}
}

void OnVarialbleGUI(std::vector<Variable*>& vars)
{
	FormUtility::FormBegin("##VarialbleGUI");

	FormUtility::FormLabelText(u8"��ʾ", u8"�ݲ�֧����������");

	static VariableType type;
	FormUtility::FormCombo(u8"��������", (int*)&type, g_VariableTypeTxts);

	static char variableName[128] = "";
	FormUtility::FormInputText(u8"��������", variableName, 128);

	FormUtility::FormEnd();

	if (ImGui::Button(u8"��ӱ���"))
	{
		Variable* var = NULL;
		switch (type)
		{
		case VariableType::Bool:
		{
			var = new VariableBool();
		}
		break;
		case VariableType::Float:
		{
			var = new VariableFloat();
		}
		break;
		case VariableType::Int:
		{
			var = new VariableInt();
		}
		break;
		case VariableType::String:
		{
			var = new VariableString();
		}
		break;
		case VariableType::Vector2:
		{
			var = new VariableVector2();
		}
		break;
		case VariableType::Vector3:
		{
			var = new VariableVector3();
		}
		break;
		case VariableType::Vector4:
		{
			var = new VariableVector4();
		}
		break;
		case VariableType::Charactor:
		{
			var = new VariableCharactor();
		}
		break;
		case VariableType::Npc:
		{
			var = new VariableNpc();
		}
		break;
		case VariableType::NeutralNpc:
		{
			var = new VariableNeutralNpc();
		}
		break;
		case VariableType::Player:
		{
			var = new VariablePlayer();
		}
		break;
		case VariableType::Monster:
		{
			var = new VariableMonster();
		}
		break;
		}
		var->name = variableName;
		vars.push_back(var);
	}

	ImGui::Separator();

	FormUtility::FormBegin("##VarialbleGUI1");
	for (auto it = vars.begin(); it != vars.end(); ++it)
	{
		Variable* var = *it;
		if (var == NULL)
			continue;
		if (!var->OnGUI())
		{
			vars.erase(it);
			break;
		}
	}
	FormUtility::FormEnd();
}