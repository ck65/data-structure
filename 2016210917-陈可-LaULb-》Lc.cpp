//����������Ϊ����ʵ���㷨2.1�����������ϵĲ������㡣
#include "SqListFunc.cpp" // �������Ա��˳��洢�ṹ

void InputElement(SqList &L)   //���뼯��Ԫ�ص����Ա�L��
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
    // �㷨2.1�������Ա� Lb �������� La �в����ڵ�����Ԫ�ز��뵽 La �У��㷨ִ�н��������Ա� Lb ���ٴ���
    ElemType e;
	int Lc_len = 0;          // �����Ա� La �ĳ���
    while (!ListEmpty_Sq(La)) {          // Lb ���Ԫ����δ������
       ListDelete_Sq(La, 1, e);          // �� Lb ��ɾ����һ������Ԫ�ظ��� e
       if (!LocateElem_Sq(Lc, e))
		   ListInsert_Sq(Lc, ++Lc_len, e ); // ��La�в�����ֵ�� e ��ȵ�����Ԫ�أ�����������La �����һ������Ԫ��֮��
      }
    while (!ListEmpty_Sq(Lb)) {          // Lb ���Ԫ����δ������
       ListDelete_Sq(Lb, 1, e);          // �� Lb ��ɾ����һ������Ԫ�ظ��� e
       if (!LocateElem_Sq(Lc, e))
		   ListInsert_Sq(Lc, ++Lc_len, e ); // ��La�в�����ֵ�� e ��ȵ�����Ԫ�أ�����������La �����һ������Ԫ��֮��
      }
      DestroyList_Sq(Lb);             // �������Ա� Lb
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
	printf("A = {"); // �������A
	ListTraverse_Sq(Lc);
	printf("}\n");
	printf("*************************************\n");

	DestroyList_Sq(Lc);
}
