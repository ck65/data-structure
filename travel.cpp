#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
const int MAXSIZE=100;

typedef struct BiTNode
{
	char   date;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void InitBiTree(BiTree &T){
	T=NULL;
}

void CrateBiTree(BiTree &T){
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else {
		T=new BiTNode;
		T->date=ch;
        CrateBiTree(T->lchild);
        CrateBiTree(T->rchild);
	}
}

void Preoder(BiTree T, void( *print)(BiTree)){
	if(T){
		print(T);
		Preoder(T->lchild,print);
		Preoder(T->rchild,print);
	}
}

void Preoder2(BiTree T, void( *print)(BiTree)){
	if(T){
		Preoder(T->lchild,print);
		print(T);
		Preoder(T->rchild,print);
	}
}

void Preoder3(BiTree T, void( *print)(BiTree)){
	if(T){
		Preoder(T->lchild,print);
		Preoder(T->rchild,print);
		print(T);
	}
}

void Preoder4(BiTree T, void( *print)(BiTree)){
     queue<BiTree> q;
        if(T)
        {
             q.push(T);
             while(!q.empty())
               {
                 BiTree R;
                 R = q.front();
                 print(R);
                 q.pop();
                 if(R -> lchild)
                    q.push(R -> lchild);
if(R -> rchild)
                     q.push(R -> rchild);
                }
        }
  }

void destoryBiTree(BiTree T){
	if(T){
		destoryBiTree(T->lchild);
		destoryBiTree(T->rchild);
		delete T;
        T=NULL;
	}
}


void print(BiTree T){
	printf("%c",T->date);
}

int main()
{
	BiTree T;
	InitBiTree(T);
	printf("input the binary tree:\n");
	CrateBiTree(T);
	printf("--------------------------\n");
	printf("\n---------先序遍历---------\n");
    Preoder(T,print);
    printf("\n=========中序遍历=========\n");
    Preoder2(T,print);
    printf("\n---------后序遍历---------\n");
    Preoder3(T,print);
    printf("\n---------层次遍历---------\n");
    Preoder4(T,print);

	return 0;
}
