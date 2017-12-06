 #include <stdio.h>
 #include <stdlib.h>
 typedef int ElemType;
 typedef int Boolean;

 #define TRUE 1
 #define FALSE 0

 /*           线性表的单链表存储结构                    */

 typedef struct LNode
 {
	 ElemType data;
	 struct LNode *next;
 }LNode, *LinkList;        // 教材上的定义


 /*带头结点的单链表的基本操作(12个)*/
 void InitList_L(LinkList &L)
 {
	 L = new LNode;
	 if(!L)
		 exit(-1);
	 L->next = NULL;
 }

 void DestroyList_L(LinkList &L)
 {
	 LinkList q;
	 while(L)
	 {
		 q = L->next;
		 free(L);
		 L = q;
	 }
 }

 void ClearList_L(LinkList &L)
 {
	 LinkList p,q;
	 p = L->next;
	 while(p)
	 {
		 q = p->next;
		 free(p);
		 p = q;
	 }
	 L->next = NULL;
 }

 Boolean ListEmpty_L(LinkList L)
 {
	 if(L->next)
		 return FALSE;
	 else
		 return TRUE;
 }

 int ListLength_L(LinkList L)
 {
    LinkList p = L->next;
	 int k = 0;
	 while(p)
	 {
		 k++;
		 p = p->next;
	 }
	 return k;
 }

 void GetElem_L(LinkList L,int i,ElemType &e)
 {
	 int j;
	 LinkList p;

	 if(i < 1)
	 {
		 printf("i小于1，不 f合法！\n");
		 exit(-1);
	 }

	 p = L->next; // p指向第一个结点
	 j = 1;
	 while(p && j<i) // 顺指针向后查找,直到p指向第i个元素或p为空
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p) // 第i个元素不存在
	 {
		 printf("第i个元素不存在！\n");
		 exit(-1);
	 }
	 e = p->data; // 取第i个元素
 }

 LNode* LocateElem_L(LinkList L,ElemType e)  // 算法2.15
 {
      LinkList p = L->next;
      while ( p && p->data!=e )
		  p = p->next;
      return p;
 }

 void PriorElem_L(LinkList L,ElemType cur_e,ElemType &pre_e)
 {
	 LinkList q, p = L->next;
	 while(p && p->next)
	 {
		 q = p->next;
		 if(q->data == cur_e)
		 {
			 pre_e = p->data;
			 exit(0);
		 }
		 p = q;
	 }
	 printf("无所要查找的前驱元素！\n");
 }

 void NextElem_L(LinkList L,ElemType cur_e,ElemType &next_e)
 {
	 LinkList p = L->next;
	 while(p && p->next)
	 {
		 if(p->data == cur_e)
		 {
			 next_e = p->next->data;
			 exit(0);
		 }
		 p = p->next;
	 }
	 printf("无所要查找的后继元素！\n");
 }


 void ListInsert_L( LinkList &L, LNode *p, LNode *s )
 {
	 LNode *q = L;

	 while (q->next != p )
		 q = q->next;
	 q->next = s;
	 s->next = p;
 } // ListInsert_L


 void ListInsert_L_E(LinkList &L,int i,ElemType e)
 {
	 LinkList p = L, q;
	 int  j = 0;

	 if(i < 1)
	 {
		 printf("i小于1，插入位置不合法！\n");
		 exit(-1);
	 }

	 while(p && j<i-1)
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p)
	 {
		 printf("i>Listlength(L)+1，插入位置不合法！\n");
		 exit(-1);
	 }

	 q = new LNode; // 生成新结点
	 q->data = e; // 插入L中
	 q->next = p->next;
	 p->next = q;
 }

 void ListDelete_L( LinkList &L, LNode* p, ElemType &e ) // 算法 2.17修改
 {
	 LNode *q = L;

	 while (q->next != p )
		 q = q->next;
	 q->next = p->next;
	 e = p->data;
	 delete p;
 }

 void ListDelete_L_E(LinkList L,int i,ElemType &e) // 算法2.17扩充
 {
	 LinkList p = L, q;
	 int  j = 0;

	 if(i < 1)
	 {
		 printf("i小于1，删除位置不合法！\n");
		 exit(-1);
	 }


	 while(p && j<i-1)       // 从头结点开始向后查找,直到p指向第i-1个元素或p为空
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p->next || !p)      // p最多只能到链表的倒数第二个结点，此时p已到链尾或为链尾的空指针
	 {
		 printf("i>Listlength(L)，删除位置不合法！\n");
		 exit(-1);
	 }

	 q = p->next; // 删除并释放结点
	 p->next = q->next;
	 e = q->data;
	 free(q);
 }

 void ListTraverse_L(LinkList L)
 {
	 LinkList p = L->next;
	 while(p)
	 {
		 printf("%d",(p->data));
		 p = p->next;
	 }
 }
