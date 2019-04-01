#include "Application.h"
#include <Windows.h>

std::map<NodeType, std::string> nodeTypeNames;

void InitNodeTypeNames()
{
	nodeTypeNames[NodeType::Entry] = u8"��ʼ";

	nodeTypeNames[NodeType::Selector] = u8"ѡ��ڵ�";
	nodeTypeNames[NodeType::Sequence] = u8"˳��ڵ�";
	nodeTypeNames[NodeType::Parallel] = u8"���нڵ�";
	nodeTypeNames[NodeType::RandomSelector] = u8"���ѡ��ڵ�";
	nodeTypeNames[NodeType::RandomSequence] = u8"���˳��ڵ�";

	nodeTypeNames[NodeType::Repeat] = u8"�ظ��ڵ�";
	nodeTypeNames[NodeType::Success] = u8"�ɹ��ڵ�";
	nodeTypeNames[NodeType::Inverter] = u8"���ڵ�";

	nodeTypeNames[NodeType::PatrolRange] = u8"��ΧѲ��";
}

std::string UTS(const std::string& str)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//һ��Ҫ��1����Ȼ�����β�� 
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = pBuf;

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;
}

std::string STU(const std::string& str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//һ��Ҫ��1����Ȼ�����β��  
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}