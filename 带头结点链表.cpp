#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;


//构造一个空的线性表L;
void InitList_HL(LinkList &L)
{
	L->next=NULL;
}


//销毁线性表L;
void DestroyList_HL(LinkList &L)
{
	LNode *p;
	while(L)
	{
		p->next=L;
		delete L;
		L=p;
	}
}


//将L重置为空表;
void ClearList_HL(LinkList &L)
{
	LNode *p;
	p = L->next;
	L->next = NULL;
	while(L)
	{
		p->next=L;
		delete L;
		L=p;
	}
}


//判断L是否为空;
bool ListEmpty_HL(LinkList L)
{
	if(L->next==NULL)
		return true;
	else
		return false;
}


//线性表L的长度;
int ListLength_HL(LinkList L)
{
	LinkList p=L->next;
	int i=0;
	while(p)
	{
		p=p->next;
		i++;
	}
	return i;
}


//用e返回L中第i个元素的值
int GetElem_HL(LinkList L,int i,int &e)
{
	LinkList p=L->next;
	if(i<1)
		exit(0);
	for(int j=1;p!=NULL&&j<i;j++)
		p=p->next;
	e=p->data;
	return e;
}


//返回L中第1个其值与e相等的元素的位序,若这样的元素不存在，则返回值为0
LNode* LocateElem_HL(LinkList L,
                     int e)
{
	LinkList p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;
}


//用pre_e返回cur_e的前驱,若操作失败，pre_e无定义;
int PriorElem_HL(LinkList L,int cur_e,int &pre_e)
{
	LinkList p=L->next;
	LNode *q;
	if(p!=NULL)
	{
		q=p->next;
		if(q&&q->data==cur_e)
		{
			pre_e=p->data;
			return pre_e;
		}
		p=q;
	}
	else
		return false;
}


//用next_e返回cur_e的后继,若操作失败，next_e无定义;
int NextElem_HL(LinkList L,int cur_e,int &next_e)
{
	LinkList p=L->next;
	LNode *q;
	q=p->next;
	if(q!=NULL&&p->data==cur_e)
	{
		next_e=q->data;
		return next_e;
	}
	p=q;
	if(q==NULL)
		return false;
}


//在第p个元素之前，插入新的元素;
void ListInsert_HL(LinkList &L,LNode *p,LNode *s)
{
	LNode *q;
	if(p==L->next)
	{
		s->next=L->next;
		L=s;
	}
	else
	{
		q=L;
		while(q->next!=p)
			q=q->next;
		q->next=s;
		s->next=p;
	}
}


//删除某个元素;
void ListDelete_HL(LinkList &L,LNode *p,int &e)
{
	LNode *q;
	if(p==L->next)
	{
		L->next=p->next;
	}
	else
	{
		q=L;
		while(q->next!=p)
			q=q->next;
	}
	e=p->data;
	delete p;
}


//依次输出L中的每个数据元素；
void ListTraverse_HL(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		cout<<p->data<<"/t";
		p=p->next;
	}
}
