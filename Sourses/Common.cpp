#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//�ļ�����

//ˢ���ļ����ݺ���
//������filenameҪˢ�µ��ļ���
void Refresh(const char fileName[20])
{
	FILE* file;
	file = fopen(fileName, "w");
	fclose(file);
}
