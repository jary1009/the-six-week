#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//文件交互

//刷新文件内容函数
//参数：filename要刷新的文件名
void Refresh(const char fileName[20])
{
	FILE* file;
	file = fopen(fileName, "w");
	fclose(file);
}
