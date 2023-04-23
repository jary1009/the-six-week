#define _CRT_SECURE_NO_WARNINGS

#include"BstTree.h"
#include"Stack.h"
#include"Queue.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//��ӡ����
//������nameҪ��ӡ���ַ���
void BstPrintf(char name[20])
{
	printf("%s\n", name);
}

//�ļ�����

////ˢ���ļ����ݺ���
////������filenameҪˢ�µ��ļ���
//void Refresh(const char fileName[20])
//{
//	FILE* file;
//	file = fopen(fileName, "w");
//	fclose(file);
//}

//�ļ���� 
//������nameҪ��ӡ���ַ���
void BstFprintf(char name[20])
{
	FILE* fp;
	fp = fopen("BstTree.txt", "a");

	fprintf(fp,"%s\n", name);

	fclose(fp);
}

//�ļ�����
//������Tָ�룬���ع�������
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

//�ļ�չʾ
//������void
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



//��ɾ�� �� �Ȳ�д

//��ʼ��
//������Tָ�룬�����޸ĺ�ĸ��ڵ�
void InitBstTree(BstTree* T)
{
	*T = (BstTree)malloc(sizeof(BstTreeNode));
	
	strcpy((*T)->name, "\0");
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
}

//�����½��
//������Nָ�룬�����½�㣬name����ʼ��������
void NewBstTreeNode(BstTreeNode** N, const char name[20])
{
	*N = (BstTreeNode*)malloc(sizeof(BstTreeNode));

	strcpy((*N)->name, name);
	(*N)->lchild = NULL;
	(*N)->rchild = NULL;
}


//�뷨��search ȡ��

//����
//������Tָ�룬�����޸ĺ�����ĸ��ڵ㣬name�ַ���
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
			printf("����������ظ�ֵ\n");
		}
	}
}

//ɾ��
//������Tָ�룬����ɾ���������name�ַ���
void DeleteBst(BstTree* T, const char name[20])
{
	if (*T == NULL)
	{
		printf("�����ڸýڵ�\n");
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

//����
//T���ĸ��ڵ㣬nameҪ���ҵ��ַ�����Nָ�룬���ص�ַ
void SearchBst(BstTree T, const char name[20],BstTreeNode** N)
{
	if (T == NULL)
	{
		printf("�����ڸýڵ�\n");
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


//����

//ǰ��������ݹ飩
//������T����f����ָ��
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

//ǰ��������ǵݹ飩
//������T����f����ָ��
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

//����������ݹ飩
//������T����f����ָ��
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

//����������ǵݹ飩
//������T����f����ָ��
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

//����������ݹ飩
//������T����f����ָ��
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

//����������ǵݹ飩
//������T����f����ָ��
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
			if (cur->rchild!=NULL&&cur->rchild!=record)//������δ������
			{
				cur = cur->rchild;
				PushLStack(&s, cur);
				cur = cur->lchild;
			}
			else //�����ڻ򱻷���
			{
				f(cur->name);
				PopLStack(&s, &cur);

				record = cur;
				cur = NULL;
			}
		}
	}
}


//�������
//������T����f����ָ��
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

//����
//������T�����ٵĶ�����
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

