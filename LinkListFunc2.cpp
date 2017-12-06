//2016210817 ë��
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define ERROR -1
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;//LinkList��LNode���͵�ָ��

//��ʼ�����Ա�
void InitList_L(LinkList &L)
{
    L=NULL;
}

//�����Ա�ĳ���
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

//����Ԫ�ز���
LNode *LocateElem_L(LinkList L,ElemType e)//����ֵΪָ��������ֵΪe�Ľ��ָ��
{
    LNode  *p;
    p=L;
    while(p&&p->data!=e)
        p=p->next;
    return(p);
}

//���������
void ListInsert_L(LinkList &L,LNode *p,LNode *s,char mode)
{
    if(p==L)     //��s�ڵ�嵽��ǰ
    {
        s->next=L;
        L=s;
    }
    if(mode=='A')//���
    {
        s->next=p->next;
        p->next=s;
    }
    LNode *q;    //ǰ��
    q=L;
    while(q->next!=p)
        q=q->next;
    q->next=s;
    s->next=p;
}

//ɾ��������
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

//�������Ա�
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

//�������
void ClearList_L(LinkList L)//��Ϊ�ı����L��ֵ��û�иı�L
{
    LNode *p=L;
    LNode *pNext;
    while(p->next!=NULL)
        pNext=p->next;
        free(p);
        p=pNext;
}

//�ж������Ƿ�Ϊ��
ElemType ListEmpty_L(LinkList L)
{
    if(L)
       return ERROR;
    else
        return TRUE;

}

//ȡԪ��
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

//����
void TravelList_L(LinkList L)
{
    int j=0;
    LNode *p=L;
    while(p)
    {
        ++j;
        printf("��%d������ֵΪ��%d\n",j,p->data);
        p=p->next;
    }
}
//����ǰ��
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
//����
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

