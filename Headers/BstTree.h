#ifndef __BstTree_H__
#define __BstTree_H__

typedef struct BstTreeNode
{
	char name[20];
	struct BstTreeNode* lchild;
	struct BstTreeNode* rchild;
}BstTreeNode,*BstTree;


//��ӡ����
//������nameҪ��ӡ���ַ���
void BstPrintf(char name[20]);


//�ļ�����

////ˢ���ļ����ݺ���
////������filenameҪˢ�µ��ļ���
//void Refresh(const char fileName[20]);


//�ļ���� 
//������nameҪ��ӡ���ַ���
void BstFprintf(char name[20]);


//�ļ�����
//������Tָ�룬���ع�������
void BstFscanf(BstTree* T);

//�ļ�չʾ
//������void
void ShowFileBst(void);


//��ɾ�� �� �Ȳ�д

//��ʼ��
//������Tָ�룬�����޸ĺ�ĸ��ڵ�
void InitBstTree(BstTree* T);


//�����½��
//������Nָ�룬�����½�㣬name����ʼ��������
void NewBstTreeNode(BstTreeNode** N, const char name[20]);


//����
//������Tָ�룬�����޸ĺ�����ĸ��ڵ㣬name�ַ���
void InsertBst(BstTree* T, const char name[20]);


//ɾ��
//������Tָ�룬����ɾ���������name�ַ���
void DeleteBst(BstTree* T, const char name[20]);

//����
//T���ĸ��ڵ㣬nameҪ���ҵ��ַ�����Nָ�룬���ص�ַ
void SearchBst(BstTree T, const char name[20], BstTreeNode** N);


//����

//ǰ��������ݹ飩
//������T����f����ָ��
void PreOrderBstRec(BstTree T, void(*f)(char name[20]));


//ǰ��������ǵݹ飩
//������T����f����ָ��
void PreOrderBstNRec(BstTree T, void(*f)(char name[20]));

//����������ݹ飩
//������T����f����ָ��
void MidOrderBstRec(BstTree T, void(*f)(char name[20]));


//����������ǵݹ飩
//������T����f����ָ��
void MidOrderBstNRec(BstTree T, void(*f)(char name[20]));


//����������ݹ飩
//������T����f����ָ��
void PostOrderBstRec(BstTree T, void(*f)(char name[20]));


//����������ǵݹ飩
//������T����f����ָ��
void PostOrderBstNRec(BstTree T, void(*f)(char name[20]));

//�������
//������T����f����ָ��
void LevelOrderBst(BstTree T, void(*f)(char name[20]));

//����
//������T�����ٵĶ�����
void DestroyBst(BstTree* T);


#endif // !__BstTree_H__
