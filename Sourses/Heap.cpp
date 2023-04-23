#define _CRT_SECURE_NO_WARNINGS

#include"Heap.h"
#include"IO.h"

#include<stdlib.h>
#include<stdio.h>



//����
//������hp�ѣ�f����ָ��
void TraverseHeap(Heap hp, void(*f)(int num))
{
	if (hp == NULL)return;

	for (int i = 1; i <= hp->size; i++)
	{
		f(hp->data[i]);
	}
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

//���������ѵ��ļ�Heap.txt�У�
//������hp��
void FprintHeap(Heap hp)
{
	FILE* fp;
	fp = fopen("Heap.txt", "a");

	fprintf(fp, "�ܹ���%d��\n", hp->size);
	fprintf(fp, "��������%d\n", hp->capacity);

	for (int i = 1; i <= hp->size; i++)
	{

		fprintf(fp,"��%d����%d\n", i, hp->data[i]);
	}

	fclose(fp);
}

//չʾ�ļ���Ϣ
//��������
void ShowFileHeap(void)
{

	FILE* fp;
	fp = fopen("Heap.txt", "r");

	int flag = 0;

	int i = 0;
	int num = 0;
	int size = 0;
	int  capacity = 0;


	flag = fscanf(fp, "�ܹ���%d��\n", &size);
	if (flag != 1)
	{
		printf("�ļ�Ϊ�ջ��ļ������ϸ�ʽ\n");
		return;
	}

	printf("�ܹ���%d��\n", size);

	flag = fscanf(fp, "��������%d\n", &capacity);
	if (flag != 1)
	{
		printf("�ļ������ϸ�ʽ\n");
		return;
	}

	printf("��������%d\n",capacity);

	while (1)
	{
		flag = fscanf(fp, "��%d����%d\n", &i, &num);
		if (flag != 2)break;

		printf("��%d����%d\n", i, num);
	}

	fclose(fp);
}

//¼�루���ļ�Heap.txt��¼�����ݽ���ѣ�
//����:hpָ�룬���ؽ���õĶѣ�capacity�ѵ��������
//ע�ͣ�capacity��Χ[1,INT_MAX]
void FscanfHeap(Heap* hp)
{

	FILE* fp;
	fp = fopen("Heap.txt", "r");

	int flag = 0;

	int i = 0;
	int num=0;
	int size = 0;
	int capacity = 0;
	int scanfCapacity = 0;

	flag=fscanf(fp, "�ܹ���%d��\n", &size);
	if (flag != 1)
	{
		printf("�ļ�Ϊ�ջ���Ч����ѡ��ѡ��1\n");
		return;
	}
	flag=fscanf(fp, "��������%d\n", &capacity);
	if (flag != 1)
	{
		printf("�ļ���Ч����ѡ��ѡ��1\n");
		return;
	}
	
	while(1)
	{
		printf("������ѵ�������С\n");
		printf("���ַ�Χ��[1,10000]\n");
		GetNumLimit(1, 10000, &scanfCapacity);

		if (scanfCapacity >= size)break;
		else
		{
			printf("������С��������\n");
		}
	}

	int* array = (int*)malloc(size * sizeof(int));

	while (1)
	{
		flag = fscanf(fp, "��%d����%d\n", &i,&num);
		if (flag != 2)break;

		array[i-1] = num;
	}

	BuildHeap(hp, scanfCapacity, array,size);

	free(array);
	array = NULL;

	fclose(fp);

	return ;
}

//��ӡ
//������hp��
void PrintHeap(Heap hp)
{
	if (hp == NULL)return;

	printf("�ܹ���%d��\n", hp->size);
	printf("������:%d\n", hp->capacity);
	
	for (int i = 1; i <= hp->size; i++)
	{
		printf("��%d����%d\n",i,hp->data[i]);
	}
}


//��ʼ����
//������hpָ�룬���س�ʼ����Ķѣ�capacity������  
//ע�ͣ�capacity��Χ[1,INT_MAX]
void InitHeap(Heap *hp,int capacity)
{
	//
	if (capacity <= 0)
	{
		printf("������С�ڵ���0");
		return;
	}
	
	//�������ٴγ�ʼ�����ڴ�й©��
	//������

	*hp = (Heap)malloc(sizeof(HeapNode));//���Ѹ�
	(*hp)->data = (int*)malloc((capacity + 1) * sizeof(int));

	(*hp)->capacity = capacity;
	(*hp)->size = 0;
	
	(*hp)->data[0] = INT_MIN;
}


//����ѣ���һά����¼�룬����һ���ѣ�
//������hpָ�룬���ؽ���õĶѣ�heapCapacity��������array���飬arraysize�����С
//ע�ͣ�capacity��Χ[1,INT_MAX]��arraysize��Χ[1,INT_MAX]
void BuildHeap(Heap* hp,int heapCapacity,int array[],int arraySize)
{
	//��һ��һֱinsert�����ã�o��N��
	

	//if (arraySize <= 0)
	//{
	//	printf("�����СС�ڵ���0\n");
	//	return;
	//}

	/*if (heapCapacity < arraySize)
	{
		printf("������С�������С\n");
		return;
	}*/

	InitHeap(hp, heapCapacity);
	(*hp)->size = arraySize;

	for(int i=0;i<=arraySize;i++)
	{
		(*hp)->data[i+1] = array[i];
	}

	for (int i = (*hp)->size / 2; i >= 1; i--)
	{
		ShiftDown(*hp, i);
	}
}

//�ݻٶ�
//����:hp��
void DestroyHeap(Heap* hp)
{
	//(*hp)->capacity = 0;
	//(*hp)->size = 0;

	free((*hp)->data);
	(*hp)->data = NULL;

	free(*hp);
	*hp = NULL;
}


//����
//������hp�ѣ�dataҪ�����ֵ
//ע�ͣ�data��Χ[INT_MIN+1,INT_MAX]
void InsertHeap(Heap hp,int data)
{
	if (hp == NULL)return;

	if (IsFullHeap(hp)==true)
	{
		printf("��������\n");
		return;
	}

	hp->data[hp->size+1] = data;
	hp->size++;

	ShiftUp(hp, hp->size);
}

//ɾ����СԪ
//������hp��
void DeletaMinHeap(Heap hp)
{
	if (hp == NULL)return;

	if (IsEmptyHeap(hp) == true)
	{
		printf("����Ϊ��\n");
		return;
	}

	hp->data[1] = hp->data[hp->size];
	hp->size--;

	ShiftDown(hp, 1);
}

//ɾ��ĳ���ڵ�
//������hp�ѣ�index��Ҫɾ���Ľڵ�����
//�޸ģ���������int����
void DeleteHeap(Heap hp,int index)
{
	ChangeHeap(hp, index,-10000-hp->data[index]);
	DeletaMinHeap(hp);
}


//�޸�
//������hp�ѣ�index�ڵ�����λ�ã�delta������С
//ע�ͣ�data��Χ[INT_MIN+1,INT_MAX]��delta��Χ[INT_MIN+1-data,INT_MAX-data]
//ע�ͣ�data��Χ[-10000,10000]��delta��Χ[-10000-data,10000-data]
void ChangeHeap(Heap hp, int index,int delta)
{
	if (hp == NULL)
		return;

	if (index <= 0)
	{
		printf("����С��0\n");
		return;
	}
	if (index > hp->size)
	{
		printf("�������ڶѴ�С\n");
		return;
	}

	int data = hp->data[index];

	/*if (delta < INT_MIN+1 - data)
	{
		printf("������С\n");
		return;
	}
	if (delta > INT_MAX - data)
	{
		printf("��������\n");
		return;
	}*/



	if (delta < -10000 - data)
	{
		printf("������С\n");
		printf("����������Χ��[%d,%d]", -10000 - data, 10000 - data);
		return;
	}
	if (delta > 10000 - data)
	{
		printf("��������\n");
		printf("����������Χ��[%d,%d]", -10000 - data, 10000 - data);
		return;
	}

	if (delta > 0)
	{
		hp->data[index] += delta;
		ShiftDown(hp, index);
	}
	else if(delta==0)
	{
		;
	}
	else if (delta < 0)
	{
		hp->data[index] += delta;
		ShiftUp(hp, index);
	}
}



//����
//������hp�ѣ�indexҪ���˵�����
void ShiftUp(Heap hp,int index)
{
	if (hp == NULL)return;
	if (index < 1||index>hp->size)return;

	int data = hp->data[index];

	while (1)
	{
		if (data < hp->data[index / 2])
		{
			hp->data[index] = hp->data[index / 2];
			index /= 2;
		}
		else
			break;
	}
	hp->data[index] = data;
}

//����
//������hp�ѣ�indexҪ���˵�����
void ShiftDown(Heap hp, int index)
{
	if (hp == NULL)return;
	if (index < 1||index>hp->size)return;

	int data = hp->data[index];
	int childIndex = 0;

	while (1)
	{
		if (index * 2 > hp->size)//����//Ҳ�����ò���
			break;
		else
		{
			childIndex = index * 2;
			if (index * 2 + 1 > hp->size)//���Һ�
			{
				;
			}
			else//���󺢺��Һ�
			{
				if (hp->data[childIndex + 1] < hp->data[childIndex])
					childIndex += 1;
			}

			if (hp->data[childIndex] < data)
			{
				hp->data[index] = hp->data[childIndex];
				index = childIndex;
			}
			else
				break;
		}
	}

	hp->data[index] = data;
}

//����

//�п�
//������hp��
bool IsEmptyHeap(Heap hp)
{
	if (hp == NULL)return false;

	if (hp->size <= 0)return true;
	else return false;
}

//����
//������hp��
bool IsFullHeap(Heap hp)
{
	if (hp == NULL)return false;

	if (hp->size >= hp->capacity)return true;
	else return false;
}

//���������������)
//�Թ���


//���������
//�Թ���
