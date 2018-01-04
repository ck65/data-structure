#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef struct {
  int xpos;
  int ypos;
}PostType;

typedef PostType SElemType;

typedef struct
{
	SElemType *elem;
	int top;
	int stacksize;
	int incrementsize;
}SqStack;

void InitStack(SqStack &S)
{
	S.elem = new SElemType[100];
	S.top = -1;
	S.stacksize = 100;
}

int Push(SqStack &S, SElemType e)
{
	S.elem[++S.top] = e;
	return 1;
}

int Pop(SqStack &S, SElemType &e)
{
	if(S.top == -1)
		return 0;
	else
		e = S.elem[S.top--];
	return 1;
}
int EmptyStack(SqStack S)
{
	if(S.top == -1)
		return 1;
	else
		return 0;
}

void destroyStack(SqStack &S){
     S.top=NULL;
     S.stacksize=0;
     delete []S.elem;
}


typedef struct DQNode{
  PostType seat;
  struct DQNode *next;
  struct DQNode *pre;
}DQNode, *DqueuePtr;

typedef struct {
  DqueuePtr front;
  DqueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
  Q.front = NULL;
  Q.rear  = NULL;
}

void EnQueue(LinkQueue &Q, PostType e){
  DQNode *p=new DQNode;
  p->seat.xpos=e.xpos;
  p->seat.ypos=e.ypos;
  p->next=NULL;
  if(!Q.rear){
    p->pre=NULL;
    Q.rear=p;
    Q.front=p;//the first node.
  }else{
    p->pre=Q.front;
    Q.rear->next=p;
    Q.rear=p;
  }
}//EnQueue

void GetHead(LinkQueue Q, PostType &e ){
  e.xpos=Q.front->seat.xpos;
  e.ypos=Q.front->seat.ypos;
}

void DeQueue(LinkQueue &Q){
  Q.front=Q.front->next;
}

 bool QueueEmpty(LinkQueue Q){
   return (Q.front == NULL);
 }


int ShorteatPath(SqStack &S){
  LinkQueue Q;
  int m=6;
  int n=8;
  int maze[6][8];
  InitQueue(Q);
  int i,j,v;
  bool found;
  printf("input the size (m*n):");
  	scanf("%d %d",&m,&n);
  DqueuePtr p;
  PostType curpos,npos,e;

    int visited[100][100];
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++){
            scanf("%d",&maze[i][j]);
         //printf("%d\n",maze[i][j]);
        }

  for(i =0 ; i<=m; i++){
    for(j=0;j<n;j++){
        visited[i][j]=0;
        }
  }//标志数组初始化

  //printf("%d",maze[0][0]);
  if(maze[0][0]!=0)
    return 0;

  e.xpos=0;
  e.ypos=0;
  EnQueue(Q,e);//maze[0][0]入队列

  found = 0;//标志变量是否找到
  while(!found && !QueueEmpty(Q)){
    GetHead(Q, curpos);
    for(v=0; v<8&&!found;v++){
            npos.xpos = dx[v] + curpos.xpos;
            npos.ypos = dy[v] + curpos.ypos;
        if((npos.xpos >= 0) && (npos.xpos <= m-1) && (npos.ypos >= 0) && (npos.ypos <= n-1) && (maze[npos.xpos][npos.ypos] == 0) && (visited[npos.xpos][npos.ypos] == 0))
            {
                EnQueue(Q, npos);
                //printf("1");
                visited[npos.xpos][npos.ypos] = 1;
            }
        if((npos.xpos==m-1) && (npos.ypos==n-1))
            {
                found =1;
            }
    }//for
    DeQueue(Q);
  }//while
  if(found){
    InitStack(S);
    p=Q.rear;
    while(p){
      Push(S,p->seat);
      p=p->pre;
    }
    return 1;
  }
  else
    return 0;
}


int main()
{
	SqStack S;
	InitStack(S);
	int m,n;
	int maze[100][100];






	    if(ShorteatPath(S))
        {
            while(!EmptyStack(S))
            {
                PostType e;
                Pop(S, e);
                cout<<"("<<e.xpos<<","<<e.ypos<<")"<<endl;
            }
            cout<<endl;
        }
        else
            cout<<"There is no feasible path."<<endl;
        //printf("%d",ShorteatPath(S));
    return 0;
}
