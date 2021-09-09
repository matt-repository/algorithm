#include "JumpFloor.h"

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

void JumpFloor::Test()
{
	int ret= JumpFloor1(7);
}

/// <summary>
/// 经过简单的动态规划，发下 f(n)=f(n-1)+f(n-2) 是斐波那契数列；可以直接用动态规划斐波那契 实现
/// </summary>
/// <param name="number"></param>
/// <returns></returns>
int JumpFloor::JumpFloor1(int number)
{
	if (number <= 3)
		return number;
	int a1 = 2, a2 =3, ret = 5;
	//由于从 4 开始。所以先把a1=JumpFloor1(2) a2=JumpFloor1(3)
	for (int i = 4; i <= number; i++)
	{
		ret = a1 + a2;
		a1 = a2;
		a2 = ret;
	}
	return ret;
}

//这里扩展一下，当可以一次跳3格时，经过动态规划后，发现f（n）=2ⁿ-¹ 