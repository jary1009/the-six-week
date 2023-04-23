#define _CRT_SECURE_NO_WARNINGS

#include"BstTree.h"
#include"Stack.h"
#include"Queue.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//打印函数
//参数：name要打印的字符串
void BstPrintf(char name[20])
{
	printf("%s\n", name);
}

//文件交互

////刷新文件内容函数
////参数：filename要刷新的文件名
//void Refresh(const char fileName[20])
//{
//	FILE* file;
//	file = fopen(fileName, "w");
//	fclose(file);
//}

//文件输出 
//参数：name要打印的字符串
void BstFprintf(char name[20])
{
	FILE* fp;
	fp = fopen("BstTree.txt", "a");

	fprintf(fp,"%s\n", name);

	fclose(fp);
}

//文件输入
//参数：T指针，返回构建的树
void BstFscanf(BstTree* T)
{
	FILE* fp;
	fp = fopen("BstTree.txt", "r");

	int flag = 0;

	char name[20];

	while(1)
	{
		flag = fscanf(fp, "%s", name);
		if (flag != 1)break;

		InsertBst(T, name);
	}

	fclose(fp);
}

//文件展示
//参数：void
void ShowFileBst(void)
{
	FILE* fp;
	fp = fopen("BstTree.txt", "r");

	int flag = 0;

	char name[20];

	while (1)
	{
		flag = fscanf(fp, "%s", name);
		if (flag != 1)break;

		printf("%s\n",name);

	}

	fclose(fp);
}



//增删查 改 先不写

//初始化
//参数：T指针，返回修改后的根节点
void InitBstTree(BstTree* T)
{
	*T = (BstTree)malloc(sizeof(BstTreeNode));
	
	strcpy((*T)->name, "\0");
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
}

//生成新结点
//参数：N指针，返回新结点，name，初始化的数据
void NewBstTreeNode(BstTreeNode** N, const char name[20])
{
	*N = (BstTreeNode*)malloc(sizeof(BstTreeNode));

	strcpy((*N)->name, name);
	(*N)->lchild = NULL;
	(*N)->rchild = NULL;
}


//想法：search 取代

//插入
//参数：T指针，返回修改后的树的根节点，name字符串
void InsertBst(BstTree* T,const char name[20])
{
	if (*T == NULL)
	{
		BstTreeNode* temp = NULL;
		NewBstTreeNode(&temp, name);
		*T = temp;
	}
	else 
	{
		char result = strcmp(name, (*T)->name);
		if (result == 1)
		{
			InsertBst(&(*T)->rchild, name);
		}
		else if (result == -1)
		{
			InsertBst(&(*T)->lchild, name);
		}
		else if (result == 0)
		{
			printf("不允许插入重复值\n");
		}
	}
}

//删除
//参数：T指针，返回删除后的树，name字符串
void DeleteBst(BstTree* T, const char name[20])
{
	if (*T == NULL)
	{
		printf("不存在该节点\n");
	}
	else
	{
		char result = strcmp(name, (*T)->name);
		if (result == 1)
		{
			DeleteBst(&(*T)->rchild, name);
		}
		else if (result == -1)
		{
			DeleteBst(&(*T)->lchild, name);
		}
		else if (result == 0)
		{
			if ((*T)->lchild == NULL && (*T)->rchild == NULL)
			{
				free(*T);
				*T = NULL;
			}
			else if ((*T)->rchild == NULL)
			{
				BstTreeNode* temp = *T;
				*T = (*T)->lchild;
				free(temp);
			}
			else if ((*T)->lchild == NULL)
			{
				BstTreeNode* temp = *T;
				*T = (*T)->rchild;
				free(temp);
			}
			else
			{
				BstTreeNode* temp = (*T)->lchild;
				while (temp->rchild != NULL)
				{
					temp = temp->rchild;
				}

				strcpy((*T)->name, temp->name);

				DeleteBst(&(*T)->lchild, name);
			}
		}
	}
}

//查找
//T树的根节点，name要查找的字符串，N指针，返回地址
void SearchBst(BstTree T, const char name[20],BstTreeNode** N)
{
	if (T == NULL)
	{
		printf("不存在该节点\n");
	}
	else
	{
		char result = strcmp(name, T->name);
		if (result == 1)
		{
			SearchBst(T->rchild, name,N);
		}
		else if (result == -1)
		{
			SearchBst(T->lchild, name, N);
		}
		else if (result == 0)
		{
			*N = T;
		}
	}
}


//遍历

//前序遍历（递归）
//参数：T树，f函数指针
void PreOrderBstRec(BstTree T, void(*f)(char name[20]))
{
	if (T == NULL)return;
	else
	{
		f(T->name);
		PreOrderBstRec(T->lchild, f);
		PreOrderBstRec(T->rchild, f);
	}
}

//前序遍历（非递归）
//参数：T树，f函数指针
void PreOrderBstNRec(BstTree T, void(*f)(char name[20]))
{
	LinkStack s;
	InitLStack(&s);

	BstTreeNode* cur = T;

	while (cur != NULL || IsEmptyLStack(s) != true)
	{
		if (cur != NULL)
		{
			PushLStack(&s, cur);
			f(cur->name);

			cur = cur->lchild;
		}
		else if (cur == NULL)
		{
			PopLStack(&s, &cur);
			cur = cur->rchild;
		}
	}
}

//中序遍历（递归）
//参数：T树，f函数指针
void MidOrderBstRec(BstTree T, void(*f)(char name[20]))
{
	if (T == NULL)return;
	else
	{
		MidOrderBstRec(T->lchild, f);
		f(T->name);
		MidOrderBstRec(T->rchild, f);
	}
}

//中序遍历（非递归）
//参数：T树，f函数指针
void MidOrderBstNRec(BstTree T, void(*f)(char name[20]))
{
	LinkStack s;
	InitLStack(&s);

	BstTreeNode* cur = T;

	while (cur != NULL || IsEmptyLStack(s) != true)
	{
		if (cur != NULL)
		{
			PushLStack(&s, cur);

			cur = cur->lchild;
		}
		else if (cur == NULL)
		{
			PopLStack(&s, &cur);
			f(cur->name);

			cur = cur->rchild;
		}
	}
}

//后序遍历（递归）
//参数：T树，f函数指针
void PostOrderBstRec(BstTree T, void(*f)(char name[20]))
{
	if (T == NULL)return;
	else
	{
		PostOrderBstRec(T->lchild, f);
		PostOrderBstRec(T->rchild, f);
		f(T->name);
	}
}

//后序遍历（非递归）
//参数：T树，f函数指针
void PostOrderBstNRec(BstTree T, void(*f)(char name[20]))
{

	LinkStack s;
	InitLStack(&s);

	BstTreeNode* cur = T;

	BstTreeNode* record = NULL;

	while (cur != NULL || IsEmptyLStack(s) != true)
	{
		if (cur != NULL)
		{
			PushLStack(&s, cur);
			cur = cur->lchild;
		}
		else if (cur == NULL)
		{
			GetTopLStack(s, &cur);
			if (cur->rchild!=NULL&&cur->rchild!=record)//存在且未被访问
			{
				cur = cur->rchild;
				PushLStack(&s, cur);
				cur = cur->lchild;
			}
			else //不存在或被访问
			{
				f(cur->name);
				PopLStack(&s, &cur);

				record = cur;
				cur = NULL;
			}
		}
	}
}


//层序遍历
//参数：T树，f函数指针
void LevelOrderBst(BstTree T, void(*f)(char name[20]))
{
	if (T == NULL)return;

	LinkQueue Q;
	InitLQueue(&Q);

	PushLQueue(&Q, T);

	while (IsEmptyLQueue(Q) != true)
	{
		BstTreeNode* temp;
		PopLQueue(&Q, &temp);

		f(temp->name);

		if (temp->lchild != NULL)
			PushLQueue(&Q, temp->lchild);

		if (temp->rchild != NULL)
			PushLQueue(&Q, temp->rchild);
	}
	
	DestoryLQueue(&Q);
}

//销毁
//参数：T被销毁的二叉树
void DestroyBst(BstTree *T)
{
	if (*T == NULL)return;
	else
	{
		DestroyBst(&(*T)->lchild);
		DestroyBst(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

