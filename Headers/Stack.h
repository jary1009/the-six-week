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

//��ʼ��ջ
//������sָ�룬���س�ʼ�����ջ��
bool InitLStack(LinkStack* s);

//��ջ
//������sָ�룬������ջ�޸ĺ��ջ��data����
bool PushLStack(LinkStack* s, BstTreeNode* data);

//��ջ
//������sָ�룬���س�ջ�޸ĺ��ջ��dataָ�룬����ջ��Ԫ��
bool PopLStack(LinkStack* s, BstTreeNode** data);

//�õ�ջ��Ԫ��
//������sҪ���ҵ�ջ��dataָ�룬����ջ��Ԫ��
bool GetTopLStack(LinkStack s, BstTreeNode** e);

//�ж�ջ�Ƿ�Ϊ��
//������sҪ�жϵ�ջ
bool IsEmptyLStack(LinkStack s);






#endif // !__STACK_H__

