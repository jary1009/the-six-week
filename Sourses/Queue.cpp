#include"Queue.h"

#include<stdlib.h>

//有头节点的版本


//初始化队列
//参数:Q指针，要初始化的队列
void InitLQueue(LinkQueue* Q) 
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = NULL;
	temp->next = NULL;

	Q->front = temp;
	Q->rear = temp;
	Q->length = 0;
}

//入队
//参数：Q指针，要入队的队列，data元素
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

//出队
//参数：Q指针，要出队的队列，data指针，返回出队的元素
bool PopLQueue(LinkQueue* Q,BstTreeNode** data) 
{
	if (Q == NULL || Q->front == Q->rear)
		return false;
	else if (Q->front->next->next == NULL)//只有一个节点
	{
		*data = Q->rear->data;

		QueueNode* temp = Q->rear;
		Q->rear = Q->front;

		free(temp);
		Q->length = 0;
	}
	else//有两个以上的结点
	{
		*data = Q->front->next->data;

		QueueNode* temp = Q->front->next;
		Q->front->next = Q->front->next->next;

		free(temp);
		Q->length--;
	}
	return true;
}

//判空
//参数：Q要判断的队列
bool IsEmptyLQueue(LinkQueue Q) 
{
	if (Q.front == NULL || Q.rear == NULL)return true;
	if (Q.front == Q.rear)return true;
	else return false;
}


//销毁（主要是释放头节点占用的空间）
//参数：Q（要销毁的队列）
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