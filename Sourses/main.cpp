#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Menu.h"
#include"IO.h"
#include"BstTree.h"
#include"Heap.h"
#include"Common.h"


int main()
{
	//退出循环标志
	int whileFlagMain = 0;
	int whileFlagBST = 0;
	int whileFlagAVL = 0;
	int whileFlagRBT = 0;
	int whileFlagTraBst = 0;
	int whileFlagTraAVL = 0;
	int whileFlagTraRBT = 0;
	int whileFlagHeap = 0;

	//选择标志
	int switchFlagMain = 0;
	int switchFlagBST = 0;
	int switchFlagAVL = 0;
	int switchFlagRBT = 0;
	int switchFlagTraBst = 0;
	int switchFlagTraAVL = 0;
	int switchFlagTraRBT = 0;
	int switchFlagHeap = 0;
	int creatFlag = 0;

	//参数

	char legalChar[63] = "\0";//合法字符 字母和数字
	for (int i = 0; i < 26; i++)
	{
		legalChar[i] = 'a' + i;
	}
	for (int i = 0; i < 26; i++)
	{
		legalChar[i + 26] = 'A' + i;
	}
	for (int i = 0; i < 10; i++)
	{
		legalChar[i + 52] = '0' + i;
	}
	legalChar[62] = '~';

	//存储返回信息
	BstTreeNode* BstNodeTemp =NULL ;

	//树
	BstTree BstTree = NULL;

	char scanfName[20] = "0";//录入字符串

	//堆
	Heap Heap=NULL;
	bool FscanfFlag = false;

	int scanfData = 0;
	int scanfIndex = 0;
	int scanfDelta = 0;
	int scanfCapacity = 0;

	//总界面
	while (1)
	{
		whileFlagMain = 1;

		system("cls");
		MenuMain();

		printf("请输入选项\n");
		GetNumLimit(1, 3, &switchFlagMain);

		switch (switchFlagMain)
		{
		case (1)://二叉排序树
				//录入
			 {
			//输入
			system("cls");

			printf("____________________二叉树初始化_____________________\n");
			printf("0:构建空白树\n");
			printf("1:从BstTree.txt文件中获取数据，构建二叉搜索树\n");
			printf("_____________________________________________________\n");
			
			printf("文件内容如下：\n");
			ShowFileBst();

			printf("\n");
			printf("请输入选项\n");
			GetNumLimit(0, 1, &creatFlag);

			if (creatFlag == 0)
			{
				DestroyBst(&BstTree);
			}
			else if (creatFlag == 1)
			{
				DestroyBst(&BstTree);
				BstFscanf(&BstTree);
				printf("已经从BstTree.txt文件中获取数据，构建了二叉搜索树\n");
			}
			system("pause");
			}

			while (1)
			{
				whileFlagBST = 1;
				
				system("cls");
				MenuBST();

				printf("请输入选项\n");
				GetNumLimit(1, 5, &switchFlagBST);
				switch (switchFlagBST)
				{
				case (1)://插入

					printf("请输入要录入的字符串\n");
					printf("合法字符串格式：仅含大小写字母加数字\n");
					GetStringLimitNumChar(scanfName, 20, legalChar);

					InsertBst(&BstTree, scanfName);

					printf("操作完成\n");

					system("pause");
					break;

				case (2)://删除

					printf("请输入要删除的字符串\n");
					printf("合法字符串格式：仅含大小写字母加数字\n");
					GetStringLimitNumChar(scanfName, 20, legalChar);

					DeleteBst(&BstTree, scanfName);

					printf("操作完成\n");
					system("pause");
					break;

				case (3)://查找

					printf("请输入要查找的字符串\n");
					printf("合法字符串格式：仅含大小写字母加数字\n");
					GetStringLimitNumChar(scanfName, 20, legalChar);

					BstNodeTemp = NULL;
					SearchBst(BstTree, scanfName, &BstNodeTemp);

					if (BstNodeTemp != NULL)
						printf("该节点存在，地址值为：%p\n", BstNodeTemp);

					system("pause");
					break;

				case (4)://遍历

					while (1)//遍历菜单
					{
						whileFlagTraBst = 1;

						system("cls");
						MenuTra();

						printf("请输入选项\n");
						GetNumLimit(1, 8, &switchFlagTraBst);

						switch (switchFlagTraBst)
						{
						case (1)://层序遍历

							LevelOrderBst(BstTree, BstPrintf);

							system("pause");
							break;
						case (2)://前序遍历（递归）

							PreOrderBstRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (3)://前序遍历（非递归）

							PreOrderBstNRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (4)://中序遍历（递归）

							MidOrderBstRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (5)://中序遍历（非递归）

							MidOrderBstNRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (6)://后序遍历（递归）

							PostOrderBstRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (7)://后序遍历（非递归）

							PostOrderBstNRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (8)://退出

							whileFlagTraBst = 0;

							system("pause");
							break;

						default:
							break;
						}

						if (whileFlagTraBst == 0) break;

					}

					break;

				case (5)://退出

					whileFlagBST = 0;

					break;

				default:
					break;
				}

				if (whileFlagBST == 0) break;

			}

			//输出
			Refresh("BstTree.txt");
			LevelOrderBst(BstTree, BstFprintf);
			printf("此二叉搜索树已经保存到BstTree.txt文件中\n");

			system("pause");
			break;

		case(2)://堆
			
			//录入
			{
				//输入
				system("cls");

				printf("______________________堆初始化_______________________\n");
				printf("0:构建空白堆\n");
				printf("1:从Heap.txt文件中获取数据，构建堆\n");
				printf("_____________________________________________________\n");
			
				printf("文件内容如下\n");
				ShowFileHeap();

				printf("\n");
				printf("请输入选项\n");
				GetNumLimit(0, 1, &creatFlag);

				if (creatFlag == 0)
				{
					printf("请输入堆的容量大小\n");
					printf("数字范围：[1,10000]\n");
					GetNumLimit(1, 10000, &scanfCapacity);

					if (Heap != NULL)
						DestroyHeap(&Heap);

					InitHeap(&Heap, scanfCapacity);
				}
				else if (creatFlag == 1)
				{
					FscanfFlag = false;

					if (Heap != NULL)
						DestroyHeap(&Heap);

						FscanfHeap(&Heap);
				
					printf("已经从Heap.txt文件中获取数据，构建了堆\n");
				}
				system("pause");
			}
			while (1)
			{
				whileFlagHeap = 1;

				system("cls");
				MenuHeap();

				//录入

				printf("请输入选项\n");
				GetNumLimit(1, 6, &switchFlagHeap);
				switch (switchFlagHeap)
				{
				case (1)://插入

					printf("请输入要录入的数字\n");
					printf("数字范围：[-10000,10000]\n");
					//GetNumLimit(INT_MIN+1,INT_MAX ,&scanfData);
					GetNumLimit(-10000,10000 ,&scanfData);
				
					InsertHeap(Heap, scanfData);

					printf("操作完成\n");

					system("pause");
					break;
				case (2)://删除最小值

					DeletaMinHeap(Heap);

					printf("操作完成\n");

					system("pause");
					break;
				case (3)://删除第n个

					printf("请输入要输出的数据索引\n");
					GetNumLimit(1, 10000, &scanfIndex);

					DeleteHeap(Heap, scanfIndex);

					system("pause");
					break;
				case (4)://修改第n个的值

					printf("请输入要改变的数据索引\n");
					GetNumLimit(1, 10000, &scanfIndex);

					printf("请输入数据增量\n");
					printf("注释：增量可正可负\n");
					printf("注释：改变后数据的范围不应该在[-10000,10000]之外\n");
					GetNumLimit(-20000, 20000, &scanfDelta);

					ChangeHeap(Heap, scanfIndex, scanfDelta);

					printf("操作完成\n");

					system("pause");
					break;
				case (5)://打印堆

					PrintHeap(Heap);

					system("pause");
					break;
				case (6)://退出

					whileFlagHeap = 0;
					system("pause");
					break;

				default:
					break;
				}

				


				if (whileFlagHeap == 0) break;

			}
			//输出
				Refresh("Heap.txt");
				FprintHeap(Heap);
			break;
		case(3)://退出界面
			whileFlagMain = 0;
			break;
		}

		if (whileFlagMain == 0) break;
	}
}
