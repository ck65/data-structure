#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<string>
using namespace std;

typedef char **HuffmanCode;
typedef char TElemType;

typedef struct HTNode
{
    TElemType elem;
    int weight;
    int parent;
    int lchild, rchild;
}HTNode, *HuffmanTree;

void Select(HuffmanTree HT, int i, int &s1, int &s2){
    int j, k = 1;
    while(HT[k].parent != -1)
        k++;
    s1 = k;
    for(j = 1; j <= i; j++)
        if((HT[j].parent == -1) && (HT[j].weight < HT[s1].weight))
            s1 = j;
    k = 1;
    while(HT[k].parent != -1 || k == s1)
        k++;
    s2 = k;
    for(j = 1; j <= i; j++)
        if((HT[j].parent == -1) && (HT[j].weight < HT[s2].weight) && (j != s1))
            s2 = j;
}

void CreateHuffmanTree(HuffmanTree &HT, TElemType *c, int *w, int n)
{
    if(n <= 1)
        return;
    int m = 2 * n - 1;
    HT = new HTNode[m + 1];
    int i;
    for(i = 1; i <= n; i++)
    {
        HT[i].weight = w[i];
        HT[i].elem = c[i];
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }
    for(; i <= m; i++)
    {
        HT[i].weight = 0;
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }
    for(i = n + 1; i <= m; i++)
    {
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void encoding(HuffmanTree HT, HuffmanCode &HC, int n)
{
    HC = new char *[n + 1];
    char *temphc = new char[n];
    temphc[n - 1] = '\0';
    for(int i = 1; i <= n; i++)
    {
        int start = n - 1, tempi, p;
        for(tempi = i, p = HT[i].parent; p !=  -1; tempi = p, p = HT[p].parent)
        {
            if(HT[p].lchild == tempi)
            {
                temphc[--start] = '0';
            }
            else
            {
                temphc[--start] = '1';
            }
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &temphc[start]);
    }
    delete []temphc;
}

void printHuffmanCode(HuffmanTree HT, HuffmanCode HC, int n)
{
    for(int i = 1; i <= n; i++)
        cout<<HT[i].elem<<":"<<HC[i]<<endl;
    cout<<endl;
}

void decoding(HuffmanTree HT, string teststr, int n, char *result)
{
    int m = 2 * n - 1;
    int p = m;
    int j = 0;
    for(int i = 0; i < teststr.length(); i++)
    {
        if(teststr[i] == '0')
        {
            p = HT[p].lchild;
        }
        if(teststr[i] == '1')
        {
            p = HT[p].rchild;
        }
        if(p <= n)
        {
            result[j] = HT[p].elem;
            j++;
            p = m;
        }
    }
    result[j] = '\0';
}
int main()
{
    HuffmanTree HT;

    cout<<"Please input the number of Huffman code: "<<endl;
    int n;
    cin>>n;

    if(n > 1)
        cout<<"Please input "<<n<<" elements: "<<endl;
    else
        cout<<"Please input 1 element: "<<endl;

    TElemType c[1000];
    for(int i = 1; i <= n; i++)
        cin>>c[i];

    cout<<"Please input the weight of "<<n<<" elements: "<<endl;
    int w[1000];
    for(int d = 1; d <= n; d++)
        cin>>w[d];

    CreateHuffmanTree(HT, c, w, n);

    HuffmanCode HC;
    encoding(HT, HC, n);
    printHuffmanCode(HT, HC, n);

    string teststr;
    cout<<"Please input the string: "<<endl;
    cin>>teststr;
    char result[100];
    decoding(HT, teststr, n, result);
    cout<<"Result is: "<<result<<endl;
    return 0;
}
