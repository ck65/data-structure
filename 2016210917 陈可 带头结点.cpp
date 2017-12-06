#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;


//����һ���յ����Ա�L;
void InitList_HL(LinkList &L)
{
	L->next=NULL;
}


//�������Ա�L;
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


//��L����Ϊ�ձ�;
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


//�ж�L�Ƿ�Ϊ��;
bool ListEmpty_HL(LinkList L)
{
	if(L->next==NULL)
		return true;
	else
		return false;
}


//���Ա�L�ĳ���;
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


//��e����L�е�i��Ԫ�ص�ֵ
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


//����L�е�1����ֵ��e��ȵ�Ԫ�ص�λ��,��������Ԫ�ز����ڣ��򷵻�ֵΪ0
LNode* LocateElem_HL(LinkList L,
                     int e)
{
	LinkList p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;
}


//��pre_e����cur_e��ǰ��,������ʧ�ܣ�pre_e�޶���;
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


//��next_e����cur_e�ĺ��,������ʧ�ܣ�next_e�޶���;
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


//�ڵ�p��Ԫ��֮ǰ�������µ�Ԫ��;
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


//ɾ��ĳ��Ԫ��;
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


//�������L�е�ÿ������Ԫ�أ�
void ListTraverse_HL(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		cout<<p->data<<"/t";
		p=p->next;
	}
}
