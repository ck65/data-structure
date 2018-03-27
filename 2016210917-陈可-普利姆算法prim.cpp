#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct
{
    char vexs[30];
    int numVex,numEdg;
    int arc[30][30];
}MGraph;

 typedef struct
 {
     char begin;
     char end;
     int weight;
 }Edge;

 int Locate(MGraph *G, char name)
 {
     int i;
     for(i=0;i<G->numVex;i++){
        if(name==G->vexs[i]) return i;
     }
     return -1;
 }



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
     G->numVex=m;
     G->numEdg=n;

     printf("Input the vexs:");
     for(int j=0;j< G->numVex;j++){
        cin>>vex;
        G->vexs[j]=vex;
     }
     printf("input the infomation of the edg(begin,end,weight):");
     for(i=0;i< G->numEdg;i++){
        //printf("%d",G->numVex);
        cin>>vex1>>vex2>>w;
        a=Locate(G,vex1);
        b=Locate(G,vex2);
        G->arc[a][b]=G->arc[b][a]=w;
     }

 }

 void prim(MGraph *G, int s)
 {
     int min,i,j,k,m,n,l;
     int index=0;
     char prim[30];
     int weight[30];

     prim[index++]=G->vexs[s];//将vex的值存入prim辅助数组中

     for(i=0;i<G->numVex;i++)
            weight[i]=G->arc[s][i];//开始节点与每个节点的边的权值
     weight[s]=0;//与自己的权值为0

     for(i=0; i<G->numVex; i++){
        if(s==i)
            continue;
        j=0;
        k=0;
        min=1001;
        for(j=0;j<G->numVex;j++){
            if(weight[j]&&weight[j]<min){//weight最小且不为0
                min=weight[j];
                k=j;
            }
        }
        for(int g=0;g<G->numVex;g++){//找到与该节点相连权值最小的节点
            if(G->arc[k][g]==weight[k])
                l=g;
        }
        printf("(%c,%c) %d\n",G->vexs[l],G->vexs[k],weight[k]);
        prim[index++]=G->vexs[k];
        weight[k]=0;
        for(j=0;j<G->numVex;j++){
            if(weight[j]&&G->arc[k][j]<weight[j]){
                weight[j]=G->arc[k][j];//更新权值数组
            }

        }
     }
}


int main()
{
    MGraph G;
    Create(&G);
    prim(&G,0);
}
