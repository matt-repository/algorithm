#include <vector>
#include <iostream>
#include "TwoArrayFind.h"
using namespace std;

TwoArrayFind::TwoArrayFind()
{
	cout << "TwoArrayFind 开始" << endl;
};

TwoArrayFind::~TwoArrayFind()
{
	cout << "TwoArrayFind 消亡" << endl;
}

bool TwoArrayFind::Test()
{
	vector<vector<int> > a;
	a = DataTwoArrayFind(a, 1, 2, 8, 9);
	a = DataTwoArrayFind(a, 2, 4, 9, 12);
	a = DataTwoArrayFind(a, 4, 7, 10, 13);
	a = DataTwoArrayFind(a, 6, 8, 11, 15);
	bool result = TestTwoArrayFind2(6, a);
	return result;
}

bool TwoArrayFind::TestTwoArrayFind1(int target, vector<vector<int>> array)
{
	// 判断数组是否为空
	if (array.size() == 0 || array[0].size() == 0) return false;

	for (const auto& vec : array) {
		for (const int val : vec) {
			if (val == target)
				return true;
		}
	}
	return false;
}
bool TwoArrayFind::TestTwoArrayFind2(int target, vector<vector<int>> array)
{
	if (array.size() == 0 || array[0].size() == 0)
		return false;

	//这里演示从右上查找
	int i = 0;
	int j = array[0].size() - 1;

	while (j >= 0 && i <= array.size() - 1)
	{
		if (array[i][j] == target)
			return true;
		else if (array[i][j] > target)
			j--;
		else
			i++;

	}
	return false;
}
vector<vector<int>> TwoArrayFind::DataTwoArrayFind(vector<vector<int>> a, int a1, int a2, int a3, int a4)
{
	vector<int> b;
	b.push_back(a1);
	b.push_back(a2);
	b.push_back(a3);
	b.push_back(a4);
	a.push_back(b);
	return a;
}



  
