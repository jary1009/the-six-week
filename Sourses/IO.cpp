#define _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include<stdio.h>

//��ȡ����
//������resultָ�룬���ػ�õ�����
bool GetNum(int* result)
{
	int num = 0;
	scanf("%d", &num);
	char judge = getchar();
	while (judge != '\n')
	{
		puts("��ȷ�����ʽ���������ֺ��»س�");
		while ((judge = getchar()) != '\n');
		scanf("%d", &num);
		judge = getchar();
	}
	*result = num;
	return true;
}
//��ȡ�з�Χ������
//������min��max���ֵ������Сֵ�����Ե��ڣ���resultָ�룬���ػ�õ�����
bool GetNumLimit(int min, int max, int* result)
{
	int flag;
	GetNum(&flag);
	while (flag > max || flag < min)
	{
		printf("��ȷ���ַ�Χ��%d��%d\n", min, max);
		GetNum(&flag);
	}
	*result = flag;
	return true;
}



//��ȡ�ַ�������С����
//������stringָ�룬���ػ�ȡ���ַ�����size�ַ����ַ�����
bool GetStringLimitNum(char* string, int size)
{
	char tempString[1000];
	bool flag = false;
	while (flag == false)
	{
		printf("������%d���ַ����ڵ��ַ���\n", size);
		scanf("%s", &tempString);
		for (int i = 0; i < size+1; i++)
		{

			if (tempString[i] == '\0')
			{
				flag = true;
				break;
			}

			if (i == size  && tempString[i] != '\0')
			{
				printf("�ַ�������������\n");
			}
		}
	}
	strcpy(string, tempString);
	return true;
}


//��ȡ�ַ�������С���ַ�����
//������stringָ�룬���ػ�ȡ���ַ�����size�ַ����ַ�������legalChar�ַ����飬�����źϷ��ַ�
bool GetStringLimitNumChar(char* string, int size, char* legalChar)
{
	GetStringLimitNum(string, size);
	bool flagTotal = false;
	char* OriginalLegalChar = legalChar;
	bool flagArray[10000];
	while (flagTotal == false)
	{
		for (int i = 0; i < size; i++)
		{
			flagArray[i] = false;
		}
		for (int i = 0; i < strlen(string); i++)
		{
			while (*legalChar != '~')
			{
				if (string[i] == *legalChar)
				{
					flagArray[i] = true;
					break;
				}
				legalChar++;
			}
			legalChar = OriginalLegalChar;
		}
		flagTotal = true;
		for (int i = 0; i < strlen(string); i++)
		{
			if (flagArray[i] == false)
			{
				flagTotal = false;
			}
		}
		if (flagTotal == false)
		{
			printf("������ڷǷ��ַ�\n");
			GetStringLimitNum(string, size);
		}
	}
	getchar();
	return true;
}
