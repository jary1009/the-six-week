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
	//�˳�ѭ����־
	int whileFlagMain = 0;
	int whileFlagBST = 0;
	int whileFlagAVL = 0;
	int whileFlagRBT = 0;
	int whileFlagTraBst = 0;
	int whileFlagTraAVL = 0;
	int whileFlagTraRBT = 0;
	int whileFlagHeap = 0;

	//ѡ���־
	int switchFlagMain = 0;
	int switchFlagBST = 0;
	int switchFlagAVL = 0;
	int switchFlagRBT = 0;
	int switchFlagTraBst = 0;
	int switchFlagTraAVL = 0;
	int switchFlagTraRBT = 0;
	int switchFlagHeap = 0;
	int creatFlag = 0;

	//����

	char legalChar[63] = "\0";//�Ϸ��ַ� ��ĸ������
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

	//�洢������Ϣ
	BstTreeNode* BstNodeTemp =NULL ;

	//��
	BstTree BstTree = NULL;

	char scanfName[20] = "0";//¼���ַ���

	//��
	Heap Heap=NULL;
	bool FscanfFlag = false;

	int scanfData = 0;
	int scanfIndex = 0;
	int scanfDelta = 0;
	int scanfCapacity = 0;

	//�ܽ���
	while (1)
	{
		whileFlagMain = 1;

		system("cls");
		MenuMain();

		printf("������ѡ��\n");
		GetNumLimit(1, 3, &switchFlagMain);

		switch (switchFlagMain)
		{
		case (1)://����������
				//¼��
			 {
			//����
			system("cls");

			printf("____________________��������ʼ��_____________________\n");
			printf("0:�����հ���\n");
			printf("1:��BstTree.txt�ļ��л�ȡ���ݣ���������������\n");
			printf("_____________________________________________________\n");
			
			printf("�ļ��������£�\n");
			ShowFileBst();

			printf("\n");
			printf("������ѡ��\n");
			GetNumLimit(0, 1, &creatFlag);

			if (creatFlag == 0)
			{
				DestroyBst(&BstTree);
			}
			else if (creatFlag == 1)
			{
				DestroyBst(&BstTree);
				BstFscanf(&BstTree);
				printf("�Ѿ���BstTree.txt�ļ��л�ȡ���ݣ������˶���������\n");
			}
			system("pause");
			}

			while (1)
			{
				whileFlagBST = 1;
				
				system("cls");
				MenuBST();

				printf("������ѡ��\n");
				GetNumLimit(1, 5, &switchFlagBST);
				switch (switchFlagBST)
				{
				case (1)://����

					printf("������Ҫ¼����ַ���\n");
					printf("�Ϸ��ַ�����ʽ��������Сд��ĸ������\n");
					GetStringLimitNumChar(scanfName, 20, legalChar);

					InsertBst(&BstTree, scanfName);

					printf("�������\n");

					system("pause");
					break;

				case (2)://ɾ��

					printf("������Ҫɾ�����ַ���\n");
					printf("�Ϸ��ַ�����ʽ��������Сд��ĸ������\n");
					GetStringLimitNumChar(scanfName, 20, legalChar);

					DeleteBst(&BstTree, scanfName);

					printf("�������\n");
					system("pause");
					break;

				case (3)://����

					printf("������Ҫ���ҵ��ַ���\n");
					printf("�Ϸ��ַ�����ʽ��������Сд��ĸ������\n");
					GetStringLimitNumChar(scanfName, 20, legalChar);

					BstNodeTemp = NULL;
					SearchBst(BstTree, scanfName, &BstNodeTemp);

					if (BstNodeTemp != NULL)
						printf("�ýڵ���ڣ���ֵַΪ��%p\n", BstNodeTemp);

					system("pause");
					break;

				case (4)://����

					while (1)//�����˵�
					{
						whileFlagTraBst = 1;

						system("cls");
						MenuTra();

						printf("������ѡ��\n");
						GetNumLimit(1, 8, &switchFlagTraBst);

						switch (switchFlagTraBst)
						{
						case (1)://�������

							LevelOrderBst(BstTree, BstPrintf);

							system("pause");
							break;
						case (2)://ǰ��������ݹ飩

							PreOrderBstRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (3)://ǰ��������ǵݹ飩

							PreOrderBstNRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (4)://����������ݹ飩

							MidOrderBstRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (5)://����������ǵݹ飩

							MidOrderBstNRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (6)://����������ݹ飩

							PostOrderBstRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (7)://����������ǵݹ飩

							PostOrderBstNRec(BstTree, BstPrintf);

							system("pause");
							break;
						case (8)://�˳�

							whileFlagTraBst = 0;

							system("pause");
							break;

						default:
							break;
						}

						if (whileFlagTraBst == 0) break;

					}

					break;

				case (5)://�˳�

					whileFlagBST = 0;

					break;

				default:
					break;
				}

				if (whileFlagBST == 0) break;

			}

			//���
			Refresh("BstTree.txt");
			LevelOrderBst(BstTree, BstFprintf);
			printf("�˶����������Ѿ����浽BstTree.txt�ļ���\n");

			system("pause");
			break;

		case(2)://��
			
			//¼��
			{
				//����
				system("cls");

				printf("______________________�ѳ�ʼ��_______________________\n");
				printf("0:�����հ׶�\n");
				printf("1:��Heap.txt�ļ��л�ȡ���ݣ�������\n");
				printf("_____________________________________________________\n");
			
				printf("�ļ���������\n");
				ShowFileHeap();

				printf("\n");
				printf("������ѡ��\n");
				GetNumLimit(0, 1, &creatFlag);

				if (creatFlag == 0)
				{
					printf("������ѵ�������С\n");
					printf("���ַ�Χ��[1,10000]\n");
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
				
					printf("�Ѿ���Heap.txt�ļ��л�ȡ���ݣ������˶�\n");
				}
				system("pause");
			}
			while (1)
			{
				whileFlagHeap = 1;

				system("cls");
				MenuHeap();

				//¼��

				printf("������ѡ��\n");
				GetNumLimit(1, 6, &switchFlagHeap);
				switch (switchFlagHeap)
				{
				case (1)://����

					printf("������Ҫ¼�������\n");
					printf("���ַ�Χ��[-10000,10000]\n");
					//GetNumLimit(INT_MIN+1,INT_MAX ,&scanfData);
					GetNumLimit(-10000,10000 ,&scanfData);
				
					InsertHeap(Heap, scanfData);

					printf("�������\n");

					system("pause");
					break;
				case (2)://ɾ����Сֵ

					DeletaMinHeap(Heap);

					printf("�������\n");

					system("pause");
					break;
				case (3)://ɾ����n��

					printf("������Ҫ�������������\n");
					GetNumLimit(1, 10000, &scanfIndex);

					DeleteHeap(Heap, scanfIndex);

					system("pause");
					break;
				case (4)://�޸ĵ�n����ֵ

					printf("������Ҫ�ı����������\n");
					GetNumLimit(1, 10000, &scanfIndex);

					printf("��������������\n");
					printf("ע�ͣ����������ɸ�\n");
					printf("ע�ͣ��ı�����ݵķ�Χ��Ӧ����[-10000,10000]֮��\n");
					GetNumLimit(-20000, 20000, &scanfDelta);

					ChangeHeap(Heap, scanfIndex, scanfDelta);

					printf("�������\n");

					system("pause");
					break;
				case (5)://��ӡ��

					PrintHeap(Heap);

					system("pause");
					break;
				case (6)://�˳�

					whileFlagHeap = 0;
					system("pause");
					break;

				default:
					break;
				}

				


				if (whileFlagHeap == 0) break;

			}
			//���
				Refresh("Heap.txt");
				FprintHeap(Heap);
			break;
		case(3)://�˳�����
			whileFlagMain = 0;
			break;
		}

		if (whileFlagMain == 0) break;
	}
}
