#include "RectCover.h"

//矩形覆盖：
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，从同一个方向看总共有多少种不同的方法？

//比如n = 3时，2 * 3的矩形块有3种不同的覆盖方法(从同一个方向看)：

//输入描述：
//2 * 1的小矩形的总个数n
//返回值描述：
//覆盖一个2 * n的大矩形总共有多少种不同的方法(从同一个方向看)
//示例1  输入：1返回值：1
//示例2  输入：2返回值：2
//示例3  输入：3返回值：3
//示例4  输入：4返回值：5
//经过分析 f（n）=f(n-1)+f(n-2)
void RectCover::Test()
{
	
	for (int i = 1; i < 10; i++)
	{
		auto ret = rectCover1(i);
		cout << ret <<endl ;
	}
	
}
//利用递推 时间复杂度和空间复杂度比较低
int RectCover:: rectCover1(int number)
{  
	int a1 = 1, a2 = 2, ret = 3;
	if (number <=2)
		return number;
	else
	{
		for (int i = 3; i <=number; i++)
		{
			ret = a1 + a2;
			a1 = a2;
			a2 = ret;
		}
		return ret;
	}
}