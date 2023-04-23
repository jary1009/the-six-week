#include"Stack.h"

#include<stdlib.h>

//��ʼ��ջ
//������sָ�룬���س�ʼ�����ջ��
bool InitLStack(LinkStack* s) 
{
	s->top = NULL;
	s->count = 0;
	return true;
}

//��ջ
//������sָ�룬������ջ�޸ĺ��ջ��data����
bool PushLStack(LinkStack* s, BstTreeNode* data) 
{
	//˼·������һ����㣬�ӵ�ͷ��
	if (s == NULL)return false;

	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL)return false;
	temp->data = data;
	temp->next = s->top;

	s->top = temp;
	s->count++;
	return true;
}

//��ջ
//������sָ�룬���س�ջ�޸ĺ��ջ��dataָ�룬����ջ��Ԫ��
bool PopLStack(LinkStack* s, BstTreeNode** data) 
{
	//˼·���޸�top��free����һ���ڵ㼴��
	if (s == NULL)return false;
	if (s->top == NULL)return false;

	StackNode* temp = s->top;
	*data = s->top->data;
	s->top = s->top->next;
	s->count--;
	free(temp);
	return true;
}

//�õ�ջ��Ԫ��
//������sҪ���ҵ�ջ��dataָ�룬����ջ��Ԫ��
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

//�ж�ջ�Ƿ�Ϊ��
//������sҪ�жϵ�ջ
bool IsEmptyLStack(LinkStack s) 
{

	if (s.count != 0)return false;
	else return true;
}