#include "JP.h"

std::vector<std::string> JP::SplitStr(std::string sourcestr, char sep)
{
	std::vector<std::string> resultarray;//�����洢���н������������ַ���
	std::string strtmp;	//�����������ַ���

	//PrevC�ڱ���Դ�ַ���ʱ��¼������ǰ�ַ�������ʶ������������
	//�����Ƿָ��ַ������
	char PrevC = '\0';
	for (auto itc = sourcestr.begin(); itc < sourcestr.end(); ++itc)
	{//itc������������ָ��Դ�ַ����е��ַ�
		if (sep == (*itc))//�����ָ��ַ�
		{
			if (itc == sourcestr.begin())
			{
				resultarray.push_back(" ");
			}
			else
			{
				if (PrevC != sep)//���ǰһ���ַ����Ƿָ��ַ�
				{//��ǰstrtmp�洢����һ����Ч���ַ���������ѹ��resultarray
					resultarray.push_back(strtmp);
				}
				else
				{//���ǰһ���ַ�Ҳ�Ƿָ��ַ�����Ӧ����resultarrayѹ����һ����
				 //�񹹳ɵ��ַ���
					resultarray.push_back(" ");
				}
			}
			strtmp.clear();	//��strtmp��գ�׼��������һ���Ӵ����ַ�
		}
		else
		{//��ǰ�ַ����Ƿָ��ַ�������ѹ��strtmp��
			strtmp.push_back(*itc);
		}
		PrevC = (*itc);//��¼�µ�ǰ�ַ�
	}
	if (strtmp.empty())//forѭ�����������strtmp��û���ַ�������ζ��
	{//Դ�ַ������Էָ��ַ�����β�ģ����ƿ��ַ���,��ʱ��strtmp��Ϊ�ո�
	 //�ַ���������������һ��ֻ��һ���ո񹹳ɵ��ַ�����
		strtmp = " ";
	}
	resultarray.push_back(strtmp);	//�����һ���ָ��ַ�����Ӵ�ѹ��resultarray

	return resultarray;//���洢�������Ӵ���resultarray����
}

//�±�汾
std::vector<std::string> JP::SplitString(std::string SourceStr, char sep)
{
	std::vector<std::string> ResultArray;//�����洢���н������������ַ���
	int len = static_cast<int>(SourceStr.size());
	std::string strtmp = "";
	char PrevC = '\0';
	for (int i = 0; i < len; ++i)
	{
		if (SourceStr[i] == sep)
		{
			if (0 == i)
			{
				ResultArray.push_back(" ");
			}
			else
			{
				if (PrevC != sep)
				{
					ResultArray.push_back(strtmp);
				}
				else
				{
					ResultArray.push_back(" ");
				}
			}
			strtmp.clear();
		}
		else
		{
			strtmp.push_back(SourceStr[i]);
		}
		PrevC = SourceStr[i];
	}

	if (strtmp.empty())//forѭ�����������strtmp��û���ַ�������ζ��
	{//Դ�ַ������Էָ��ַ�����β�ģ����ƿ��ַ���,��ʱ��strtmp��Ϊ�ո�
	 //�ַ���������������һ��ֻ��һ���ո񹹳ɵ��ַ�����
		strtmp = " ";
	}
	ResultArray.push_back(strtmp);	//�����һ���ָ��ַ�����Ӵ�ѹ��ResultArray

	return ResultArray;//���洢�������Ӵ���ResultArray����
}