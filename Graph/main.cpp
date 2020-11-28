#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#define MaxNode 20
typedef int datatype;
typedef double weighttype;
using namespace std;

typedef struct ArcNode
{
    int verdex;
    ArcNode *next;
    weighttype *weight;
}ArcNode;
typedef struct VNode
{
   datatype  data;
   ArcNode*  first_Arc;
}VNode;

VNode G[MaxNode];

void CreatGraph(int n,VNode G[])
{
    int dex;
    cout<<"input the information of the vertex:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>G[i].data;
        G[i].first_Arc = NULL;
    }
    ArcNode* temp;
    for(int i=0;i<n;i++)
    {
        cout <<"Creating the edges for the %"<<i<<"th vertex:"<<endl;
        cin>>dex;
        while(dex!=-1)
        {
            ArcNode *node = (ArcNode*)malloc(sizeof(ArcNode));
            node->verdex = dex;
            node->next = NULL;
            if(G[i].first_Arc == NULL)
            {
                G[i].first_Arc = node;
            }
            else{
                temp->next = node;
            }
            temp = node;
            cin>>dex;
        }

    }
}

int FirstAdj(VNode G[],int v)
{
    if(G[v].first_Arc == NULL) return -1;
        return G[v].data;
}

int NextAdj(VNode G[],int v,int visited[])
{
    ArcNode* temp;
    temp = G[v].first_Arc;
    while(temp)
    {
    if(visited[temp->verdex])temp=temp->next;
    else
    {
        return temp->verdex;
    }
    return -1;
    }

void DFS(VNode G[],int v,int visited[])
{
    int w;
    cout<<G[v].data;
    visited[v]=1;
    w = FirstAdj(G,v);
    while(w!=-1)
    {
       if(visited[w] == 0)
       {
           DFS(G,w,visited);
       }
       w=NextAdj(G,v,visited);
    }
}

void Travel_DFS(VNode G[],int visited[],int n)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            DFS(G,visited,i);
        }
    }
}

int main()
{

    int visited[MaxNode];
    VNode G[5];
    CreatGraph(5,G);
    Travel_DFS(G,visited,5);
    cout << "Hello world!" << endl;
    return 0;
}
