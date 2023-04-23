#include"Queue.h"

#include<stdlib.h>

//��ͷ�ڵ�İ汾


//��ʼ������
//����:Qָ�룬Ҫ��ʼ���Ķ���
void InitLQueue(LinkQueue* Q) 
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = NULL;
	temp->next = NULL;

	Q->front = temp;
	Q->rear = temp;
	Q->length = 0;
}

//���
//������Qָ�룬Ҫ��ӵĶ��У�dataԪ��
bool PushLQueue(LinkQueue* Q, BstTreeNode* data) 
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->next = NULL;

	if (Q == NULL)return false;
	else
	{
		Q->rear->next = temp;
		Q->rear = temp;
		Q->length++;
	}
	return true;
}

//����
//������Qָ�룬Ҫ���ӵĶ��У�dataָ�룬���س��ӵ�Ԫ��
bool PopLQueue(LinkQueue* Q,BstTreeNode** data) 
{
	if (Q == NULL || Q->front == Q->rear)
		return false;
	else if (Q->front->next->next == NULL)//ֻ��һ���ڵ�
	{
		*data = Q->rear->data;

		QueueNode* temp = Q->rear;
		Q->rear = Q->front;

		free(temp);
		Q->length = 0;
	}
	else//���������ϵĽ��
	{
		*data = Q->front->next->data;

		QueueNode* temp = Q->front->next;
		Q->front->next = Q->front->next->next;

		free(temp);
		Q->length--;
	}
	return true;
}

//�п�
//������QҪ�жϵĶ���
bool IsEmptyLQueue(LinkQueue Q) 
{
	if (Q.front == NULL || Q.rear == NULL)return true;
	if (Q.front == Q.rear)return true;
	else return false;
}


//���٣���Ҫ���ͷ�ͷ�ڵ�ռ�õĿռ䣩
//������Q��Ҫ���ٵĶ��У�
void DestoryLQueue(LinkQueue* Q) 
{
	QueueNode* temp = Q->front;

	while (Q->front != Q->rear)
	{
		Q->front = Q->front->next;
		free(temp);
		temp = Q->front;
	}

	free(temp);
	Q = NULL;
}