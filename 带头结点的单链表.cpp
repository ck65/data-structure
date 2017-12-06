#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ElemType int        

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LNode* InitList_L(LinkList &L, int ms)    
{
	L = NULL;
	LinkList p;  
    int i, x;
	L = p = (LNode *)malloc(sizeof(LNode));
	for(i = 0; i < ms; i++)  
    {
		p->next = (LNode *)malloc(sizeof(LNode));  
        printf("Please input node data:");  
        scanf("%d", &x);  
        p->next->data = x; 
        p->next->next = NULL;  
        p = p->next;  
    }  
  
    return L;  
}//构造一个空的线性表
 
void DestroyList(LinkList &L)
{ 
  LinkList q;
  while(L) 
  { 
	  q=L->next;
	  free(L);
	  L=q;
  }
}//销毁线性表
 
void ClearList(LinkList L)
{
  LinkList p=L->next; 
  L->next=NULL;
  DestroyList(p);
}//重置线性表为空表
 
int ListEmpty_L(LinkList L)
{
	if(L ->next == NULL)
		return 1;
	else
		return 0;
}//判断是否为空表
 
int ListLength(LinkList L)
{
  int i=0;
  LinkList p=L->next;
  while(p)
  { 
	  i++;
	  p=p->next;
  }
  return i;
}//返回线性表元素个数
 
int GetElem(LinkList L,int i,ElemType &e)
{ 
  int j=1;
  LinkList p=L->next;
  while(p&&j<i)
  { 
	  j++;
	  p=p->next;
  }
  if(!p||j>i) 
    return 0;
  e=p->data;
  return 1;
}//返回第i个元素的值
 
LNode* LocateElem_L(LinkList L, ElemType e)
{
	LNode *p = L->next;
	while(p && p ->data != e)
		p = p ->next;
	return p;
}//查找元素
 
int PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
{
  LinkList q,p=L->next; 
  while(p->next)
  { q=p->next;
    if(q->data==cur_e)
    { 
		pre_e=p->data;
		return 1;
    }
    p=q;
  }
  return 0;
}//返回前驱
 
int NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
{ 
  LinkList p=L->next;
  while(p->next) 
  { 
	  if(p->data==cur_e)
	  { 
		  next_e=p->next->data;
		  return 1;
	  }
	  p=p->next;
  }
  return 0;
}//返回后继
 
int ListInsert(LinkList L,int i,ElemType e)
{ 
  int j=0;
  LinkList s,p=L; 
  while(p&&j<i-1)
  { 
	  j++;
	  p=p->next;
  }
  if(!p||j>i-1)
    return 0;
  s=(LinkList)malloc(sizeof(LNode));
  s->data=e;
  s->next=p->next;
  p->next=s;
  return 1;
}//插入元素
 
int ListDelete(LinkList L,int i,ElemType &e)
{
  int j=0;
  LinkList q,p=L;
  while(p->next&&j<i-1)
  { 
	  j++;
	  p=p->next;
  }
  if(!p->next||j>i-1)
    return 0;
  q=p->next;
  p->next=q->next;
  e=q->data;
  free(q);
  return 1;
}//删除元素
 
void ListTraverse(LinkList L,void(*visit)(ElemType))
{ 
  LinkList p=L->next;
  while(p)
  { 
	  visit(p->data);
	  p=p->next;
  }
  printf("\n");
}//输出元素


