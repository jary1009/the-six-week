#ifndef __STACK_H__
#define __STCAK_H__

#include"BstTree.h"

typedef  struct StackNode
{
	BstTreeNode* data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//初始化栈
//参数：s指针，返回初始化后的栈。
bool InitLStack(LinkStack* s);

//入栈
//参数：s指针，返回入栈修改后的栈，data数据
bool PushLStack(LinkStack* s, BstTreeNode* data);

//出栈
//参数：s指针，返回出栈修改后的栈，data指针，返回栈顶元素
bool PopLStack(LinkStack* s, BstTreeNode** data);

//得到栈顶元素
//参数：s要查找的栈，data指针，返回栈顶元素
bool GetTopLStack(LinkStack s, BstTreeNode** e);

//判断栈是否为空
//参数：s要判断的栈
bool IsEmptyLStack(LinkStack s);






#endif // !__STACK_H__

