#include "PrintListFromTailToHead.h"
#include <iostream>

// 输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。

	//	如输入{ 1,2,3 }的链表如下:

	//	返回一个数组为[3, 2, 1]

 void PrintListFromTailToHead::Test()
{
	 ListNode* head = new ListNode(1);
	 head->next=new  ListNode(2);
	 head->next->next= new  ListNode(3);
	 auto a= printListFromTailToHead3(head);
	 for (size_t i = 0; i < a.size(); i++)
	 {
		cout << a[i] << endl;
	 }
}
	
	

 /// <summary>
 /// 解决方法一 （直接通过数组，然后反转(有对应的函数)）
 /// </summary>
 /// <param name="head"></param>
 /// <returns></returns>
 vector<int> PrintListFromTailToHead::printListFromTailToHead1(ListNode* head){

	 
	 vector<int> ret;
	 while (head)
	 {
		 ret.push_back( head->val);
		 head = head->next;
	 }
	 reverse(ret.begin(), ret.end());
	 return ret;
 }

 
 /// <summary>
 /// 递归 实现（类似于二叉树的后序遍历，不过这里就是一个儿子，二叉树是有两个儿子，仅此而已）
 /// </summary>
 /// <param name="head"></param>
 /// <returns></returns>
 vector<int> PrintListFromTailToHead::printListFromTailToHead2(ListNode* head) {

	vector<int> ret;
	if (!head)
		 return ret;
	ret= printListFromTailToHead2(head->next);
	ret.push_back(head->val);
	return ret;
 }

 /// <summary>
 /// 通过数组反转，但反转链表自己实现
 /// </summary>
 /// <param name="head"></param>
 /// <returns></returns>
 vector<int> PrintListFromTailToHead::printListFromTailToHead3(ListNode* head) {

	 //反转链表
	 ListNode* pre = nullptr;
	 ListNode* cur = head;
	 ListNode* temp = cur;
	 while (cur) 
	 {
		 temp = cur->next;
		 cur->next = pre;
		 pre = cur;
		 cur = temp;
	 }
	 vector<int> ret;

	 while (pre)
	 {
		 ret.push_back(pre->val);
		 pre = pre->next;
	 }
	 return ret;
 }



