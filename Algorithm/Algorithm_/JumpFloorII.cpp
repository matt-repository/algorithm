#include "JumpFloorII.h"
using namespace std;

void JumpFloorII::Test()
{
	int ret = JumpFloorII1(9);
    cout << ret << endl;
}

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。

//1、如果f(0)=1  则 f(n)=f(n-1)+f(n-2)...f(0);这种方法写起来比较浪费时间和空间
//2、经过动态规划后，发现 f(n)=2ⁿ﹣¹
int JumpFloorII::JumpFloorII1(int number)
{
    int ret = 1;//f(1)的值
    for (int i = 2; i <= number; i++)
    {
        ret = ret <<1;
    }
    return ret;
}

/// <summary>
/// 直接 f(n)=2ⁿ﹣¹,节省了内存。相对于上面 简化了空间
/// </summary>
/// <param name="number"></param>
/// <returns></returns>
int JumpFloorII :: JumpFloorII2(int number)
{
    if (number == 0)
        return 1;
    return pow(2, number - 1);
}

