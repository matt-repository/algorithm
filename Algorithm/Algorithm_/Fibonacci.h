#pragma once
#include<iostream>
#include <vector>
using namespace std;
//斐波那契数列

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
// n≤39
class Fibonacci
{
	
	public:void Test();
			int Fibonacci1(int n);
			int Fibonacci2(int n);
			int Fibonacci3(int n);
			int Fibonacci2Private(int n, vector<int>& dp);
	private:
		
		 
};

