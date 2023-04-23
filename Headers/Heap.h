#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct HeapNode
{
	int capacity;
	int size;
	int* data;
}HeapNode,*Heap;

//遍历
//参数：hp堆，f函数指针
void TraverseHeap(Heap hp, void(*f)(int num));


//文件交互


////刷新文件内容函数
////参数：filename要刷新的文件名
//void Refresh(const char fileName[20]);

//输出（输出堆到文件Heap.txt中）
//参数：hp堆
void FprintHeap(Heap hp);

//录入（从文件Heap.txt中录入数据建造堆）
//参数:hp指针，返回建造好的堆
//注释：capacity范围[1,INT_MAX]
void FscanfHeap(Heap* hp);

//展示文件信息
//参数：无
void ShowFileHeap(void);


//打印
//参数：hp堆
void PrintHeap(Heap hp);


//初始化堆
//参数：hp指针，返回初始化后的堆，capacity堆容量  
//注释：capacity范围[1,INT_MAX]
void InitHeap(Heap* hp, int capacity);


//建造堆（将一维数组录入，返回一个堆）
//参数：hp指针，返回建造好的堆，heapCapacity堆容量，array数组，arraysize数组大小
//注释：capacity范围[1,INT_MAX]，arraysize范围[1,INT_MAX]
void BuildHeap(Heap* hp, int heapCapacity, int array[], int arraySize);

//摧毁堆
//参数:hp堆
void DestroyHeap(Heap* hp);

//插入
//参数：hp堆，data要插入的值
//注释：data范围[INT_MIN+1,INT_MAX]
void InsertHeap(Heap hp, int data);


//删除最小元
//参数；hp堆
void DeletaMinHeap(Heap hp);

//删除某个节点
//参数：hp堆，index，要删除的节点索引
void DeleteHeap(Heap hp, int index);

//修改
//参数：hp堆，index节点所处位置，delta增量大小
//注释：data范围[INT_MIN+1,INT_MAX]，delta范围[INT_MIN+1-data,INT_MAX-data]
void ChangeHeap(Heap hp, int index,int delta);

//上滤
//参数：hp堆，index要上滤的索引
void ShiftUp(Heap hp, int index);


//下滤
//参数：hp堆，index要下滤的索引
void ShiftDown(Heap hp, int index);


//判空
//参数：hp堆
bool IsEmptyHeap(Heap hp);

//判满
//参数：hp堆
bool IsFullHeap(Heap hp);




#endif // !__HEAP_H__