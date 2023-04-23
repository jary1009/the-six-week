#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct HeapNode
{
	int capacity;
	int size;
	int* data;
}HeapNode,*Heap;

//����
//������hp�ѣ�f����ָ��
void TraverseHeap(Heap hp, void(*f)(int num));


//�ļ�����


////ˢ���ļ����ݺ���
////������filenameҪˢ�µ��ļ���
//void Refresh(const char fileName[20]);

//���������ѵ��ļ�Heap.txt�У�
//������hp��
void FprintHeap(Heap hp);

//¼�루���ļ�Heap.txt��¼�����ݽ���ѣ�
//����:hpָ�룬���ؽ���õĶ�
//ע�ͣ�capacity��Χ[1,INT_MAX]
void FscanfHeap(Heap* hp);

//չʾ�ļ���Ϣ
//��������
void ShowFileHeap(void);


//��ӡ
//������hp��
void PrintHeap(Heap hp);


//��ʼ����
//������hpָ�룬���س�ʼ����Ķѣ�capacity������  
//ע�ͣ�capacity��Χ[1,INT_MAX]
void InitHeap(Heap* hp, int capacity);


//����ѣ���һά����¼�룬����һ���ѣ�
//������hpָ�룬���ؽ���õĶѣ�heapCapacity��������array���飬arraysize�����С
//ע�ͣ�capacity��Χ[1,INT_MAX]��arraysize��Χ[1,INT_MAX]
void BuildHeap(Heap* hp, int heapCapacity, int array[], int arraySize);

//�ݻٶ�
//����:hp��
void DestroyHeap(Heap* hp);

//����
//������hp�ѣ�dataҪ�����ֵ
//ע�ͣ�data��Χ[INT_MIN+1,INT_MAX]
void InsertHeap(Heap hp, int data);


//ɾ����СԪ
//������hp��
void DeletaMinHeap(Heap hp);

//ɾ��ĳ���ڵ�
//������hp�ѣ�index��Ҫɾ���Ľڵ�����
void DeleteHeap(Heap hp, int index);

//�޸�
//������hp�ѣ�index�ڵ�����λ�ã�delta������С
//ע�ͣ�data��Χ[INT_MIN+1,INT_MAX]��delta��Χ[INT_MIN+1-data,INT_MAX-data]
void ChangeHeap(Heap hp, int index,int delta);

//����
//������hp�ѣ�indexҪ���˵�����
void ShiftUp(Heap hp, int index);


//����
//������hp�ѣ�indexҪ���˵�����
void ShiftDown(Heap hp, int index);


//�п�
//������hp��
bool IsEmptyHeap(Heap hp);

//����
//������hp��
bool IsFullHeap(Heap hp);




#endif // !__HEAP_H__