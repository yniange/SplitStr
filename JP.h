#pragma once

//��һ���ַ�����string�����β�1����ָ
//���ַ�Ϊ�ָ�����Ĭ��Ϊ����','�β�2����
//�з�Ϊ���ɸ��ִ������ش���ִ���������
//���Դ�ַ������������������ָ�������
//��Ϊ�������ָ���֮�������һ��" "�Ӵ�
//��������һ���ո���ַ�����������ָ�
//����Դ�ַ����Ŀ�ͷ��ĩβ��ͬ����Ϊ��
//ͷ��ĩβ����һ��" "�Ӵ���
#include <vector>
#include <string>

class JP
{
public:
	//�������汾
	static std::vector<std::string> SplitStr(
		std::string sourcestr, char sep = ',');
	//�±�汾
	static std::vector<std::string> SplitString(
		std::string SourceStr, char sep = ',');
};

