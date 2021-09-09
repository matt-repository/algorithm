#include<vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) { //执行构造函数的时候先把val 赋值。next 初始化
	}
};
class PrintListFromTailToHead
{
	

public :
	void Test();
	vector<int> printListFromTailToHead1(ListNode* head);
	vector<int> printListFromTailToHead2(ListNode* head);
	vector<int> printListFromTailToHead3(ListNode* head);
private:

};

