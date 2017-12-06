 #include <stdio.h>
 #include <stdlib.h>
 typedef int ElemType;
 typedef int Boolean;

 #define TRUE 1
 #define FALSE 0

 /*           ���Ա�ĵ�����洢�ṹ                    */

 typedef struct LNode
 {
	 ElemType data;
	 struct LNode *next;
 }LNode, *LinkList;        // �̲��ϵĶ���


 /*��ͷ���ĵ�����Ļ�������(12��)*/
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
		 printf("iС��1���� f�Ϸ���\n");
		 exit(-1);
	 }

	 p = L->next; // pָ���һ�����
	 j = 1;
	 while(p && j<i) // ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ��
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p) // ��i��Ԫ�ز�����
	 {
		 printf("��i��Ԫ�ز����ڣ�\n");
		 exit(-1);
	 }
	 e = p->data; // ȡ��i��Ԫ��
 }

 LNode* LocateElem_L(LinkList L,ElemType e)  // �㷨2.15
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
	 printf("����Ҫ���ҵ�ǰ��Ԫ�أ�\n");
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
	 printf("����Ҫ���ҵĺ��Ԫ�أ�\n");
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
		 printf("iС��1������λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 while(p && j<i-1)
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p)
	 {
		 printf("i>Listlength(L)+1������λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 q = new LNode; // �����½��
	 q->data = e; // ����L��
	 q->next = p->next;
	 p->next = q;
 }

 void ListDelete_L( LinkList &L, LNode* p, ElemType &e ) // �㷨 2.17�޸�
 {
	 LNode *q = L;

	 while (q->next != p )
		 q = q->next;
	 q->next = p->next;
	 e = p->data;
	 delete p;
 }

 void ListDelete_L_E(LinkList L,int i,ElemType &e) // �㷨2.17����
 {
	 LinkList p = L, q;
	 int  j = 0;

	 if(i < 1)
	 {
		 printf("iС��1��ɾ��λ�ò��Ϸ���\n");
		 exit(-1);
	 }


	 while(p && j<i-1)       // ��ͷ��㿪ʼ������,ֱ��pָ���i-1��Ԫ�ػ�pΪ��
	 {
		 p = p->next;
		 j++;
	 }
	 if(!p->next || !p)      // p���ֻ�ܵ�����ĵ����ڶ�����㣬��ʱp�ѵ���β��Ϊ��β�Ŀ�ָ��
	 {
		 printf("i>Listlength(L)��ɾ��λ�ò��Ϸ���\n");
		 exit(-1);
	 }

	 q = p->next; // ɾ�����ͷŽ��
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
