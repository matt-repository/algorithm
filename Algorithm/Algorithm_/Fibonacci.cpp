#include "Fibonacci.h"
#include <vector>
using namespace std;

//斐波那契数列

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
// n≤39

void Fibonacci::Test()
{
	clock_t start1 = clock();
	
	auto ret1 = Fibonacci1(39);
	
	clock_t ends1 = clock();
	
	cout << "Running Time : " << (float)(ends1 - start1) / CLOCKS_PER_SEC << endl;

	clock_t start2 = clock();
	auto ret2 = Fibonacci3(39);

	clock_t ends2 = clock();

	cout << "Running Time : " << (float)(ends2 - start2) / CLOCKS_PER_SEC << endl;
	cout << ret2 << endl;
}

/// <summary>
/// 最简单的 递归实现,时间复杂度（2ⁿ） 空间复杂度 1
/// </summary>
/// <param name="n"></param>
/// <returns></returns>

int Fibonacci::Fibonacci1(int n)
{  
	if (n <= 1)
		return n;
	else
	{
		return Fibonacci1(n-1)+ Fibonacci1(n-2);
	}
}

/// <summary>
/// 递归的 优化。空间替代时间  时间复杂度（2ⁿ），但这里每次很快（但是栈里用了很多）。 空间复杂度 n
/// </summary>
/// <param name="n"></param>
/// <returns></returns>

int Fibonacci::Fibonacci2(int n)
{
	vector<int> dp(n,-1);
	return Fibonacci2Private(n, dp);
}


/// <summary>
/// 由于 上面空间 替代时间也会 消耗大量的内存，但是有些是不必要的，
/// 较上面比较。 这里用动态规划解决，比如，f(3)=f(2)+f(1)   f(6)=f(5)+f(4) ，
/// 此时 继续往下算 发现 f(2)f(3)都不需要了。可以释放了，但以上方法没有释放，浪费内存,,并且把栈空间也优化出来了
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int Fibonacci::Fibonacci3(int n)
{
	if (n <= 1)
		return n;
	int a1 = 0, a2 = 1, ret = 1;
	for (int i = 2; i <= n; i++)
	{
		ret = a1 + a2;
		a1 = a2;
		a2 = ret;
	}
	return ret;
}

int Fibonacci::Fibonacci2Private(int n, vector<int>& dp)
{
	if (n <= 1)
		return n;
	if (dp[n] != -1)
		return dp[n];
	else
		return dp[n] = Fibonacci2Private(n - 1, dp) + Fibonacci2Private(n - 2, dp);
}




