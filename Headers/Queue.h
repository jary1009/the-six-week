
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include"BstTree.h"

typedef struct QueueNode
{
	BstTreeNode* data;
	QueueNode* next;
}QueueNode;

typedef struct LinkQueue
{
	QueueNode* front;
	QueueNode* rear;
	int length;
}LinkQueue;


//��ʼ������
//����:Qָ�룬Ҫ��ʼ���Ķ���
void InitLQueue(LinkQueue* Q);


//���
//������Qָ�룬Ҫ��ӵĶ��У�dataԪ��
bool PushLQueue(LinkQueue* Q, BstTreeNode* data);

//����
//������Qָ�룬Ҫ���ӵĶ��У�dataָ�룬���س��ӵ�Ԫ��
bool PopLQueue(LinkQueue* Q, BstTreeNode** data);

//�п�
//������QҪ�жϵĶ���
bool IsEmptyLQueue(LinkQueue Q);

//���٣���Ҫ���ͷ�ͷ�ڵ�ռ�õĿռ䣩
//������Q��Ҫ���ٵĶ��У�
void DestoryLQueue(LinkQueue* Q);

#endif // !__QUEUE_H__



