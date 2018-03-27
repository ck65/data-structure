#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<string.h>

using namespace std;
#define MAX_VERTEX_NUM 30
typedef char InfoType;
typedef int Status;
typedef int Boolean;
typedef string VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
Boolean visited[MAX_VERTEX_NUM];

typedef struct ArcNode//��(�ڽӱ�)
{
    int adjvex;             //��ǰ��ָ��Ķ���
    int info;               //Ȩֵ
    struct ArcNode *nextarc;//��һ����ǰ����Ϊ���ȵĻ�
} ArcNode;

typedef struct VNode//��(�ڽӱ�)
{
    VertexType data;//�����
    ArcNode *firstarc;//�õ�ĵ�һ������
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct//ͼ(�ڽӱ�)
{
    AdjList vertices;//����ڽӱ�(����)
    int vexnum,arcnum;
    int kind;
} ALGraph;
typedef struct ArcCell
{
    int adj;
    InfoType *info;
} ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
    char vexs[MAX_VERTEX_NUM];//�����
    AdjMatrix arcs;             //�ڽӾ���
    int vexnum,arcnum;          //�����������
    GraphKind kind;
} MGraph;
void (*VisitFunc)(MGraph G,int v);
void (*VisitFunc_2)(ALGraph G,int v);

int LocateVex(MGraph G,char name)//��ȡ�����
{
    for(int i=0; i<G.vexnum; i++)
        if(name==G.vexs[i])return i;
    return -1;
}

int LocateVex_2(ALGraph G,string name)///��ȡ�����
{
    for(int i=0; i<G.vexnum; i++)
        if(name==G.vertices[i].data)return i;
    return -1;
}

int CreateUDG(MGraph &G)
{
    int IncInfo;
    printf("������Ȩ����ͼ�������������ܽ�������ܱ������Ƿ������Ϣ:\n");
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    printf("��Ϊ��1��n���������:\n");
    for(int i=0; i<G.vexnum; i++)cin>>G.vexs[i];
    for(int i=0; i<G.vexnum; i++)
        for(int j=0; j<G.vexnum; j++)G.arcs[i][j].adj=1000,G.arcs[i][j].info=NULL;
    char v1,v2;
    printf("������%d���໥���ӵ������:\n",G.arcnum);
    for(int k=0; k<G.arcnum; k++)
    {
        cin>>v1>>v2;
        int i=LocateVex(G,v1);
        int j=LocateVex(G,v2);
        G.arcs[i][j].adj=1;
        if(IncInfo)scanf("%s",G.arcs[i][j].info);
        G.arcs[j][i]=G.arcs[i][j];
    }
    return 1;
}
void ArcAdd_sort(ALGraph &G,int v1,int v2,int w)//�Ӵ�С˳�����ڽӱ�
{
    ArcNode *p,*h,*q;
    p=new ArcNode;
    p->adjvex=v2;
    p->info=w;
    p->nextarc=NULL;
    h=q=G.vertices[v1].firstarc;
    if(q==NULL)G.vertices[v2].firstarc=p;
    else
    {
        if(p->adjvex > q->adjvex)//�ڽӱ������ŴӴ�С����
        {
            p->nextarc=q;
            G.vertices[v2].firstarc=p;
        }
        else
        {
            while(G.vertices[v2].firstarc!=NULL&&q->nextarc!=NULL&&p->adjvex < q->adjvex)
            {
                h=q;
                q=q->nextarc;
            }
            if(q->nextarc==NULL&&p->adjvex < q->adjvex) q->nextarc=p;
            else
            {
                p->nextarc=q;
                h->nextarc=p;
            }
        }
    }
}

void ArcAdd(ALGraph &G,int v1,int v2,int w)//�ӱ�
{
    ArcNode *p,*q;
    p=new ArcNode;
    p->adjvex=v2;
    p->info=w;
    p->nextarc=NULL;
    q=G.vertices[v1].firstarc;
    if(q==NULL) G.vertices[v1].firstarc=p;//����һ������v2����Ļ���δ���ڣ��¼���ı���Ϊ��һ��������
    else//����˳������������
    {
        while(q->nextarc!=NULL) q=q->nextarc;
        q->nextarc=p;
    }
}

int CreateUDG_2(ALGraph &G)//�ڽӱ�(������Ȩ����ͼ)
{
    printf("������Ȩ����ͼ�������������ܽ�������ܱ���:\n");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    printf("��Ϊ��1��n���������:\n");
    for(int i=0; i<G.vexnum; i++)cin>>G.vertices[i].data,G.vertices[i].firstarc=NULL;
    string v1,v2;
    printf("������%d���໥�����������:\n",G.arcnum);
    for(int k=0; k<G.arcnum; k++)
    {
        cin>>v1>>v2;
        int i=LocateVex_2(G,v1);//��ȡ���
        int j=LocateVex_2(G,v2);
        ArcAdd(G,i,j,1);//�����
        ArcAdd(G,j,i,1);
    }
    return 1;
}

int FirstAdjVex(ALGraph G,int v)
{
    if(G.vertices[v].firstarc) return G.vertices[v].firstarc->adjvex;
    return -1;
}
int NextAdjVex(ALGraph G,int v,int w)
{
    ArcNode *p=G.vertices[v].firstarc;
    while(p->adjvex!=w&&p->nextarc!=NULL)p=p->nextarc;
    if(p->nextarc==NULL)return -1;
    return p->nextarc->adjvex;
}

void BFSTraverse(MGraph G,void(*Visit)(MGraph G,int v))//�ڽӾ���BFS
{
    for(int v=0; v<G.vexnum; v++)visited[v]=0;
    queue<int>Q;
    printf("������������������ʼ���:\n");
    char st;
    cin>>st;
    printf("�������������������:\n");
    int temp=LocateVex(G,st);
    Visit(G,temp);
    Q.push(temp);
    visited[temp]=1;
    while(!Q.empty())
    {
        int tmp=Q.front();
        Q.pop();
        for(int w=0; w<G.vexnum; w++)
        {
            if(!visited[w]&&G.arcs[tmp][w].adj!=1000)
            {
                visited[w]=1;
                Visit(G,w);
                Q.push(w);
            }
        }
    }
    for(int v=0; v<G.vexnum; v++)//ʣ����ͨ����
    {
        if(!visited[v])
        {
            visited[v]=1;
            Visit(G,v);
            Q.push(v);
            while(!Q.empty())
            {
                int tmp=Q.front();
                Q.pop();
                for(int w=0; w<G.vexnum; w++)
                {
                    if(!visited[w]&&G.arcs[tmp][w].adj!=1000)
                    {
                        visited[w]=1;
                        Visit(G,w);
                        Q.push(w);
                    }
                }
            }
        }
    }
    printf("\n");
}

void DFS(ALGraph G,int v)///�ڽӱ�DFS
{
    visited[v]=1;
    VisitFunc_2(G,v);
    for(int w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w))
        if(!visited[w])DFS(G,w);
}

void DFSTravers(ALGraph G,void (*Visit)(ALGraph G,int v))
{
    VisitFunc_2=Visit;
    printf("�������������������ʼ���:\n");
    for(int v=0; v<G.vexnum; v++)visited[v]=0;
    string st;
    cin>>st;
    int tmp=LocateVex_2(G,st);
    printf("�������������������:\n");
    DFS(G,tmp);
    for(int v=0; v<G.vexnum; v++)if(!visited[v])DFS(G,v);
    printf("\n");
}


void visit(MGraph G,int v)//�ڽӾ������
{
    cout<<G.vexs[v]<<' ';
}

void visit_2(ALGraph G,int v)//�ڽӱ����
{
    cout<<G.vertices[v].data<<' ';
}

int main()
{
    printf("1.�����ڽӾ��󣬲���BFS���\n2.�����ڽӱ�����DFS���");
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 1: MGraph G1;
                CreateUDG(G1);
                BFSTraverse(G1,visit);
                break;
        case 2: ALGraph G2;///�ڽӱ�
                CreateUDG_2(G2);
                DFSTravers(G2,visit_2);
                break;
}
    }



