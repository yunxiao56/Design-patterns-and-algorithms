#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}Lnode;


Lnode* GreateLinklist(int n)//建立一个长度为n的链表
{
    Lnode *p;
    Lnode *List = NULL;
    Lnode *r;
    int x;
    for(int i=0;i<n;i++)
    {
        cout<<"input list data：";
        cin>>x;
        p = (Lnode *)malloc(sizeof(Lnode));
        p->data = x;
        p->next = NULL;
        if(!List)
        {
            List = p;
        }
        else
        {
            r->next = p;
        }
        r = p;

    }
    return List;
}

void insertnode(Lnode** List,Lnode* m,int e)
{
    Lnode *p ;
    p= (Lnode *)malloc(sizeof(Lnode));
    p->data = e;
    if(!*List)
    {
        *List=p;
        p->next=NULL;
    }
    else{
        p->next = m->next;
        m->next = p;
    }
}

void delLinkList(Lnode **List,Lnode*q)
{
    Lnode *r;
    if(q==*List)
    {
        *List = q->next;
        free(q);
    }
    else
    {
        for(r=*List;r->next!=q;r=r->next)
        if(r->next!=NULL)
        {
            r->next = q->next;
            free(q);

        }
    }


}
void print(Lnode*List)
{
    Lnode *p;
    Lnode *r;
    p=List;
    cout<<"output list data";
    while(p)
    {
        r=p->next;
        cout<<p->data<<endl;
        p=r;

    }

}

void distroyLinklist(Lnode**List)
{
    Lnode* p;
    Lnode* r;
    p=*List;
    while(p)
    {
        r=p->next;
        free(p);
        p=r;
    }
    *List=NULL;
}


int main()
{
   int e;
   Lnode *l;
   Lnode *q;
   q=l=GreateLinklist(1);
   cin>>e;
   while(e)
   {
       insertnode(&l,q,e);
       q=q->next;
       cin>>e;
   }
   q=l;

    cout << "output the list data:" << endl;
    while(q)
    {
        cout<<q->data<<endl;
        q=q->next;
    }
    cout<<endl;
    q=l;
    for(int i=0;i<6;i++)
    {
        if(q==NULL)
        {
            cout<<"the length of the list is smaller than 6."<<endl;
            return 0;
        }
        q=q->next;
    }
    delLinkList(&l,q);
    q=l;
    while(q)
    {
        cout<<q->data<<" ";
        q=q->next;
    }
    cout<<endl;
    distroyLinklist(&l);
    return 0;
}
