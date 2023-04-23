#define _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include<stdio.h>

//获取数字
//参数：result指针，返回获得的数字
bool GetNum(int* result)
{
	int num = 0;
	scanf("%d", &num);
	char judge = getchar();
	while (judge != '\n')
	{
		puts("正确输入格式：输入数字后按下回车");
		while ((judge = getchar()) != '\n');
		scanf("%d", &num);
		judge = getchar();
	}
	*result = num;
	return true;
}
//获取有范围的数字
//参数：min，max数字的最大最小值（可以等于），result指针，返回获得的数字
bool GetNumLimit(int min, int max, int* result)
{
	int flag;
	GetNum(&flag);
	while (flag > max || flag < min)
	{
		printf("正确数字范围：%d到%d\n", min, max);
		GetNum(&flag);
	}
	*result = flag;
	return true;
}



//获取字符串，大小限制
//参数：string指针，返回获取的字符串，size字符串字符个数
bool GetStringLimitNum(char* string, int size)
{
	char tempString[1000];
	bool flag = false;
	while (flag == false)
	{
		printf("请输入%d个字符以内的字符串\n", size);
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
				printf("字符个数超出限制\n");
			}
		}
	}
	strcpy(string, tempString);
	return true;
}


//获取字符串，大小和字符限制
//参数：string指针，返回获取的字符串，size字符串字符个数，legalChar字符数组，里面存放合法字符
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
			printf("输入存在非法字符\n");
			GetStringLimitNum(string, size);
		}
	}
	getchar();
	return true;
}
