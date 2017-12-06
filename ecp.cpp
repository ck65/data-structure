#include "LinkListFunc.cpp"

void Inputn(LinkList &L){
	int i, num, e;
	printf("input the num:");
	scanf("%d",&num);
	for(i=1;i <= num;i++)
	{
		scanf("%d",&e);
		ListInsert_L_E(L,i,e);
	}
}

void Union(LinkList La,LinkList Lb,LinkList &Lc){
	int i,j=0;
	ElemType e;
	for(i=1;i<=ListLength_L(La);i++){
		GetElem_L(La,i,e);
		j++;
		ListInsert_L_E(Lc,j,e);
	}
	for (i = 1; i <= ListLength_L(Lb); i++)
	{
		GetElem_L(Lb,i,e);
		if(LocateElem_L(Lc,e))
			continue;
		j++;
		ListInsert_L_E(Lc,j,e);
	}
}

void Inter(LinkList La, LinkList Lb, LinkList &Lc){
	int i,j;
	j=0;
	ElemType e;
	for(i=1;i<=ListLength_L(La);i++){
		GetElem_L(La,i,e);
			if(LocateElem_L(Lb,e)){
				j++;
				ListInsert_L_E(Lc,j,e);
			}

	}
}

void Sub(LinkList La, LinkList Lb, LinkList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_L(La); i++)
	{
		GetElem_L(La, i, e);
		if (!LocateElem_L(Lb, e))
		{
			j++;
			ListInsert_L_E(Lc, j, e);
		}
	}
}



int main()
{
	LinkList La, Lb, Lc, Ld, Le, Lf;

	printf("************* Input A ***************\n");
	InitList_L(La);
	Inputn(La);

	printf("************* Input B ***************\n");
	InitList_L(Lb);
	Inputn(Lb);

	InitList_L(Lc);
	Union(La,Lb,Lc);

	InitList_L(Ld);
	Inter(La,Lb,Ld);

	InitList_L(Le);
	Sub(La,Lb,Le);

	InitList_L(Lf);
	Sub(Lb,La,Lf);

	printf("\n************* Result ****************\n");

    printf("\n************* A ****************\n");
	ListTraverse_L(La);
    printf("\n************* B ****************\n");
	ListTraverse_L(Lb);
	printf("\n************* AUB ****************\n");
	ListTraverse_L(Lc);
    printf("\n************* A*B ****************\n");
	ListTraverse_L(Ld);
    printf("\n************* A-B ****************\n");
	ListTraverse_L(Le);
    printf("\n************* B-A ****************\n");
	ListTraverse_L(Lf);

	DestroyList_L(La);
	DestroyList_L(Lb);
	DestroyList_L(Lc);
	DestroyList_L(Ld);
	DestroyList_L(Le);
	DestroyList_L(Lf);
	return 0;
}

