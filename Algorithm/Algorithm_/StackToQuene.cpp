#include "StackToQuene.h"

void StackToQuene::Test()
{

	//push1(1);
	//push1(2);
	//push1(3);
	//auto ret1 = pop1();
	//push1(4);
	//auto ret2 = pop1();
	//push1(5);
	auto ret3 = pop2();
	push2(1);
	push2(2);
	push2(3);
	auto ret1 = pop2();
	push2(4);
	auto ret2 = pop2();
	push2(5);

}


/// <summary>
/// 方法一：进队： 往有数据的那个栈里添加；出队：获取之前把有数据的栈统一拿到没数据的栈，然后拿出一个，然后再把此时有数据的栈放回原来数据的栈中。时间复杂度： 进栈:O(1)，出栈:O(2n) 空间复杂度均为：O(n)
/// </summary>
/// <param name="node"></param>

void StackToQuene::push1(int node)
{
	if (stack1.size() != 0)
		stack1.push(node);
	else 
		stack2.push(node);
}
int StackToQuene::pop1()
{
	if (!stack1.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int ret = stack2.top();
		stack2.pop();
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return ret;
	}
	else if(!stack2.empty())
	{
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		int ret = stack1.top();
		stack1.pop();
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		return ret;
	}
	else
	{
		return 0;
	}
}


/// <summary>
/// 方法二：进队： 进到stack1 中，出队：先判断stack2中有数据没，如有数据，直接stack出栈，如无数据，再把stack1中的数据全部倒到stack2中，时间复杂度 均 O(1) 空间复杂度 均为 O(n)
/// </summary>
/// <param name="node"></param>
void StackToQuene::push2(int node)
{
	stack1.push(node);
}
int StackToQuene::pop2()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			int temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}
	if (stack2.empty()) //官方没有考虑这一点。是需要考虑的
		return 0;
	int ret = stack2.top();
	stack2.pop();
	return ret;
		
}
