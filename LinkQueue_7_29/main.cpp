#include <iostream>
#include "stdlib.h"
#include "stdio.h"
typedef  char  datatype;
#define Maxsize  10;
using namespace std;

typedef struct Qnode
{
    datatype data;
    Qnode*   next;
}Qnode;

typedef struct
{
    Qnode* pro;
    Qnode* rear;
}linkQuene;

typedef struct
{
    datatype *base;
    int pro;
    int rear;
}cycleQueue;

void iniLinkQuene(linkQuene *que)
{
    que->pro = que->rear = (Qnode*)malloc(sizeof(Qnode));
    if(!que) exit(0);
    que->pro->next = NULL;
}

void EnQuene(linkQuene *que,datatype elem)
{
    Qnode* m = (Qnode*)malloc(sizeof(Qnode));
    if(!m) exit(0);
    m->data = elem;
    m->next = NULL;
    que->rear->next = m;
    que->rear = m;

}

void delQuene(linkQuene *que,datatype *elem)
{
    Qnode* m ;//= (Qnode*)malloc(sizeof(Qnode));
    //if(!m) exit(0);
    m = que->pro->next;
    *elem  = m->data;
    que->pro->next = m->next;
    if(m == que->rear)
    {
        que->rear = que->pro;
    }
    free(m);
}

void distroyQuene(linkQuene * que)
{
    while(que->pro)
    {
        que->rear = que->pro->next;
        free(que->pro);
        que->pro = que->rear;
    }
}


void initcycleQuene(cycleQueue* cycque)
{
    /*cycque->base = (datatype*)malloc(Maxsize*sizeof(datatype));
    if(!cycque->base) exit(0);
    cycque->pro = cycque->rear = 0;*/
}

void EncycleQuene(cycleQueue *cycque,datatype data)
{
    /*if(((cycque->rear+1)%Maxsize) ==(cycque->pro))
        return;
    cycque->base[cycque->rear] = data;
    cycque->rear = (cycque->rear+1)%Maxsize;*/
}

void DecycleQuene(cycleQueue* cycque,datatype *data)
{
    if(cycque->pro == cycque->rear) return;
    *data = cycque->base[cycque->pro];
    cycque->pro = (cycque->pro +1)%Maxsize;
}

int main()
{
    datatype temp;
    linkQuene *que;
    iniLinkQuene(que);
    cout<<"input a string into a queue:";
    cin>>temp;
    while(temp!='@')
    {
        EnQuene(que,temp);
        cin>>temp;
    }
    cout<<"output the string:";
    while(que->pro != que->rear)
    {
        delQuene(que,&temp);
        cout<<temp;
    }
    cout<<endl;
    distroyQuene(que);

    return 0;
}
