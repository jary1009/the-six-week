#ifndef __IO_H__
#define __IO_H__



//获取数字
//参数：result指针，返回获得的数字
bool GetNum(int* result);

//获取有范围的数字
//参数：min，max数字的最大最小值（可以等于），result指针，返回获得的数字
bool GetNumLimit(int min, int max, int* result);

//获取字符串，大小限制
//参数：string指针，返回获取的字符串，size字符串字符个数
bool GetStringLimitNum(char* string, int size);

//获取字符串，大小和字符限制
//参数：string指针，返回获取的字符串，size字符串字符个数，legalChar字符数组，里面存放合法字符
bool GetStringLimitNumChar(char* string, int size, char* legalChar);




#endif // !__IO_H__

