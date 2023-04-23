#define _CRT_SECURE_NO_WARNINGS

#include"Heap.h"
#include"IO.h"

#include<stdlib.h>
#include<stdio.h>



//遍历
//参数：hp堆，f函数指针
void TraverseHeap(Heap hp, void(*f)(int num))
{
	if (hp == NULL)return;

	for (int i = 1; i <= hp->size; i++)
	{
		f(hp->data[i]);
	}
}
//文件交互


////刷新文件内容函数
////参数：filename要刷新的文件名
//void Refresh(const char fileName[20])
//{
//	FILE* file;
//	file = fopen(fileName, "w");
//	fclose(file);
//}

//输出（输出堆到文件Heap.txt中）
//参数：hp堆
void FprintHeap(Heap hp)
{
	FILE* fp;
	fp = fopen("Heap.txt", "a");

	fprintf(fp, "总共有%d个\n", hp->size);
	fprintf(fp, "堆容量：%d\n", hp->capacity);

	for (int i = 1; i <= hp->size; i++)
	{

		fprintf(fp,"第%d个：%d\n", i, hp->data[i]);
	}

	fclose(fp);
}

//展示文件信息
//参数：无
void ShowFileHeap(void)
{

	FILE* fp;
	fp = fopen("Heap.txt", "r");

	int flag = 0;

	int i = 0;
	int num = 0;
	int size = 0;
	int  capacity = 0;


	flag = fscanf(fp, "总共有%d个\n", &size);
	if (flag != 1)
	{
		printf("文件为空或文件不符合格式\n");
		return;
	}

	printf("总共有%d个\n", size);

	flag = fscanf(fp, "堆容量：%d\n", &capacity);
	if (flag != 1)
	{
		printf("文件不符合格式\n");
		return;
	}

	printf("堆容量：%d\n",capacity);

	while (1)
	{
		flag = fscanf(fp, "第%d个：%d\n", &i, &num);
		if (flag != 2)break;

		printf("第%d个：%d\n", i, num);
	}

	fclose(fp);
}

//录入（从文件Heap.txt中录入数据建造堆）
//参数:hp指针，返回建造好的堆，capacity堆的最大容量
//注释：capacity范围[1,INT_MAX]
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

	flag=fscanf(fp, "总共有%d个\n", &size);
	if (flag != 1)
	{
		printf("文件为空或无效，请选择选项1\n");
		return;
	}
	flag=fscanf(fp, "堆容量：%d\n", &capacity);
	if (flag != 1)
	{
		printf("文件无效，请选择选项1\n");
		return;
	}
	
	while(1)
	{
		printf("请输入堆的容量大小\n");
		printf("数字范围：[1,10000]\n");
		GetNumLimit(1, 10000, &scanfCapacity);

		if (scanfCapacity >= size)break;
		else
		{
			printf("堆容量小于数据量\n");
		}
	}

	int* array = (int*)malloc(size * sizeof(int));

	while (1)
	{
		flag = fscanf(fp, "第%d个：%d\n", &i,&num);
		if (flag != 2)break;

		array[i-1] = num;
	}

	BuildHeap(hp, scanfCapacity, array,size);

	free(array);
	array = NULL;

	fclose(fp);

	return ;
}

//打印
//参数：hp堆
void PrintHeap(Heap hp)
{
	if (hp == NULL)return;

	printf("总共有%d个\n", hp->size);
	printf("堆容量:%d\n", hp->capacity);
	
	for (int i = 1; i <= hp->size; i++)
	{
		printf("第%d个：%d\n",i,hp->data[i]);
	}
}


//初始化堆
//参数：hp指针，返回初始化后的堆，capacity堆容量  
//注释：capacity范围[1,INT_MAX]
void InitHeap(Heap *hp,int capacity)
{
	//
	if (capacity <= 0)
	{
		printf("堆容量小于等于0");
		return;
	}
	
	//不允许再次初始化（内存泄漏）
	//报错警告

	*hp = (Heap)malloc(sizeof(HeapNode));//误，已改
	(*hp)->data = (int*)malloc((capacity + 1) * sizeof(int));

	(*hp)->capacity = capacity;
	(*hp)->size = 0;
	
	(*hp)->data[0] = INT_MIN;
}


//建造堆（将一维数组录入，返回一个堆）
//参数：hp指针，返回建造好的堆，heapCapacity堆容量，array数组，arraysize数组大小
//注释：capacity范围[1,INT_MAX]，arraysize范围[1,INT_MAX]
void BuildHeap(Heap* hp,int heapCapacity,int array[],int arraySize)
{
	//法一：一直insert，不好，o（N）
	

	//if (arraySize <= 0)
	//{
	//	printf("数组大小小于等于0\n");
	//	return;
	//}

	/*if (heapCapacity < arraySize)
	{
		printf("堆容量小于数组大小\n");
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

//摧毁堆
//参数:hp堆
void DestroyHeap(Heap* hp)
{
	//(*hp)->capacity = 0;
	//(*hp)->size = 0;

	free((*hp)->data);
	(*hp)->data = NULL;

	free(*hp);
	*hp = NULL;
}


//插入
//参数：hp堆，data要插入的值
//注释：data范围[INT_MIN+1,INT_MAX]
void InsertHeap(Heap hp,int data)
{
	if (hp == NULL)return;

	if (IsFullHeap(hp)==true)
	{
		printf("超出容量\n");
		return;
	}

	hp->data[hp->size+1] = data;
	hp->size++;

	ShiftUp(hp, hp->size);
}

//删除最小元
//参数；hp堆
void DeletaMinHeap(Heap hp)
{
	if (hp == NULL)return;

	if (IsEmptyHeap(hp) == true)
	{
		printf("队列为空\n");
		return;
	}

	hp->data[1] = hp->data[hp->size];
	hp->size--;

	ShiftDown(hp, 1);
}

//删除某个节点
//参数：hp堆，index，要删除的节点索引
//修改：不适用于int型了
void DeleteHeap(Heap hp,int index)
{
	ChangeHeap(hp, index,-10000-hp->data[index]);
	DeletaMinHeap(hp);
}


//修改
//参数：hp堆，index节点所处位置，delta增量大小
//注释：data范围[INT_MIN+1,INT_MAX]，delta范围[INT_MIN+1-data,INT_MAX-data]
//注释：data范围[-10000,10000]，delta范围[-10000-data,10000-data]
void ChangeHeap(Heap hp, int index,int delta)
{
	if (hp == NULL)
		return;

	if (index <= 0)
	{
		printf("索引小于0\n");
		return;
	}
	if (index > hp->size)
	{
		printf("索引大于堆大小\n");
		return;
	}

	int data = hp->data[index];

	/*if (delta < INT_MIN+1 - data)
	{
		printf("增量过小\n");
		return;
	}
	if (delta > INT_MAX - data)
	{
		printf("增量过大\n");
		return;
	}*/



	if (delta < -10000 - data)
	{
		printf("增量过小\n");
		printf("合理增量范围：[%d,%d]", -10000 - data, 10000 - data);
		return;
	}
	if (delta > 10000 - data)
	{
		printf("增量过大\n");
		printf("合理增量范围：[%d,%d]", -10000 - data, 10000 - data);
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



//上滤
//参数：hp堆，index要上滤的索引
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

//下滤
//参数：hp堆，index要下滤的索引
void ShiftDown(Heap hp, int index)
{
	if (hp == NULL)return;
	if (index < 1||index>hp->size)return;

	int data = hp->data[index];
	int childIndex = 0;

	while (1)
	{
		if (index * 2 > hp->size)//无左孩//也可以用层数
			break;
		else
		{
			childIndex = index * 2;
			if (index * 2 + 1 > hp->size)//无右孩
			{
				;
			}
			else//有左孩和右孩
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

//交换

//判空
//参数：hp堆
bool IsEmptyHeap(Heap hp)
{
	if (hp == NULL)return false;

	if (hp->size <= 0)return true;
	else return false;
}

//判满
//参数：hp堆
bool IsFullHeap(Heap hp)
{
	if (hp == NULL)return false;

	if (hp->size >= hp->capacity)return true;
	else return false;
}

//堆排序（数组变数组)
//略过。


//增大堆容量
//略过。
