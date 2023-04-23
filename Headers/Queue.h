
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


//初始化队列
//参数:Q指针，要初始化的队列
void InitLQueue(LinkQueue* Q);


//入队
//参数：Q指针，要入队的队列，data元素
bool PushLQueue(LinkQueue* Q, BstTreeNode* data);

//出队
//参数：Q指针，要出队的队列，data指针，返回出队的元素
bool PopLQueue(LinkQueue* Q, BstTreeNode** data);

//判空
//参数：Q要判断的队列
bool IsEmptyLQueue(LinkQueue Q);

//销毁（主要是释放头节点占用的空间）
//参数：Q（要销毁的队列）
void DestoryLQueue(LinkQueue* Q);

#endif // !__QUEUE_H__



