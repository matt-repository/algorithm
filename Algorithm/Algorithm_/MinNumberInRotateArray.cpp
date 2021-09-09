#include "MinNumberInRotateArray.h"
#include <iostream>

void MinNumberInRotateArray::Test()
{

	int ret = MinNumberInRotateArray1(vector<int> {1 ,1 ,1 ,1 ,0, 1});
	std::cout << ret << endl;
}

/// <summary>
/// 4 5 6 1 2 3 将一个非递减 数组。即a[n+1]>=a[n] 的数组进行旋转，得到的数组如前面，  找出最小的数。 递归+ 二分查找的基础上延伸的， 
///  即二分查找为 递增或递减，才能实现，即跟最中间的比，这里 没办法比，比了也不知道 它在哪一边，但是这里跟右端点比可以找出来它 最小的在哪一边。
/// 最开始想着递归的方法写，但循环到第二层的时候发现有问题，因为每到下一层 它的数组的逻辑就变了(并不是旋转数组) 所以这里不能用递归的方法写。
/// </summary>  
/// <param name="rotateArray"></param>
/// <returns></returns>
int MinNumberInRotateArray::MinNumberInRotateArray1(vector<int> rotateArray)
{
	/*if (rotateArray.size() == 0)
		return 0;
	int maxIndex = rotateArray.size();
	int mid = maxIndex / 2;
	vector<int> target;
	if (rotateArray[mid] > rotateArray[maxIndex])
	{
		int i = mid;
		while (i< maxIndex)
		{
			target.push_back(rotateArray[i + 1]);
			i++;
		}
		return MinNumberInRotateArray1(target);
	}
	else if (rotateArray[mid] < rotateArray[maxIndex])
	{

	}*/
	///上面为错误的思路，留着，以后查看思路


	if (rotateArray.size() == 0)
		return 0;

	int first = 0, last = rotateArray.size() - 1;

	int mid = last / 2;

	while (first<last) //这里写 < 或者 !=  都可以
	{
		if (rotateArray[mid] > rotateArray[last])
			first = mid+1;
		else if (rotateArray[mid] < rotateArray[last])
			last = mid;
		else
			last = last-1;
		mid = first + (last-first) / 2;
	}
	//跳出 时，mid=first=last ，所以此时可以返回 rotateArray[mid] rotateArray[first]  rotateArray[last] 都可以
	return rotateArray[mid];
		

}