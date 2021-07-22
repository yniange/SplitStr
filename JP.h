#pragma once

//将一个字符串（string对象，形参1）以指
//定字符为分隔符（默认为逗号','形参2），
//切分为若干个字串，返回存放字串的容器。
//如果源字符串中连续出现两个分隔符，则
//认为这两个分隔符之间包含了一个" "子串
//（即包含一个空格的字符串）。如果分隔
//符在源字符串的开头或末尾，同样认为开
//头或末尾处有一个" "子串。
#include <vector>
#include <string>

class JP
{
public:
	//迭代器版本
	static std::vector<std::string> SplitStr(
		std::string strSource, char cDelim = ',');
	//下标版本
	static std::vector<std::string> SplitStrIndex(
		std::string strSource, char cDelim = ',');
	//sstream版本，最简单版本
	static std::vector<std::string> SplitString(
		std::string strSource, char cDelim = ',');
};

const int LineMaxLen{ 1024 };//子串最大长度
