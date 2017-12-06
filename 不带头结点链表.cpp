#include<iostream>
#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int n;
    struct Node *next;
}Node, *LinkList;


//创建空链表
void InitList_HL(LinkList &L)
{
	L->next=NULL;
}



//在L和p之间插入s
void ListInsert_HL(LinkList &L,Node *p,Node *s)
{
	Node *q;
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
//打印链表中的数据
void print(LinkList pL)
{
    if(!pL)
      printf("空!");
    else
    {
        while(pL)
        {
            printf("%d ",pL->n);
            pL = pL->next;
        }
    }
    printf("\n");
}
//链表长度
int ListLength(LinkList L)
{
    LinkList p=L;
    int t =0;
    while(p)
    {
        t++;
        p=p->next;
    }
    return t;
}

//查找
LinkList LocateElem(LinkList L,int e)
{
    LinkList p=L;
    while(p&&p->n!=e)p=p->next;
    return p;
}
//删除节点
void ListDetele(LinkList &L,Node *p ,int &e)
{
    if (p==L)
    {
        L=p->next;
    }
    else {
        Node *q=L;
        while(q->next!=p)q=q->next;
        q->next=p->next;
    }
    e=p->n;
    delete p;
}
//删除链表
void delList(LinkList *pL)
{
    Node *tmp;
    Node *p = *pL;
    while(p)
    {
        tmp = p->next;
        printf("%d\n",p->n);
        free(p);
        p = tmp;
    }
    *pL = NULL;
}

//判断表空
int ListEmpty(LinkList L)
{
    if(L->next==NULL)
        return 1;
    else
        return 0;
}

void PriorElem(LinkList L,int cur_e,int &pre_e)
{
    LinkList p,q;
    p=L;
    while(q->next)
    {
        p=q->next;
        if(p->n=cur_e)
            pre_e=q->n;
        else
            q=p;
    }
}

void NextElem(LinkList L,int cur_e,int &next_e)
{
    LinkList p,q,next;
    p=L;
    while(q->next)
    {
        p=q->next;
        if(p->n=cur_e)
           {
            next=p->next;
            next_e=next->n;
           }
        else
            q=p;
}
}
