//2016210817 毛凯
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define ERROR -1
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;//LinkList是LNode类型的指针

//初始化线性表
void InitList_L(LinkList &L)
{
    L=NULL;
}

//求线性表的长度
ElemType ListLength_L(LinkList L)
{
    LNode *p;
    ElemType k;
    p=L;k=0;
    while(p)
    {
        k++;
        p=p->next;
    }
    return k;
}

//查找元素操作
LNode *LocateElem_L(LinkList L,ElemType e)//返回值为指向数据域值为e的结点指针
{
    LNode  *p;
    p=L;
    while(p&&p->data!=e)
        p=p->next;
    return(p);
}

//插入结点操作
void ListInsert_L(LinkList &L,LNode *p,LNode *s,char mode)
{
    if(p==L)     //将s节点插到最前
    {
        s->next=L;
        L=s;
    }
    if(mode=='A')//后插
    {
        s->next=p->next;
        p->next=s;
    }
    LNode *q;    //前插
    q=L;
    while(q->next!=p)
        q=q->next;
    q->next=s;
    s->next=p;
}

//删除结点操作
void ListDelete_L(LinkList &L,LNode *p,ElemType &e)
{
    if(p==L)
        L=p->next;
    else
    {
        LNode*q;
        q=L;
        while(q->next!=p)
            q=q->next;
        q->next=p->next;
    }
    e=p->data;
    free(p);
}

//销毁线性表
void DestoryList_L(LinkList &L)
{
    LNode *p;
    while(L)
    {
        p=L->next;
        free(L);
        L=p;
    }
}

//清空链表
void ClearList_L(LinkList L)//因为改变的是L的值，没有改变L
{
    LNode *p=L;
    LNode *pNext;
    while(p->next!=NULL)
        pNext=p->next;
        free(p);
        p=pNext;
}

//判断链表是否为空
ElemType ListEmpty_L(LinkList L)
{
    if(L)
       return ERROR;
    else
        return TRUE;

}

//取元素
ElemType GetElem_L(LinkList L, ElemType i, ElemType &e)
{
    int j=1;
    LNode *p=L;
    if(i<1||i>ListLength_L(L))
        return(-1);
    while(j<i&&p)
    {
        j++;
        p=p->next;
    }
    if(j==i)
    {
        e=p->data;
        return 1;
    }
}

//遍历
void TravelList_L(LinkList L)
{
    int j=0;
    LNode *p=L;
    while(p)
    {
        ++j;
        printf("第%d个结点的值为：%d\n",j,p->data);
        p=p->next;
    }
}
//查找前驱
ElemType PriorElem_L(LinkList L,ElemType now_e,ElemType pri_e)
{
    LNode *p=L;
    LNode *q;
    while(p)
    {
        q=p->next;
        if(q&&q->data==now_e)
         {
             pri_e=p->data;
                return(pri_e);
         }
          p=q;
    }

}
//求后继
ElemType NextElem_L(LinkList L,ElemType now_e,ElemType next_e)
{
    LNode *p=L;
    LNode *q;
    while(p)
    {
        q=p->next;
        if(q&&p->data==now_e)
        {
            next_e=q->data;
            return(next_e);
        }
    }
    p=q;
}

int main()
{
    return 0;
}

