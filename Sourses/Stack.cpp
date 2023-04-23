#include"Stack.h"

#include<stdlib.h>

//初始化栈
//参数：s指针，返回初始化后的栈。
bool InitLStack(LinkStack* s) 
{
	s->top = NULL;
	s->count = 0;
	return true;
}

//入栈
//参数：s指针，返回入栈修改后的栈，data数据
bool PushLStack(LinkStack* s, BstTreeNode* data) 
{
	//思路：创造一个结点，接到头部
	if (s == NULL)return false;

	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL)return false;
	temp->data = data;
	temp->next = s->top;

	s->top = temp;
	s->count++;
	return true;
}

//出栈
//参数：s指针，返回出栈修改后的栈，data指针，返回栈顶元素
bool PopLStack(LinkStack* s, BstTreeNode** data) 
{
	//思路：修改top，free掉第一个节点即可
	if (s == NULL)return false;
	if (s->top == NULL)return false;

	StackNode* temp = s->top;
	*data = s->top->data;
	s->top = s->top->next;
	s->count--;
	free(temp);
	return true;
}

//得到栈顶元素
//参数：s要查找的栈，data指针，返回栈顶元素
bool GetTopLStack(LinkStack s, BstTreeNode** e) 
{
	if (s.top == NULL)return false;
	if (s.count == 0)return false; 
	else
	{
		*e = s.top->data;
		return true;
	}
}

//判断栈是否为空
//参数：s要判断的栈
bool IsEmptyLStack(LinkStack s) 
{

	if (s.count != 0)return false;
	else return true;
}