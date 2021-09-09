#include "ReConstructBinaryTree.h"


//重建二叉树
//给定某二叉树的前序遍历和中序遍历，请重建出该二叉树并返回它的头结点。
//例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建出如下图所示。
//提示:
//1.0 <= pre.length <= 2000
//2.vin.length == pre.length
//3. - 10000 <= pre[i], vin[i] <= 10000
//4.pre 和 vin 均无重复元素
//5.vin出现的元素均出现在 pre里
//6.只需要返回根结点，系统会自动输出整颗树做答案对比

void ReConstructBinaryTree::Test()
{
   auto result= ReConstructBinaryTree2(vector<int>{7,4,2,5,8,6,3,1}, vector<int>{ 4, 7, 2, 1, 5, 3, 8, 6 });
}

/// <summary>
/// 递归的方法。可以查出根节点为1  左子树为 472，右子树为 5386  （依次左子树作为一个单独的树进行计算，）
/// </summary>
/// <param name="pre"></param>
/// <param name="vin"></param>
/// <returns></returns>
TreeNode*  ReConstructBinaryTree::ReConstructBinaryTree1( vector<int> pre, vector<int> vin)
{
	if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
		return nullptr;
	TreeNode* ret =new TreeNode(pre[0]);
	vector<int> preLeft, preRight, vinLeft, vinRight;
	bool isnode(false); //中序是否到了根节点
	for (int i = 0; i < vin.size(); i++)
	{
		if (!isnode) //中序遍历还没到根节点
		{
			//排除根节点 （前序遍历）
			if (i != 0)
				preLeft.push_back(pre[i]);
			if (pre[0] != vin[i])
				vinLeft.push_back(vin[i]);
		}
		else //中序遍历到了根节点（下一个）
		{
			preRight.push_back(pre[i]);
			vinRight.push_back(vin[i]);
		}
		if(pre[0] == vin[i])
			isnode = true;
	}
	if(preLeft.size()>0)
		ret->left = ReConstructBinaryTree1(preLeft, vinLeft);
	if(preRight.size()>0)
		ret->right = ReConstructBinaryTree1(preRight, vinRight);
	return ret;
}

/// <summary>
/// 已知后序遍历，中序遍历，重建二叉树（自己拓展的）
/// </summary>
/// <param name="after"></param>
/// <param name="vin"></param>
/// <returns></returns>

TreeNode* ReConstructBinaryTree::ReConstructBinaryTree2(vector<int> after, vector<int> vin)
{
	if (after.size() == 0 || vin.size() == 0 || after.size() != vin.size())
		return nullptr;
	auto maxIndex = after.size()-1;
	TreeNode* ret =new TreeNode(after[maxIndex]);
	vector<int> afterLeft, afterRight, vinLeft, vinRight;
	bool isnode(false); //中序是否到了根节点
	for (int i = 0; i <=maxIndex; i++)
	{
		if (!isnode) //中序遍历还没到根节点
		{
			if (after[maxIndex] != vin[i])
			{
				afterLeft.push_back(after[i]);
				vinLeft.push_back(vin[i]);
			}
			else
				afterRight.push_back(after[i]);
		}
		else //中序遍历到了根节点（下一个）
		{
			if(i!= maxIndex)
				afterRight.push_back(after[i]);
			vinRight.push_back(vin[i]);
		}
		if(after[maxIndex] == vin[i])
			isnode = true;
	}
	if(afterLeft.size()>0)
		ret->left = ReConstructBinaryTree2(afterLeft, vinLeft);
	if(afterRight.size()>0)
		ret->right = ReConstructBinaryTree2(afterRight, vinRight);
	return ret;
}
