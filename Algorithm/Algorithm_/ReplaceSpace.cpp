#include "ReplaceSpace.h"
using namespace std;

void ReplaceSpace::Test()
{
	string result= ReplaceSpace1("We Are Happy");
};
//替换空格 
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。（时间复杂度，空间复杂度都是n）
string ReplaceSpace::ReplaceSpace1(string s)
{
	string a;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
			a.append("%20");
		else
		{
			a.append(1,s[i]);
		}
	}
	return a;
}
