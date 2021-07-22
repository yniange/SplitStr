#include "JP.h"
#include <sstream>

//迭代器版本
std::vector<std::string> JP::SplitStr(std::string strSource, char cDelim)
{
	std::vector<std::string> resultarray;//用来存储所有解析出来的子字符串
	std::string strtmp;	//用来接收子字符串

	//PrevC在遍历源字符串时记录下来当前字符，用来识别连续两个字
	//符都是分隔字符的情况
	char PrevC = '\0';
	for (auto itc = strSource.begin(); itc < strSource.end(); ++itc)
	{//itc迭代器，依次指向源字符串中的字符
		if (cDelim == (*itc))//遇到分隔字符
		{
			if (itc == strSource.begin())
			{
				resultarray.push_back(" ");
			}
			else
			{
				if (PrevC != cDelim)//如果前一个字符不是分隔字符
				{//则当前strtmp存储的是一个有效的字符串，将其压入resultarray
					resultarray.push_back(strtmp);
				}
				else
				{//如果前一个字符也是分隔字符，则应该往resultarray压入由一个空
				 //格构成的字符串
					resultarray.push_back(" ");
				}
			}
			strtmp.clear();	//将strtmp清空，准备接收下一个子串的字符
		}
		else
		{//当前字符不是分隔字符，则将其压入strtmp中
			strtmp.push_back(*itc);
		}
		PrevC = (*itc);//记录下当前字符
	}
	if (strtmp.empty())//for循环结束后，如果strtmp中没有字符，则意味着
	{//源字符串是以分隔字符串结尾的（不计空字符）,此时将strtmp置为空格
	 //字符串，即在最后添加一个只有一个空格构成的字符串。
		strtmp = " ";
	}
	resultarray.push_back(strtmp);	//将最后一个分隔字符后的子串压入resultarray

	return resultarray;//将存储了所有子串的resultarray返回
}

//下标版本
std::vector<std::string> JP::SplitStrIndex(std::string strSource, char cDelim)
{
	std::vector<std::string> ResultArray;//用来存储所有解析出来的子字符串
	int len = static_cast<int>(strSource.size());
	std::string strtmp = "";
	char PrevC = '\0';
	for (int i = 0; i < len; ++i)
	{
		if (strSource[i] == cDelim)
		{
			if (0 == i)
			{
				ResultArray.push_back(" ");
			}
			else
			{
				if (PrevC != cDelim)
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
			strtmp.push_back(strSource[i]);
		}
		PrevC = strSource[i];
	}

	if (strtmp.empty())//for循环结束后，如果strtmp中没有字符，则意味着
	{//源字符串是以分隔字符串结尾的（不计空字符）,此时将strtmp置为空格
	 //字符串，即在最后添加一个只有一个空格构成的字符串。
		strtmp = " ";
	}
	ResultArray.push_back(strtmp);	//将最后一个分隔字符后的子串压入ResultArray

	return ResultArray;//将存储了所有子串的ResultArray返回
}

//sstream版本
std::vector<std::string> JP::SplitString(std::string strSource, char cDelim)
{
	std::vector<std::string> vSegment;
	std::stringstream ssStr(strSource);
	std::string str;
	char aSegment[LineMaxLen];
	while (ssStr.getline(aSegment, LineMaxLen, cDelim))
	{
		str = aSegment;
		vSegment.push_back(str);
	}
	if (*(strSource.end() - 1) == cDelim)
		vSegment.push_back("");

	return vSegment;
}
