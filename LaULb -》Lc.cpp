//以整数集合为例，实现算法2.1：求两个集合的并的运算。
#include "SqListFunc.cpp" // 采用线性表的顺序存储结构

void InputElement(SqList &L)   //输入集合元素到线性表L中
{
	int i, num, e;

	printf("num  = ");
	scanf("%d", &num);
	printf("elem = ");
	for(i = 1; i <= num; i++)
	{
		scanf("%d", &e);
		ListInsert_Sq(L, i, e);
	}
}

void Union(SqList &La, SqList &Lb, SqList &Lc)
{
    // 算法2.1：将线性表 Lb 中所有在 La 中不存在的数据元素插入到 La 中，算法执行结束后，线性表 Lb 不再存在
    ElemType e;
	int Lc_len = 0;          // 求线性表 La 的长度
    while (!ListEmpty_Sq(La)) {          // Lb 表的元素尚未处理完
       ListDelete_Sq(La, 1, e);          // 从 Lb 中删除第一个数据元素赋给 e
       if (!LocateElem_Sq(Lc, e))
		   ListInsert_Sq(Lc, ++Lc_len, e ); // 若La中不存在值和 e 相等的数据元素，则将它插入在La 中最后一个数据元素之后
      }
    while (!ListEmpty_Sq(Lb)) {          // Lb 表的元素尚未处理完
       ListDelete_Sq(Lb, 1, e);          // 从 Lb 中删除第一个数据元素赋给 e
       if (!LocateElem_Sq(Lc, e))
		   ListInsert_Sq(Lc, ++Lc_len, e ); // 若La中不存在值和 e 相等的数据元素，则将它插入在La 中最后一个数据元素之后
      }
      DestroyList_Sq(Lb);             // 销毁线性表 Lb
      DestroyList_Sq(La);
}

int main()
{
	SqList La, Lb,Lc;

	InitList_Sq(Lc);

	printf("************* Input A ***************\n");
	InitList_Sq(La);
	InputElement(La);

	printf("************* Input B ***************\n");
	InitList_Sq(Lb);
	InputElement(Lb);

	Union(La,Lb,Lc);

	printf("\n************* Result ****************\n");
	printf("A = {"); // 输出集合A
	ListTraverse_Sq(Lc);
	printf("}\n");
	printf("*************************************\n");

	DestroyList_Sq(Lc);
}
