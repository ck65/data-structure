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

typedef struct ArcNode//弧(邻接表)
{
    int adjvex;             //当前弧指向的顶点
    int info;               //权值
    struct ArcNode *nextarc;//下一条当前顶点为出度的弧
} ArcNode;

typedef struct VNode//点(邻接表)
{
    VertexType data;//结点名
    ArcNode *firstarc;//该点的第一条出边
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct//图(邻接表)
{
    AdjList vertices;//点的邻接表(数组)
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
    char vexs[MAX_VERTEX_NUM];//结点名
    AdjMatrix arcs;             //邻接矩阵
    int vexnum,arcnum;          //结点数，弧数
    GraphKind kind;
} MGraph;
void (*VisitFunc)(MGraph G,int v);
void (*VisitFunc_2)(ALGraph G,int v);

int LocateVex(MGraph G,char name)//获取结点标号
{
    for(int i=0; i<G.vexnum; i++)
        if(name==G.vexs[i])return i;
    return -1;
}

int LocateVex_2(ALGraph G,string name)///获取结点标号
{
    for(int i=0; i<G.vexnum; i++)
        if(name==G.vertices[i].data)return i;
    return -1;
}

int CreateUDG(MGraph &G)
{
    int IncInfo;
    printf("建立无权无向图，请依次输入总结点数、总边数、是否包含信息:\n");
    scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);
    printf("请为从1至n个结点命名:\n");
    for(int i=0; i<G.vexnum; i++)cin>>G.vexs[i];
    for(int i=0; i<G.vexnum; i++)
        for(int j=0; j<G.vexnum; j++)G.arcs[i][j].adj=1000,G.arcs[i][j].info=NULL;
    char v1,v2;
    printf("请输入%d组相互连接的两结点:\n",G.arcnum);
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
void ArcAdd_sort(ALGraph &G,int v1,int v2,int w)//从大到小顺序建立邻接表
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
        if(p->adjvex > q->adjvex)//邻接表按结点序号从大到小排列
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

void ArcAdd(ALGraph &G,int v1,int v2,int w)//加边
{
    ArcNode *p,*q;
    p=new ArcNode;
    p->adjvex=v2;
    p->info=w;
    p->nextarc=NULL;
    q=G.vertices[v1].firstarc;
    if(q==NULL) G.vertices[v1].firstarc=p;//若第一条依附v2顶点的弧还未存在，新加入的边作为第一条依附弧
    else//否则顺着链表向后查找
    {
        while(q->nextarc!=NULL) q=q->nextarc;
        q->nextarc=p;
    }
}

int CreateUDG_2(ALGraph &G)//邻接表(建立无权无向图)
{
    printf("建立无权无向图，请依次输入总结点数、总边数:\n");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    printf("请为从1至n个结点命名:\n");
    for(int i=0; i<G.vexnum; i++)cin>>G.vertices[i].data,G.vertices[i].firstarc=NULL;
    string v1,v2;
    printf("请输入%d组相互依附的两结点:\n",G.arcnum);
    for(int k=0; k<G.arcnum; k++)
    {
        cin>>v1>>v2;
        int i=LocateVex_2(G,v1);//获取标号
        int j=LocateVex_2(G,v2);
        ArcAdd(G,i,j,1);//无向边
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

void BFSTraverse(MGraph G,void(*Visit)(MGraph G,int v))//邻接矩阵BFS
{
    for(int v=0; v<G.vexnum; v++)visited[v]=0;
    queue<int>Q;
    printf("请输入广度优先搜索起始结点:\n");
    char st;
    cin>>st;
    printf("广度优先搜索遍历序列:\n");
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
    for(int v=0; v<G.vexnum; v++)//剩余连通分量
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

void DFS(ALGraph G,int v)///邻接表DFS
{
    visited[v]=1;
    VisitFunc_2(G,v);
    for(int w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w))
        if(!visited[w])DFS(G,w);
}

void DFSTravers(ALGraph G,void (*Visit)(ALGraph G,int v))
{
    VisitFunc_2=Visit;
    printf("请输入深度优先搜索起始结点:\n");
    for(int v=0; v<G.vexnum; v++)visited[v]=0;
    string st;
    cin>>st;
    int tmp=LocateVex_2(G,st);
    printf("深度优先搜索遍历序列:\n");
    DFS(G,tmp);
    for(int v=0; v<G.vexnum; v++)if(!visited[v])DFS(G,v);
    printf("\n");
}


void visit(MGraph G,int v)//邻接矩阵遍历
{
    cout<<G.vexs[v]<<' ';
}

void visit_2(ALGraph G,int v)//邻接表遍历
{
    cout<<G.vertices[v].data<<' ';
}

int main()
{
    printf("1.建立邻接矩阵，并以BFS输出\n2.建立邻接表，并以DFS输出");
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 1: MGraph G1;
                CreateUDG(G1);
                BFSTraverse(G1,visit);
                break;
        case 2: ALGraph G2;///邻接表
                CreateUDG_2(G2);
                DFSTravers(G2,visit_2);
                break;
}
    }



