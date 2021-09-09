#include "NumberOf1.h"
using namespace std;
//二进制中1的个数

 /// <summary>
 /// 输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
 /// </summary>
void NumberOf1::Test()
{
		int x = 0b01; //二进制
		int y = 074; //八进制
		int s = 74; // 十进制
		int z = 0x74;//十六进制
		int ss = 0x01;
		cout << y << endl;
	 auto ret = NumberOf1_1(1);
	  ret = NumberOf1_1(10);
	  ret = NumberOf1_1(0);
	  ret = NumberOf1_1(-1);
	  ret = NumberOf1_1(-9);
}

/// <summary>
/// 考虑正负数都可以 一个个进行 & &32次；
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int   NumberOf1::NumberOf1_1(int n)
{
	int count = 0;
	int maxIndex = 1;
	while (maxIndex != 0)
	{
		if (n & maxIndex)
			count++;
		maxIndex <<= 1;

	}
	return count;
}

/// <summary>
/// 巧妙算法，n & (n - 1)  一次除掉一个 1 ；并且获取除去后的所有1； 当为负数也可以；大大减少了时间复杂度
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int   NumberOf1::NumberOf1_2(int n)
{

	int count = 0;
	while (n != 0)
	{
		count++;
		n = n & (n - 1);

	}
	return count;
}