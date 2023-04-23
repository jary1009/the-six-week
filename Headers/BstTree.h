#ifndef __BstTree_H__
#define __BstTree_H__

typedef struct BstTreeNode
{
	char name[20];
	struct BstTreeNode* lchild;
	struct BstTreeNode* rchild;
}BstTreeNode,*BstTree;


//打印函数
//参数：name要打印的字符串
void BstPrintf(char name[20]);


//文件交互

////刷新文件内容函数
////参数：filename要刷新的文件名
//void Refresh(const char fileName[20]);


//文件输出 
//参数：name要打印的字符串
void BstFprintf(char name[20]);


//文件输入
//参数：T指针，返回构建的树
void BstFscanf(BstTree* T);

//文件展示
//参数：void
void ShowFileBst(void);


//增删查 改 先不写

//初始化
//参数：T指针，返回修改后的根节点
void InitBstTree(BstTree* T);


//生成新结点
//参数：N指针，返回新结点，name，初始化的数据
void NewBstTreeNode(BstTreeNode** N, const char name[20]);


//插入
//参数：T指针，返回修改后的树的根节点，name字符串
void InsertBst(BstTree* T, const char name[20]);


//删除
//参数：T指针，返回删除后的树，name字符串
void DeleteBst(BstTree* T, const char name[20]);

//查找
//T树的根节点，name要查找的字符串，N指针，返回地址
void SearchBst(BstTree T, const char name[20], BstTreeNode** N);


//遍历

//前序遍历（递归）
//参数：T树，f函数指针
void PreOrderBstRec(BstTree T, void(*f)(char name[20]));


//前序遍历（非递归）
//参数：T树，f函数指针
void PreOrderBstNRec(BstTree T, void(*f)(char name[20]));

//中序遍历（递归）
//参数：T树，f函数指针
void MidOrderBstRec(BstTree T, void(*f)(char name[20]));


//中序遍历（非递归）
//参数：T树，f函数指针
void MidOrderBstNRec(BstTree T, void(*f)(char name[20]));


//后序遍历（递归）
//参数：T树，f函数指针
void PostOrderBstRec(BstTree T, void(*f)(char name[20]));


//后序遍历（非递归）
//参数：T树，f函数指针
void PostOrderBstNRec(BstTree T, void(*f)(char name[20]));

//层序遍历
//参数：T树，f函数指针
void LevelOrderBst(BstTree T, void(*f)(char name[20]));

//销毁
//参数：T被销毁的二叉树
void DestroyBst(BstTree* T);


#endif // !__BstTree_H__
