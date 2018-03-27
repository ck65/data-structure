#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXEDGE 30
#define MAXVEX  30
#define INFINITY 65535

typedef struct
{
    char vexs[30];
    int arc[30][30];
    int numVertexes, numEdges;//������������
}MGraph;

typedef struct
{
    int begin;
    int end;
    int weight;
}Edge;   //�Ա߼�����Edge�ṹ�Ķ���


 int Locate(MGraph *G, char name)
 {
     int i;
     for(i=0;i<G->numVertexes;i++){
        if(name==G->vexs[i]) return i;
     }
     return -1;
 }


//����ͼ���ڽӾ���
void Create(MGraph *G)
 {
     char vex,vex1,vex2;
     int i,j,w,a,b,n,m,l;
     for(n=0;n<30;n++){
        for(int m=0;m<30;m++){
            if(n=m) G->arc[n][m]=0;
            else  G->arc[n][m]=G->arc[m][n]=1000;
        }
     }
     printf("Input the number of the vex and edg:\n");
     cin>>m>>n;
     cout<<endl;
     G->numVertexes=m;
     G->numEdges=n;

     printf("Input the vexs:");
     for(int j=0;j< G->numVertexes;j++){
        cin>>vex;
        G->vexs[j]=vex;
     }
     printf("input the infomation of the edg(begin,end,weight):");
     for(i=0;i< G->numEdges;i++){
        //printf("%d",G->numVertexes);
        cin>>vex1>>vex2>>w;
        a=Locate(G,vex1);
        b=Locate(G,vex2);
        G->arc[a][b]=G->arc[b][a]=w;
     }

 }

//����
void Swap(Edge *edges, int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

void Sort(Edge *edges, MGraph *G)
{
	for(int i = 0; i < G -> numEdges; i++)
	{
		for(int j = i + 1; j < G -> numEdges; j++)
		{
			if(edges[i].weight > edges[j].weight)
            {
                Swap(edges, i, j);
            }
		}
	}
}

//�ҵ����ڵ�
int Find(int *parent, int f) {
    while ( parent[f] > 0) {
        f = parent[f];
       // printf("f=%d %d\n",f,parent[f]);
    }
    return f;
}

// ������С������
void MiniSpanTree_Kruskal(MGraph G) {
    int i, j, n, m;
    int k = 0;
    int parent[MAXVEX]; //����Ѱ�Ҹ��ڵ������

    Edge edges[MAXEDGE]; //����߼�����,edge�ĽṹΪbegin,end,weight,��Ϊ����

    // ���������߼����鲢����(���ڽӾ���ĶԽ����ұߵĲ��ִ���߼�������)
    for ( i = 0; i < G.numVertexes-1; i++) {
        for (j = i + 1; j < G.numVertexes; j++) {
            if (G.arc[i][j] < INFINITY) {
                edges[k].begin = i+1; //��Ž�С�Ľ��Ϊ��
                edges[k].end = j+1;   //��Žϴ�Ľ��Ϊβ
                edges[k].weight = G.arc[i][j];
                k++;
            }
        }
    }

    //Ϊ�߼�����Edge����
    Sort(edges,&G);

    for (i = 0; i < G.numVertexes; i++)
        parent[i] = 0;

    printf("��С��������\n");
    for (i = 0; i < G.numEdges; i++) {
        n = Find(parent, edges[i].begin);//Ѱ�ұ�edge[i]�ġ��׽ڵ㡱������������
        //printf("n=%d\n",n);
        m = Find(parent, edges[i].end);//Ѱ�ұ�edge[i]�ġ�β�ڵ㡱������������
        //printf("m=%d\n",m);
        //����n��m���ȣ�˵���������㲻��һ������
        if (n != m) {
            parent[n] = m;
            printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int main(void)
{
    MGraph G;
    Create(&G);
    MiniSpanTree_Kruskal(G);

    return 0;
}
