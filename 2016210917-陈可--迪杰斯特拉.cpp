#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<string>
#include<vector>
using namespace std;

#define MAXEDGE 30
#define MAXVEX 30
#define INFINITY 9999999

typedef struct
{
	char vexs[MAXVEX];
	int  arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

 int Locate(MGraph *G, char name)
 {
     int i;
     for(i=0;i<G->numVertexes;i++){
        if(name==G->vexs[i]) return i;
     }
     return -1;
 }

void InitMGraph(MGraph *G)
{
	int m, n,g,i;
	char vex;
    cout<<"Please input vertex number and edge number: "<<endl;
    cin>>m>>n;
    cout<<endl;
	G -> numVertexes = m;
	G -> numEdges = n;

    printf("Input the vexs:");
	for( i = 0; i < G -> numVertexes; i++)
	{
	    cin>>vex;
	    g=Locate(G,vex);
		G -> vexs[i] = i;
	}

	for( i = 0; i < G -> numVertexes; i++)
	{
		for(int j = 0; j < G -> numVertexes; j++)
		{
			if (i == j)
				G -> arc[i][j] = 0;
			else
				G -> arc[i][j] = G -> arc[j][i] = INFINITY;
		}
	}
}

void CreateMGraph(MGraph *G)
{
    cout<<"Please input edges information : (begin, end, weight)"<<endl;
	for(int k = 0; k < G -> numEdges; k++)
    {
        int a, b;
        int  c;
        cin>>a>>b>>c;
        G -> arc[a][b] = c;
    }
    cout<<endl;

}

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
	int w, k, min,v;
	int final[MAXVEX];
	for(v = 0; v < G.numVertexes; v++)
	{
		final[v] = 0;
		(*D)[v] = G.arc[v0][v];
		(*P)[v] = 0;
	}

	(*D)[v0] = 0;
	final[v0] = 1;
	for(v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;
		for( w = 0; w < G.numVertexes; w++)
		{
			if((!final[w]) && ((*D)[w] < min))
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for( w = 0; w < G.numVertexes; w++)
		{
			if((!final[w]) && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}

int main()
{
	MGraph G;
	InitMGraph(&G);
	CreateMGraph(&G);
	Patharc P;
	ShortPathTable D;

	cout<<"起始节点为： "<<endl;
	int v;
	cin>>v;
	cout<<endl;

	ShortestPath_Dijkstra(G, v, &P, &D);

	stack<int> s;
	int tempi;
	cout<<"最短路径从 v"<<v<<" 到其他节点: "<<endl;
	for(int i = 0; i < G.numVertexes; i++)
	{
		if(v == i)
        {
            cout<<"v"<<v<<" to v"<<i<<" : NULL"<<endl;
            continue;
        }
        else if(D[i]>1000)
         {
            cout<<"v"<<v<<" ——》 v"<<i<<" : NULL"<<endl;
            continue;
        }
        else
            cout<<"v"<<v<<" ——》 v"<<i<<" : ";
		tempi = i;
		while(P[tempi] != 0)
		{
			s.push(P[tempi]);
			tempi = P[tempi];
		}
		while(!s.empty())
		{
		    int p = s.top();
		    cout<<p<<" ";
		    s.pop();
		}
		cout<<i<<"  "<<"路径长度为： "<<D[i]<<endl;
	}
	return 0;
}
