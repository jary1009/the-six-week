#ifndef __IO_H__
#define __IO_H__



//��ȡ����
//������resultָ�룬���ػ�õ�����
bool GetNum(int* result);

//��ȡ�з�Χ������
//������min��max���ֵ������Сֵ�����Ե��ڣ���resultָ�룬���ػ�õ�����
bool GetNumLimit(int min, int max, int* result);

//��ȡ�ַ�������С����
//������stringָ�룬���ػ�ȡ���ַ�����size�ַ����ַ�����
bool GetStringLimitNum(char* string, int size);

//��ȡ�ַ�������С���ַ�����
//������stringָ�룬���ػ�ȡ���ַ�����size�ַ����ַ�������legalChar�ַ����飬�����źϷ��ַ�
bool GetStringLimitNumChar(char* string, int size, char* legalChar);




#endif // !__IO_H__

