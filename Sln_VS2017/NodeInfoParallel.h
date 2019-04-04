#pragma once

#include "NodeInfo.h"

enum BTPolicy
{
	RequireOne, // һ���ɹ�/ʧ��
	RequireAll, // ȫ���ɹ�/ʧ��
};

class NodeInfoParallel : public NodeInfo
{
public:
	NodeInfoParallel();

	void OnGUI();
	cJSON* Save(cJSON* parentArray);
	void Load(cJSON* self);
public:
	BTPolicy mSuccessPolicy;
	BTPolicy mFailurePolicy;
};